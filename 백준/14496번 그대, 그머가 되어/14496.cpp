#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 1e9

/*
   Disjkstra 써봄
   각 경로로 가는 최단 거리 구하기
   양방향 연결, 거리는 무조건 1로 생각
*/

using namespace std;

int a, b, n, m;
int dist[1001], adj[1001][1001];
vector<int> graph[1001];

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {

		int dt = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < dt) continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int nxt = graph[cur][i];
			int nxtDist = dt + adj[cur][nxt];
			if (dist[nxt] > nxtDist) {
				dist[nxt] = nxtDist;
				pq.push({ nxtDist, nxt });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> n >> m;
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2; cin >> tmp1 >> tmp2;
		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
		adj[tmp1][tmp2] = adj[tmp2][tmp1] = 1;
	}

	for (int i = 1; i <= n; i++) dist[i] = INF;

	dijkstra(a);

	if (dist[b] == INF) cout << -1 << "\n";
	else cout << dist[b] << "\n";


	return 0;
}
