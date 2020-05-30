#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, result;
int population[11], section[11];
bool sel[11], isVisit[11];

vector<int> graph[11];
vector<int> sec[2];

// 각 연결구역에서 모든 구역이 방문되었다면 
// 2 구역 모두 서로 연결되어있는 구조
bool isLink() {
	for (int i = 1; i <= n; i++)
		if (!isVisit[i]) return false;
	return true;
}

// 각 구역으로 나눠진 곳에서 다른 구역으로 방문할 수 있는지 dfs로 확인
// 연결된 부분이 같은 구역이어야 방문 가능
void visit(int no) {

	isVisit[no] = true;
	for (int i = 0; i < graph[no].size(); i++) {
		int next = graph[no][i];
		if (!isVisit[next] && section[no] == section[next])
			visit(next);
	}
}

void dfs(int no, int cnt) {
	if (no == cnt) {
		sec[0].clear();
		sec[1].clear();
		for (int i = 1; i <= n; i++) {
			if (section[i]) sec[0].push_back(i);
			else sec[1].push_back(i);
		}

		memset(isVisit, false, sizeof(isVisit));
		for (int i = 0; i <= 1; i++)
			visit(sec[i][0]);
		
		// 1, 2 구역이 둘다 연결된 지역이라면 인구수의 차이 구함
		if (isLink()) {
			int sum1 = 0, sum2 = 0;
			for (int i = 1; i <= n; i++) {
				if (section[i]) sum1 += population[i];
				else sum2 += population[i];
			}
			result = min(result, abs(sum1 - sum2));
		}
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!sel[i]) {
			sel[i] = true;
			section[i] = 1;
			dfs(no + 1, cnt);
			sel[i] = false;
			section[i] = 0;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> population[i];

	for (int i = 1; i <= n; i++) {
		int len; cin >> len;
		for (int j = 0; j < len; j++) {
			int temp; cin >> temp;
			graph[i].push_back(temp);
		}
	}

	result = INF;
	for (int i = 1; i <=n / 2; i++) {
		dfs(0, i);
	}
	if (result == INF) cout << -1 << "\n";
	else cout << result << "\n";

	return 0;
}
