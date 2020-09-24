#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n, m;
long long dist[501];

vector<pair<pair<int, int>, int>> bus;

bool bellman(int st) {
	dist[st] = 0;
	bool ck = false;

	for (int i = 1;i <= n; i++) {
		for (int j = 0; j < bus.size(); j++) {
			int from = bus[j].first.first;
			int to = bus[j].first.second;
			int cost = bus[j].second;
			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
				if(i==n) ck = true;
			}
		}
	}
	return ck;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) dist[i] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		bus.push_back({ {a, b}, c });
	}

	bool isCycle = bellman(1);
	if (isCycle) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) cout << -1 << "\n";
			else cout << dist[i] << "\n";
		}
	}

	return 0;
}
