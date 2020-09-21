#include <iostream>
#include <algorithm>

using namespace std;

int n, resCnt, resMove;
char board[5][9];
int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int getPin() {
	int cnt = 0;
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 9; j++) 
			if (board[i][j] == 'o') cnt++;
	return cnt;
}

void movePin(int mov) {

	int cnt = getPin();
	if (resCnt >= cnt) {
		if (resCnt == cnt) {
			resMove = min(resMove, mov);
		}
		else {
			resCnt = cnt;
			resMove = mov;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {

			if (board[i][j] == 'o') {
				for (int k = 0; k < 4; k++) {

					int nr = i + dr[k], nc = j + dc[k];

					if (nr < 0 || nc < 0 || nr >= 5 || nc >= 9) continue;
					if (board[nr][nc] == '#' || board[nr][nc] == '.') continue;
					// 다음칸의 범위가 넘어가는지 여부를 확인해야함
					if (nr + dr[k] < 0 || nc + dc[k] < 0 || nr +dr[k] >= 5 || nc + dc[k] >= 9) continue;

					if (board[nr][nc] == 'o' && board[nr + dr[k]][nc + dc[k]] == '.') {

						board[i][j] = board[nr][nc] = '.';
						board[nr + dr[k]][nc + dc[k]] = 'o';

						movePin(mov + 1);

						board[i][j] = board[nr][nc] = 'o';
						board[nr + dr[k]][nc + dc[k]] = '.';
					}
				}
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {

		for (int r = 0; r < 5; r++) {
			string s; cin >> s;
			for (int c = 0; c < 9; c++) {
				board[r][c] = s[c];
			}
		}
		resCnt = resMove = 1e9;
		movePin(0);

		cout << resCnt << " " << resMove << "\n";
	}

	return 0;
}
