#include <iostream>
#include <queue>
#include <vector>

#define INF 1e18

using namespace std;

/*
*  dijkstra + DP
*  도로를 포장하는 개수별로 dist[][] 2차원 배열 채우기
*  
*  long long 타입으로 선언, INF값이 1e9일 때 틀리고, 1e18로 해야 정답 나옴
*/
 
struct node {
	int no;
	long long delay;
	int kCnt;
};

bool operator<(node a, node b) {
	return a.delay > b.delay;
}

int N, M, K;
long long dist[10001][21];
vector<pair<int, int>> city[10001];

void dijkstra() {

	priority_queue<node> pq;
	pq.push({ 1, 0, 0 });
	dist[1][0] = 0;

	while (!pq.empty()) {

		node cur = pq.top();
		pq.pop();

		if (dist[cur.no][cur.kCnt] < cur.delay) continue;

		for (int i = 0; i < city[cur.no].size(); i++) {
			int nextNo = city[cur.no][i].first;
			long long nextDelay = city[cur.no][i].second + cur.delay;

			if (dist[nextNo][cur.kCnt] > nextDelay) {
				dist[nextNo][cur.kCnt] = nextDelay;
				pq.push({ nextNo, nextDelay, cur.kCnt });
			}
			if (cur.kCnt < K && dist[nextNo][cur.kCnt + 1] > cur.delay) {
				dist[nextNo][cur.kCnt + 1] = cur.delay;
				pq.push({ nextNo, cur.delay, cur.kCnt + 1 });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int a, b, d; cin >> a >> b >> d;
		city[a].push_back({ b, d });
		city[b].push_back({ a, d });
	}
	
	for (int i = 1; i <= N; i++) 
		for (int j = 0; j <= K; j++)
			dist[i][j] = INF;

	dijkstra();
	long long result = INF;
	for (int i = 0; i <= K; i++) {
		result = min(result, dist[N][i]);
	}
	cout << result << "\n";

	return 0;
}
