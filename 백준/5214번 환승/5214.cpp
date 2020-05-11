#include <iostream>
#include <queue>
#include <vector>

#define SIZE 100001

using namespace std;

/*
   graph[a].push_back(b), graph[b].push_back(a)의 식으로 모두 연결하면 정점당 1000^3개씩 연결되서 메모리 초과

   N이 100000까지니까 100001부터 가상의 역을 만들어 하이퍼 튜브를 저장
   그래서 graph[100000]까지의 각 정점들이 graph[100001] ~ graph[101001] 까지의 하이퍼 튜브에 연결이 되어 있고
   그 하이퍼 튜브에서 연결된 정점들로 방문을 하는것

   --> 메모리 초과 방지

*/

int n, k, m, cnt;
bool isVisit[SIZE + 2000];
vector<int> graph[SIZE + 2000];

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	isVisit[1] = true;

	while (!q.empty()) {
		int idx = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (idx == n) {
			cnt = depth;
			return;
		}

		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i];
			if (!isVisit[next]) {
				if (next > SIZE)
					q.push({ next, depth });
				else
					q.push({ next, depth + 1 });
				isVisit[next] = true;
			}
		}
	}
}

int main(void) {

	cin >> n >> k >> m;
	
	/*for (int i = 0; i < m; i++) { // 시간초과
		
		vector<int> a(k);
		for (int j = 0; j < k; j++)
			cin >> a[j];

		for(int j=0;j <k-1; j++)
			for (int w = j + 1; w < k; w++) {
				graph[a[j]].push_back(a[w]);
				graph[a[w]].push_back(a[j]);
			}
	}*/

	for (int i = 1; i <= m; i++) {

		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			graph[SIZE + i].push_back(a);
			graph[a].push_back(SIZE + i);
		}
	}

	cnt = -1;
	bfs();
	cout << cnt << "\n";
	return 0;
}
