#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
   두 코드 사이의 다른것의 개수가 1인 것만 뽑아서 tree를 구성
     -> 두 코드 비교할 때, 다른것 개수가 2개 이상이면 바로 종료

   출발 - a 도착 - b로 잡아서 BFS로 경로 탐색 (trace 배열로 경로 추적)
*/

int n, k, a, b;
int trace[1001];
bool isVisit[1001];
vector<string> codes(1001);
vector<int> graph[1001];

bool hammingCode(string s1, string s2) {
	int cnt = 0;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) cnt++;
		if (cnt >= 2) return false;
	}
	if (cnt == 0) return false;
	return true;
}

void traceBack(int num) {
	if (trace[num] == -1) {
		cout << num << " ";
		return;
	}
	traceBack(trace[num]);
	cout << num << " ";
}

bool bfs() {
	queue<int> q;
	q.push(a);
	isVisit[a] = true;
	trace[a] = -1;
	while (!q.empty()) {
		int num = q.front();
		q.pop();

		if (num == b) {
			traceBack(num);
			cout << "\n";
			return true;
		}
		for (int i = 0; i < graph[num].size(); i++) {
			int next = graph[num][i];
			if (isVisit[next]) continue;
			q.push(next);
			trace[next] = num;
			isVisit[next] = true;
		}
	}
	return false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> codes[i];
	}
	cin >> a >> b;

	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (hammingCode(codes[i], codes[j])) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	if (!bfs()) cout << -1 << "\n";

	return 0;
}
