#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <tuple>

#define INF 1e9
using namespace std;

/*
   처음엔 MST로 풀려고 생각했으나, 조건 2가 MST와 위배됨
    => 1번 pc가 다른 pc와 통신할 때 걸리는 최소시간이 원래 최소시간보다 커지면 안된다는 것
	ex) 1 - 2 (3), 2 - 3 (3)
	    1 - 3 (5)
	의 연결과 가중치라고 생각했을 때, MST를 적용하면 시간이 적은 순으로 정렬하여 간선을 연결하기 때문에
	1-2-3의 순으로 연결되어 1 -> 3 까지 가는 데에 6이라는 비용이 든다
	하지만 원래 1 -> 3 까지 걸리는 비용은 5였기 때문에 MST를 적용할 수 없음

	따라서 dijkstra를 통해 1번 pc에서 다른 모든 pc로 가는 최단 거리를 선택하고,
	간선을 선택할 때 마다 다음 정점에서 새로운 간선을 선택했을 경우 다음 정점의 부모 노드로 현재 정점을 넣어
	갱신해준다

	 - parent[next] = cur;
	그리고 마지막으로 출력해줌
*/

typedef pair<int, int> PAIR;
typedef tuple<int, int, int> TUPLE;

int n, m;
int dist[1001], parent[1001];
vector<PAIR> graph[1001];

void dijkstra() {
	priority_queue<PAIR, vector<PAIR>, greater<PAIR>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (dist[cur] < d) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int nxt = graph[cur][i].first;
			int nxtDist = graph[cur][i].second + d;
			if (dist[nxt] > nxtDist) {
				dist[nxt] = nxtDist;
				parent[nxt] = cur;
				pq.push({ nxtDist, nxt });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	dijkstra();
	cout << n - 1 << "\n";
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << " " << i << "\n";
	}
	return 0;
}
