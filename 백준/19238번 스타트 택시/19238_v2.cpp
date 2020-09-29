#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Passenger {
	int r, c;
	int no;
	int dist;
};

int n, m, fuel;
int board[21][21];
bool isVisit[21][21], isEnd = true;
pair<int, int> taxi, dest[401];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

vector<Passenger> bfs() {
	memset(isVisit, false, sizeof(isVisit));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {taxi.first, taxi.second}, 0 });
	isVisit[taxi.first][taxi.second] = true;
	vector<Passenger> v;

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (board[r][c] != 0) {
			v.push_back({ r, c, board[r][c], dist });
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr <= 0 || nc <= 0 || nr > n || nc > n) continue;
			if (board[nr][nc] == -1 || isVisit[nr][nc]) continue;

			q.push({ {nr, nc}, dist + 1 });
			isVisit[nr][nc] = true;
		}
	}
	return v;
}

bool goToDest(int no) {
	memset(isVisit, false, sizeof(isVisit));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {taxi.first, taxi.second}, 0 });
	isVisit[taxi.first][taxi.second] = true;

	while (!q.empty()) {

		int r = q.front().first.first;
		int c = q.front().first.second;
		int dist = q.front().second;
		q.pop();

		if (r == dest[no].first && c == dest[no].second && dist <= fuel) {
			fuel += dist;
			taxi.first = r; taxi.second = c;
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr <= 0 || nc <= 0 || nr > n || nc > n) continue;
			if (isVisit[nr][nc] || board[nr][nc] == -1) continue;
			q.push({ {nr, nc}, dist + 1 });
			isVisit[nr][nc] = true;
		}
	}
	return false;
}

bool cmp(Passenger a, Passenger b) {
	if (a.dist == b.dist) {
		if (a.r == b.r)
			return a.c < b.c;
		return a.r < b.r;
	}
	return a.dist < b.dist;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> fuel;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j]) board[i][j] = -1;
		}

	cin >> taxi.first >> taxi.second;
	for (int i = 1; i <= m; i++) {
		int pr, pc, dr, dc;
		cin >> pr >> pc >> dr >> dc;
		board[pr][pc] = i;
		dest[i] = { dr, dc };
	}

	for (int i = 1; i <= m; i++) {
		vector<Passenger> v = bfs();
		if (v.empty()) {
			isEnd = false;
			break;
		}
		sort(v.begin(), v.end(), cmp);
		int dist = v[0].dist;
		int pno = v[0].no;
		int pr = v[0].r, pc = v[0].c;
		if (fuel < dist) {
			isEnd = false;
			break;
		}
		taxi.first = pr; taxi.second = pc;
		fuel -= dist;
		board[pr][pc] = 0;
		if (!goToDest(pno)) {
			isEnd = false;
			break;
		}
	}
	if (isEnd) cout << fuel << "\n";
	else cout << -1 << "\n";

	return 0;
}
