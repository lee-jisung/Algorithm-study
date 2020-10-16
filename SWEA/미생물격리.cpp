#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

struct micro {
	int r, c;
	int dir;
	int size;
};

int TC, t;
int n, k, m;
int dr[5] = { 0, -1, 1, 0, 0 }, dc[5] = { 0, 0, 0, -1, 1 };

int getReverseDir(int dir) {
	switch (dir) {
	case 1: return 2;
	case 2: return 1;
	case 3: return 4;
	case 4: return 3;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> TC;
	while (TC--) {
		deque<micro> board[101][101];
		int result = 0;

		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			int r, c, size, dir;
			cin >> r >> c >> size >> dir;
			board[r][c].push_back({ r, c, dir, size });
		}


		for (int times = 0; times < m; times++) {

			deque<micro> moving;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (!board[i][j].empty()) {
						moving.push_back(board[i][j].back());
						board[i][j].pop_back();
					}
				}
			}

			// 이동
			for (int i = 0; i < moving.size(); i++) {
				int r = moving[i].r;
				int c = moving[i].c;
				int dir = moving[i].dir;
				int size = moving[i].size;
				int nr = r + dr[dir], nc = c + dc[dir];
				// 약품 구역
				if (nr == 0 || nc == 0 || nr == n - 1 || nc == n - 1) {
					dir = getReverseDir(dir);
					size /= 2;
					if (!board[nr][nc].empty()) {
						if (board[nr][nc].front().size < size)
							board[nr][nc].push_front({ nr, nc, dir, size });
						else board[nr][nc].push_back({ nr, nc, dir, size });
					}
					else board[nr][nc].push_back({ nr, nc, dir, size });
				}
				else {
					if (!board[nr][nc].empty()) {
						if (board[nr][nc].front().size < size)
							board[nr][nc].push_front({ nr, nc, dir, size });
						else board[nr][nc].push_back({ nr, nc, dir, size });
					}
					else board[nr][nc].push_back({ nr, nc, dir, size });
				}
			}

			// 2개 이상인 경우 pop
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (board[i][j].size() >= 2) {
						int size = board[i][j].size();
						for (int k = 0; k < size - 1; k++) {
							board[i][j].front().size += board[i][j].back().size;
							board[i][j].pop_back();
						}
					}
				}
			}

		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!board[i][j].empty())
					result += board[i][j][0].size;
			}
		}

		cout << "#" << ++t << " " << result << "\n";
	}


	return 0;
}
