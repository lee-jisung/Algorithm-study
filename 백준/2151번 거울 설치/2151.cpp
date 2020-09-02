#include <iostream>
#include <algorithm>
#include <queue>

#define INF 1e9

using namespace std;

struct node {
	int r, c;
	int dir;
};

int n, idx, res;
int mirror[51][51][4];
char board[51][51];
pair<int, int> door[2];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs() {

	queue<node> q;
	for (int i = 0; i < 4; i++) {
		q.push({ door[0].first, door[0].second, i });
		mirror[door[0].first][door[0].second][i] = 0;
	}

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int dir = q.front().dir;
		q.pop();

		int nr = r + dr[dir], nc = c + dc[dir];
		int nDir1, nDir2;
		if (dir == 0 || dir == 1) {
			nDir1 = 2; nDir2 = 3;
		}
		else {
			nDir1 = 0; nDir2 = 1;
		}

		if (nr < 0 || nc < 0 || nr >= n || nc >= n || board[nr][nc] == '*') continue;
		if (board[nr][nc] == '!') {
			if (mirror[nr][nc][dir] > mirror[r][c][dir]) { // 거울 설치 x 
				q.push({ nr,nc,dir });
				mirror[nr][nc][dir] = mirror[r][c][dir];
			}
			if (mirror[nr][nc][nDir1] > mirror[r][c][dir] + 1) { // 설치 o
				mirror[nr][nc][nDir1] = mirror[r][c][dir] + 1;
				q.push({ nr, nc, nDir1 });
			}
			if (mirror[nr][nc][nDir2] > mirror[r][c][dir] + 1) { // 설치 o
				mirror[nr][nc][nDir2] = mirror[r][c][dir] + 1;
				q.push({ nr, nc, nDir2 });
			}
		}
		else if (board[nr][nc] == '.') {
			if (mirror[nr][nc][dir] > mirror[r][c][dir]) { 
				q.push({ nr,nc,dir });
				mirror[nr][nc][dir] = mirror[r][c][dir];
			}
		}
		else if (board[nr][nc] == '#') {
			if (mirror[nr][nc][dir] > mirror[r][c][dir]) {
				mirror[nr][nc][dir] = mirror[r][c][dir];
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == '#') 
				door[idx++] = { i, j };
			for (int k = 0; k < 4; k++)
				mirror[i][j][k] = INF;
		}
	}

	res = INF;
	bfs();

	for (int i = 0; i < 4; i++)
		res = min(res, mirror[door[1].first][door[1].second][i]);
	cout << res << "\n";

	return 0;
}
