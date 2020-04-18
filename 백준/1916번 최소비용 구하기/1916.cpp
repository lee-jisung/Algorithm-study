#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1001
#define INF 987654321

using namespace std;

int n, m, st, dt;
int dist[SIZE];

vector<pair<int, int> > graph[SIZE];

void dijkstra(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {

		int cur = pq.top().second;
		int distance = pq.top().first;
		pq.pop();

		if (dist[cur] < distance) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].second;
			int nextDistance = graph[cur][i].first + distance;

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

	for (int i = 0;i < SIZE; i++)
		dist[i] = INF;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ w, v });
	}

	cin >> st >> dt;

	dijkstra(st);

	cout << dist[dt] << "\n";

	return 0;
}
