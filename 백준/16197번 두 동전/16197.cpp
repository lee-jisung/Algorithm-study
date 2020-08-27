#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 1e9

/*
   양옆 1씩 늘려서 생각해보자
*/

using namespace std;

struct POS {
	int r1, c1;
	int r2, c2;
	int depth;
};

int n, m, res;
char board[21][21];
vector<pair<int, int>> coin;
bool isVisit[21][21][21][21];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

bool isDrop(int r, int c) {
	if (r <= 0 || c <= 0 || r > n || c > m) return true;
	return false;
}

void bfs() {

	queue<POS> q;
	q.push({ coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0 });
	isVisit[coin[0].first][coin[0].second][coin[1].first][coin[1].second] = true;

	while (!q.empty()) {

		int r1 = q.front().r1;
		int c1 = q.front().c1;
		int r2 = q.front().r2;
		int c2 = q.front().c2;
		int depth = q.front().depth;
		q.pop();

		if (depth > 10) continue;
		if (isDrop(r1, c1) && isDrop(r2, c2)) continue;
		if ((isDrop(r1, c1) && !isDrop(r2, c2)) || (!isDrop(r1, c1) && isDrop(r2, c2))) {
			res = min(res, depth);
			return;
		}

		for (int i = 0; i < 4; i++) {

			int nr1 = r1 + dr[i], nc1 = c1 + dc[i];
			int nr2 = r2 + dr[i], nc2 = c2 + dc[i];

			if (board[nr1][nc1] == '#') nr1 = r1, nc1 = c1;
			if (board[nr2][nc2] == '#') nr2 = r2, nc2 = c2;

			if (isVisit[nr1][nc1][nr2][nc2]) continue;
			q.push({ nr1, nc1, nr2, nc2, depth + 1 });
			isVisit[nr1][nc1][nr2][nc2] = true;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= m;j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				coin.push_back({ i, j });
			}
		}
	}

	res = INF;
	bfs();

	if (res == INF) cout << "-1\n";
	else cout << res << "\n";

	return 0;
}
