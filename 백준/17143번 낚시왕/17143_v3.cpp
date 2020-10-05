#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shark {
	int r, c;
	int move;
	int dir;
	int size;
};

int R, C, M;
int result;
vector<Shark> board[101][101];
vector<Shark> sharks;

int dr[5] = { 0, -1, 1, 0, 0 }, dc[5] = { 0, 0, 0, 1, -1 };

bool cmp(Shark a, Shark b) {
	return a.size > b.size;
}

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

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
		sharks.push_back({ r, c, s, d, z });
		board[r][c].push_back(sharks[i]);
	}

	for (int p_c = 1; p_c <= C; p_c++) {
		
		// take shark
		for (int j = 1; j <= R; j++) {
			if (!board[j][p_c].empty()) {
				result += board[j][p_c].back().size;
				board[j][p_c].pop_back();
				break;
			}
		}

		sharks.clear();
		for (int i = 1; i <= R; i++) {
			for (int j = 1;j <= C; j++) {
				int size = board[i][j].size();
				for (int k = 0; k < size; k++) {
					sharks.push_back(board[i][j].back());
					board[i][j].pop_back();
				}
			}
		}

		// move Sharks
		for (int i = 0; i < sharks.size(); i++) {
			int r = sharks[i].r, c = sharks[i].c;
			int dir = sharks[i].dir;
			int move = sharks[i].move;

			while (move) {
				switch (dir) {
				case 1:
					if (r + dr[dir] * move <= 1) {
						move -= r - 1;
						r = 1; dir = 2;
						
					}
					else {
						r = r + dr[dir] * move;
						move = 0;
					}
					break;
				case 2:
					if (r + dr[dir] * move >= R) {
						move -= R - r;
						r = R; dir = 1;
					}
					else {
						r = r + dr[dir] * move;
						move = 0;
					}
					break;
				case 3:
					if (c + dc[dir] * move >= C) {
						move -= C - c;
						c = C; dir = 4;
					}
					else {
						c = c + dc[dir] * move;
						move = 0;
					}
					break;
				case 4:
					if (c + dc[dir] * move <= 1) {
						move -= c - 1;
						c = 1; dir = 3;
					}
					else {
						c = c + dc[dir] * move;
						move = 0;
					}
					break;
				}
			}
			board[r][c].push_back({ r, c, sharks[i].move, dir, sharks[i].size });
		}

		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (board[i][j].size() >= 2) {
					int size = board[i][j].size();
					sort(board[i][j].begin(), board[i][j].end(), cmp);
					for (int k = 0; k <size - 1; k++) board[i][j].pop_back();
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}
