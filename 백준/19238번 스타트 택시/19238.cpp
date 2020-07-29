#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;
/*
   1. 특정 위치로 이동- > 최단 경로로 이동
   2. 승객을 태워 목적지로 이동 M번 반복

   3. 현재 위치에서 최단 거리의 승객을 선택
	3.1 최단 거리의 승객이 여러명 -> 행, 열 번호가 가장 작은 승객을 선택
	3.2 승객과 택시가 같은 위치 -> 최단 거리는 0
	3.3 연료 소모량 - 한칸 당 1
	3.4 승객을 태워 목적지에 도착 -> 해당 승객을 이동시킨 연료 소모량 x 2만큼 충전
	3.5 이동 도중 연료가 0이면 실패, 해당 날의 업무는 종료 -> 목적지에 도착 시 0일땐 고려 x
*/

struct INFO {
	int r, c;
	int dist;
};

int n, m, gas;
int board[21][21];
bool isVisit[21][21];
int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

pair<int, int> taxi;
map<pair<int, int>, pair<int, int>> pToD;
map<int, string> test;

void init() {
	for (int i = 1;i <= n; i++)
		for (int j = 1; j <= n; j++)
			isVisit[i][j] = false;
}

bool cmp(INFO a, INFO b) {
	if (a.dist == b.dist) {
		if (a.r == b.r)
			return a.c < b.c;
		return a.r < b.r;
	}
	return a.dist < b.dist;
}

// 현재 taxi 위치에서 찾을 수 있는 승객들을 전부 찾아 vector에 push 후 vector return
vector<INFO> findPassenger() {
	init();
	vector<INFO> v;
	queue<INFO> q;
	q.push({ taxi.first, taxi.second, 0 });
	isVisit[taxi.first][taxi.second] = true;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int dist = q.front().dist;
		q.pop();

		if (pToD.count({ r, c }) && pToD[{r, c}].first != -1) {
			v.push_back({ r, c, dist});
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 1 || nc < 1 || nr> n || nc > n) continue;
			if (isVisit[nr][nc] || board[nr][nc]) continue;
			q.push({ nr, nc, dist + 1 });
			isVisit[nr][nc] = true;
		}
	}
	return v;
}

// 현재 승객 위치에서 도착지점을 찾음
// 연료량이 도착지 거리보다 적거나 도착지를 찾지 못하면 false return
// 도착지점을 찾으면 gas + dist를 해주고 택시 위치를 도착지점으로 update, 승객 처리 표시
bool findDest(INFO next) {
	init();
	queue<INFO> q;
	q.push({ next.r, next.c, 0 });
	isVisit[next.r][next.c] = true;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int dist = q.front().dist;
		q.pop();

		if (pToD[{next.r, next.c}].first == r && pToD[{next.r, next.c}].second == c) {
			if (gas < dist) return false;
			gas += dist;
			taxi = { r, c };
			pToD[{next.r, next.c}] = { -1, -1 };
			m--;
			return true;
		}
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
			if (board[nr][nc] || isVisit[nr][nc]) continue;
			q.push({ nr, nc, dist + 1 });
			isVisit[nr][nc] = true;
		}
	}
	return false;
}

void endTaxi() {
	cout << "-1\n";
	exit(0);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> gas;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}

	cin >> taxi.first >> taxi.second;
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		pToD[{a, b}] = { c, d };
	}

	while (1) {

		vector<INFO> v = findPassenger();
		if (v.empty()) endTaxi(); // 승객이 남아있으나 태우지 못하는 경우 -1

		sort(v.begin(), v.end(), cmp); // 거리, 행, 열 순으로 정렬

		if (gas < v[0].dist) endTaxi(); // 최단 거리의 승객을 태우러 가지 못하는 경우 -1
		gas -= v[0].dist;
		bool ck = findDest(v[0]);
		if (!ck) endTaxi(); // 승객을 목적지까지 못데려다주는 경우 -1

		if (m == 0) break; // 모든 승객 처리
	}

	cout << gas << "\n";

	return 0;
}
