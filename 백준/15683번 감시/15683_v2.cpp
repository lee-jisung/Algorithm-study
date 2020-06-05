#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CCTV {
	int r, c;
	int no;
};

int n, m, result;
int board[8][8], temp[8][8], direction[8];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, -1, 0, 1 };

vector<CCTV> cctv;

void copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = board[i][j];
}

void remove_space() {

	for (int i = 0; i < cctv.size(); i++) {
		int nr = cctv[i].r, nc = cctv[i].c;
		int dir = direction[i];
		switch (cctv[i].no) {

		case 1:
			while (1) {
				if (nr + dr[dir] < 0 || nc + dc[dir] < 0 || nr + dr[dir] >= 8 || nc + dc[dir] >= 8 ||
					board[nr + dr[dir]][nc + dc[dir]] == 6)break;
				nr += dr[dir]; nc += dc[dir];
				temp[nr][nc] = 9;
			}
			break;
		case 2:
			dir = (direction[i] % 2);
			while (1) {
				if (nr + dr[dir] < 0 || nc + dc[dir] < 0 || nr + dr[dir] >= 8 || nc + dc[dir] >= 8 ||
					board[nr + dr[dir]][nc + dc[dir]] == 6)break;
				nr += dr[dir]; nc += dc[dir];
				temp[nr][nc] = 9;
			}
			nr = cctv[i].r; nc = cctv[i].c;
			dir += 2;
			while (1) {
				if (nr + dr[dir] < 0 || nc + dc[dir] < 0 || nr + dr[dir] >= 8 || nc + dc[dir] >= 8 ||
					board[nr + dr[dir]][nc + dc[dir]] == 6)break;
				nr += dr[dir]; nc += dc[dir];
				temp[nr][nc] = 9;
			}
			break;
		case 3:
			while (1) {
				if (nr + dr[dir] < 0 || nc + dc[dir] < 0 || nr + dr[dir] >= 8 || nc + dc[dir] >= 8 ||
					board[nr + dr[dir]][nc + dc[dir]] == 6)break;
				nr += dr[dir]; nc += dc[dir];
				temp[nr][nc] = 9;
			}
			nr = cctv[i].r; nc = cctv[i].c;
			dir = (dir + 1) % 4;
			while (1) {
				if (nr + dr[dir] < 0 || nc + dc[dir] < 0 || nr + dr[dir] >= 8 || nc + dc[dir] >= 8 ||
					board[nr + dr[dir]][nc + dc[dir]] == 6)break;
				nr += dr[dir]; nc += dc[dir];
				temp[nr][nc] = 9;
			}
			break;
		case 4:
			for (int k = 0; k < 4; k++) {
				nr = cctv[i].r; nc = cctv[i].c;
				if (dir == k) continue;
				while (1) {
					if (nr + dr[k] < 0 || nc + dc[k] < 0 || nr + dr[k] >= 8 || nc + dc[k] >= 8 ||
						board[nr + dr[k]][nc + dc[k]] == 6)break;
					nr += dr[k]; nc += dc[k];
					temp[nr][nc] = 9;
				}
			}
			break;
		case 5:
			for (int k = 0; k < 4; k++) {
				nr = cctv[i].r; nc = cctv[i].c;
				while (1) {
					if (nr + dr[k] < 0 || nc + dc[k] < 0 || nr + dr[k] >= 8 || nc + dc[k] >= 8 ||
						board[nr + dr[k]][nc + dc[k]] == 6)break;
					nr += dr[k]; nc += dc[k];
					temp[nr][nc] = 9;
				}
			}
			break;
		}
	}
}

void dfs(int no) {

	if (no == cctv.size()) {
		copy();
		remove_space();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == 0) cnt++;
			}
		}
		result = min(result, cnt);
		return;
	}
	if (cctv[no].no == 5) dfs(no + 1);
	for (int i = 0; i < 4; i++) {
		direction[no] = i;
		dfs(no + 1);
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] >= 1 && board[i][j] <= 5) {
				cctv.push_back({ i, j, board[i][j] });
			}
		}
	}

	result = 1e9;
	dfs(0);

	cout << result << "\n";

	return 0;
}
