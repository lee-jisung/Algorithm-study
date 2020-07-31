#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>

#define INF 1e9

using namespace std;

/*  
   x원을 기준으로 x원 이하일 때 가중치를 0, x원 보다 크면 가중치를 1로 두고
   dijkstra를 진행 -> dist[n]를 갔을 때 k보다 적은 수의 선을 이용햇다면 x원이하로 가는 것 성공
   아니라면 x원 이상으로 탐색

   ==> x원을 binary_search로 값 갱신 해서 찾기
*/

int n, p, k, result;
int st, ed;
int dist[1001];
vector<pair<int, int>> graph[1001];

void init() {
	for (int i = 0; i < 1001;i++)
		dist[i] = INF;
}

bool dijkstra(int x) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, 1 });
	init();
	dist[1] = 0;

	while (!pq.empty()) {
		int cur = pq.top().second;
		int d = pq.top().first;
		pq.pop();
		if (dist[cur] < d) continue;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDist = d + (graph[cur][i].second > x);
			if (dist[next] <= nextDist) continue;
			pq.push({ nextDist, next });
			dist[next] = nextDist;
		}
	}
	return dist[n] <= k;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> k;
	for (int i = 0; i < p; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	st = 0; ed = INF;
	result = -1;
	while (st <= ed) {
		int mid = (st + ed) / 2;
		if (dijkstra(mid)) {
			result = mid;
			ed = mid - 1;
		}
		else {
			st = mid + 1;
		}
	}

	cout << result << "\n";
	
	return 0;
}
