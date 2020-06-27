#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1e6

using namespace std;

/*

   1, v1, v2에서 시작해서 다른 모든 점으로 가는 최단 경로를 dist[3][n]에 저장

   dijkstra 
   1 -> v1 -> v2 -> n 
   1 -> v2 -> v1 -> n 
   두가지의 경우를 비교해서 경로의 합이 더 적은 것을 선택
   (경로가 없을 경우 INF값 보다 커지므로 -1 출력)

*/

int n, e, result, v1, v2;
int dist[3][801];
bool isVisit[801];
vector<pair<int, int>> graph[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int no, int start) {
	dist[no][start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {

		int cur = pq.top().first;
		int dt = pq.top().second;
		pq.pop();

		if (dist[no][cur] < dt) continue;

		for (int i = 0; i < graph[cur].size(); i++) {

			int next = graph[cur][i].first;
			int nextDist = dt + graph[cur][i].second;
			if (dist[no][next] > nextDist) {
				dist[no][next] = nextDist;
				pq.push({ next, nextDist });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;
	for (int i = 0; i < e;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> v1 >> v2;
	
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <=n; j++)
			dist[i][j] = INF;

	dijkstra(0, 1); 
	dijkstra(1, v1);
	dijkstra(2, v2);

	int len1 = dist[0][v1] + dist[1][v2] + dist[2][n];

	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;

	dijkstra(0, 1);
	dijkstra(1, v2);
	dijkstra(2, v1);

	int len2 = dist[0][v2] + dist[1][v1] + dist[2][n];

	result = min(len1, len2);

	if (result >= INF) cout << -1 << "\n";
	else cout << result << "\n";

	return 0;
}
