#include <iostream>
#include <queue>

using namespace std;

/*
   k번째 최단거리 -> 각 도시별로 탐색하는 경로를 priority_queue에 저장 (maxHeap) 
   저장되는 경로가 K개가 되면 맨 위가 k번째 최단경로임을 보장
   
   heap 크기가 k개 이하면 그냥 push 후 탐색

   heap 크기가 k개가 쌓여있고, maxHeap의 top이 현재 탐색하는 경로보다 크면 교체 후 탐색

*/

struct node {
	int no;
	int dist;
};

bool operator<(node a, node b) {
	return a.dist > b.dist;
}

int n, m, k;
vector<node> graph[1001];
priority_queue<int> city[1001];

void dijkstra() {

	priority_queue<node> pq;
	pq.push({ 1, 0 });
	city[1].push(0);

	while (!pq.empty()) {

		node cur = pq.top();
		pq.pop();

		for (int i = 0; i < graph[cur.no].size(); i++) {
			int nxt = graph[cur.no][i].no;
			int nxtDist = graph[cur.no][i].dist + cur.dist;

			if (city[nxt].size() < k) {
				city[nxt].push({ nxtDist });
				pq.push({ nxt, nxtDist });
			}
			else if (city[nxt].top() > nxtDist) {
				city[nxt].pop();
				city[nxt].push(nxtDist);
				pq.push({ nxt, nxtDist });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	dijkstra();

	for (int i = 1; i <= n; i++) {
		if (city[i].size() != k) cout << -1 << "\n";
		else cout << city[i].top() << "\n";
	}

	return 0;
}
