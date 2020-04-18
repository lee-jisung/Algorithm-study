#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 20001
#define INF 1987654321

using namespace std;

int v, e, k;
int dist[SIZE];

vector<pair<int, int> > graph[SIZE];

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int > > > pq;
	pq.push({ 0, start });
	while (!pq.empty()) {

		int cur = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		if (dist[cur] < distance) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].second;
			int nextDistance = distance + graph[cur][i].first;
			if (dist[next] > nextDistance) {
				dist[next] = nextDistance;
				pq.push({ nextDistance, next });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> k;
	for (int i = 1; i <= v; i++)
		dist[i] = INF;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ w, v });
	}

	dijkstra(k);
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

	return 0;
}
