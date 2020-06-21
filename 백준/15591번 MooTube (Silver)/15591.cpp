#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N, Q;
bool isVisit[5001];
vector<pair<int, int>> graph[5001];

int bfs(int k, int v) {
	int cnt = 0;
	memset(isVisit, false, sizeof(isVisit));
	queue<int> q;
	q.push(v);
	isVisit[v] = true;

	while (!q.empty()) {

		int ver = q.front();
		q.pop();

		for (int i = 0; i < graph[ver].size(); i++) {
			int next = graph[ver][i].first;
			int usado = graph[ver][i].second;
			if (!isVisit[next] && usado >= k) {
				cnt++;
				isVisit[next] = true;
				q.push(next);
			}
		}
	}
	return cnt;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N  >> Q;
	for (int i = 0; i < N-1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		graph[p].push_back({ q, r });
		graph[q].push_back({ p, r });
	}
	for (int i = 0; i < Q; i++) {
		int k, v;
		cin >> k >> v;
		cout << bfs(k, v) << "\n";
	}

	return 0;
}
