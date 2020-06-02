#include <iostream>

#define SIZE 51

using namespace std;

int R, C, T, result;
int r1, c1, r2, c2;
int board[SIZE][SIZE], temp[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void init() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			temp[i][j] = 0;
}

void spread() {
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] != 0 && board[i][j] != -1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {

					int nr = i + dr[k], nc = j + dc[k];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C || board[nr][nc] == -1) continue;
					cnt++;
					temp[nr][nc] += board[i][j] / 5;
				}
				board[i][j] -= (board[i][j] / 5) * cnt;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] != -1)
				board[i][j] += temp[i][j];
		}
	}
}

void clear() {

	for (int i = r1 - 1; i > 0; i--)
		board[i][c1] = board[i - 1][c1];
	for (int i = 0; i < C - 1; i++)
		board[0][i] = board[0][i + 1];
	for (int i = 0; i < r1; i++)
		board[i][C - 1] = board[i + 1][C - 1];
	for (int i = C - 1; i > 1; i--)
		board[r1][i] = board[r1][i - 1];
	board[r1][1] = 0;

	for (int i = r2 + 1; i < R - 1; i++)
		board[i][0] = board[i + 1][0];
	for (int i = 0; i < C - 1; i++)
		board[R-1][i] = board[R-1][i + 1];
	for (int i = R - 1; i > r2; i--)
		board[i][C - 1] = board[i - 1][C - 1];
	for (int i = C - 1; i > 1; i--)
		board[r2][i] = board[r2][i - 1];
	board[r2][1] = 0;

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;
	int idx = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1 && idx == 0)
				r1 = i, c1 = j, idx++;
			else if (board[i][j] == -1 && idx == 1)
				r2 = i, c2 = j;
		}
	}
	
	while (T--) {
		init();
		spread();
		clear();
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (board[i][j] > 0) result += board[i][j];

	cout << result << "\n";
	return 0;
}
