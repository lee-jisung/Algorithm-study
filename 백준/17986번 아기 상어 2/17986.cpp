#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

/*
   임의의 시작 지점에서 가장 가까운 상어와의 거리의 최댓값 찾기
*/

using namespace std;

int n, m, dist;
int board[51][51];
bool isVisit[51][51];

int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void findMaxDist(int y, int x) {
	memset(isVisit, false, sizeof(isVisit));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {y, x}, 0 });
	isVisit[y][x] = true;

	while (!q.empty()) {
		
		int r = q.front().first.first;
		int c = q.front().first.second;
		int depth = q.front().second;
		q.pop();

		if (board[r][c] == 1) {
			dist = max(dist, depth);
			return;
		}

		for (int i = 0; i < 8; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || isVisit[nr][nc]) continue;
			q.push({ {nr, nc},depth + 1 });
			isVisit[nr][nc] = true;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) continue;
			findMaxDist(i, j);
		}
	}

	cout << dist << "\n";

	return 0;
}
