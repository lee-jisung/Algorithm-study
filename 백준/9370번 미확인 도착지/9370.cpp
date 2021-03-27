#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 1e9

using namespace std;

/*
   dijkstra로 출발에서 모든 다른 경로로 가는 최단 경로 찾기 
   trace배열을 이용해서 최단 경로 추적

   후보지들에 대해서 trace배열을 이용해 출발지로 경로를 역추적하면서, g,h를 거치는 경우만 추려냄
    (여기서 방문처리를 해야 메모리 초과 x)
*/

struct node {
	int no, dist;
};

bool operator<(node a, node b) {
	return a.dist > b.dist;
}

int T;
int n, m, t, s, g, h;
int dist[2001];
bool isVisit[2001];
vector<node> city[2001], trace[2001];
vector<int> candidate, result;;

void init() {
	for (int i = 0; i < 2001; i++) {
		city[i].clear();
		trace[i].clear();
		dist[i] = INF;
	}
	candidate.clear();
	result.clear();
}

void input() {
	cin >> n >> m >> t;
	cin >> s >> g >> h;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		city[a].push_back({ b, d });
		city[b].push_back({ a, d });
	}
	candidate.resize(t);
	for (int i = 0; i < t; i++)
		cin >> candidate[i];
}

void dijkstra() {
	priority_queue<node> pq;
	pq.push({ s, 0 });
	dist[s] = 0;

	while (!pq.empty()) {

		node cur = pq.top();
		pq.pop();

		if (dist[cur.no] < cur.dist) continue;

		for (int i = 0; i < city[cur.no].size(); i++) {
			int nextNo = city[cur.no][i].no;
			int nextDist = city[cur.no][i].dist + cur.dist;

			if (dist[nextNo] > nextDist) {
				dist[nextNo] = nextDist;
				pq.push({ nextNo, nextDist });

				trace[nextNo].clear();
				trace[nextNo].push_back({ cur.no, nextDist });
			}
			else if (dist[nextNo] == nextDist) {
				trace[nextNo].push_back({ cur.no, nextDist });
			}
		}
	}
}

bool findDest(int no) {

	memset(isVisit, false, sizeof(isVisit));
	bool isThrough = false;
	queue<int> q;
	q.push(no);

	while (!q.empty()) {
		
		int nextNo = q.front();
		q.pop();

		if (isVisit[nextNo]) continue; // 방문처리 안해주면 메모리 초과
		isVisit[nextNo] = true;

		for (int i = 0; i < trace[nextNo].size(); i++) {
			int prevNo = trace[nextNo][i].no;
			if ((prevNo == g && nextNo == h) || (prevNo == h && nextNo == g)) isThrough = true;
			q.push(prevNo);
		}
	}
	return isThrough;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {

		init();
		input();

		dijkstra();

		for (int i = 0; i < candidate.size(); i++) {

			if (findDest(candidate[i])) {
				result.push_back(candidate[i]);
			}
		}

		sort(result.begin(), result.end());
		
		for (int a : result) {
			cout << a << " ";
		}
		cout << "\n";
	}

	return 0;
}
