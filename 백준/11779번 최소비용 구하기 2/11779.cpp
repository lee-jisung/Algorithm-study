#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int n, m, start, goal;
int dist[1001], trace[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> graph[1001];
vector<int> load;

void dijk() {
	trace[start] = -1;
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty()) {

		int cur = pq.top().first;
		int dt = pq.top().second;
		pq.pop();

		if (dist[cur] < dt) continue;
		
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDist = dt + graph[cur][i].second;
			if (dist[next] > nextDist) {
				dist[next] = nextDist;
				pq.push({ next, nextDist });
				trace[next] = cur;
			}
		}
	}
}

void print(int no) {
	if (no == -1) return;
	print(trace[no]);
	load.push_back(no);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	cin >> start >> goal;
	
	for (int i = 0; i <= n; i++)
		dist[i] = INF;

	dijk();
	print(goal);

	cout << dist[goal] << "\n" << load.size() << "\n";
	for (int i = 0; i < load.size(); i++)
		cout << load[i] << " ";
	return 0;
}

