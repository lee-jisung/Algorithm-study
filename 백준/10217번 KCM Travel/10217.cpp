#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>

#define INF 1e9
using namespace std;

/*

  dist[i][j] => 1번에서 i번까지 가는데에 j비용을 써서 도착하는 소요 시간
  현재까지 온 비용 + 다음 도시로 갈 비용 > 지원비용 => 탐색 x
  dist[i][j] < 현재까지 온 시간 + 다음 도시 시간 => 탐색 x

  우선순위 큐를 사용하기 때문에 n번 도시에 온 순간 바로 소요 시간을 return (최단 소요 시간이기 때문)

*/

typedef pair<int, int> PAIR;
typedef tuple<int, int, int> TUPLE;

int tc;
int n, m, k, result;
int dist[101][10001];
vector<TUPLE> graph[101];

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			dist[i][j] = INF;
		graph[i].clear();
	}
}

int dijkstra() {
	priority_queue<TUPLE, vector<TUPLE>, greater<TUPLE>> pq;
	pq.push({ 0, 1, 0 }); // time, city idx, cost
	dist[1][0] = 0;

	while (!pq.empty()) {

		auto cur = pq.top();
		pq.pop();
		int time = get<0>(cur);
		int city = get<1>(cur);
		int cost = get<2>(cur);

		if (city == n)
			return time;

		if (dist[city][cost] < time) continue;
		for (auto nxt : graph[city]) {
			int nCity = get<0>(nxt);
			int nCost = get<1>(nxt);
			int nTime = get<2>(nxt);
			if (nCost + cost > m) continue;
			if (dist[nCity][nCost + cost] > nTime + time) {
				dist[nCity][nCost + cost] = nTime + time;
				pq.push({ nTime + time, nCity, nCost + cost });
			}
		}
	}
	return -1;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;
		init();
		for (int i = 0;i < k;i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			graph[u].push_back({ v, c, d });
		}
		result = dijkstra();
		if (result == -1) cout << "Poor KCM\n";
		else cout << result << "\n";
	}


	return 0;
}
