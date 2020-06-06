#include <iostream>

#define SIZE 101

using namespace std;


int n, L, cnt;
int board[SIZE][SIZE];
bool garo[SIZE][SIZE], sero[SIZE][SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> L;
	for (int i = 0; i < n;i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	//가로
	for (int i = 0; i < n; i++) {
		bool ck = true;
		for (int j = 0; j < n - 1; j++) {
			if (board[i][j] != board[i][j + 1]) {

				int diff = abs(board[i][j] - board[i][j + 1]);

				if (diff == 1) {
					if (board[i][j] < board[i][j + 1]) {
						for (int k = 0; k < L;k++) {
							if (j - k < 0) ck = false;
							else if (board[i][j] != board[i][j - k]) ck = false;
							else if (garo[i][j - k]) ck = false;
							else garo[i][j - k] = true;
						}
					}
					else if(board[i][j] > board[i][j+1]) {
						for (int k = 0; k < L; k++) {
							if (j + 1 + k >= n) ck = false;
							else if (board[i][j + 1] != board[i][j + 1 + k]) ck = false;
							else if (garo[i][j + 1 + k]) ck = false;
							else garo[i][j + 1 + k] = true;
						}
					}
				}
				else if (diff >= 2)
					ck = false;
			}
		}
		if (ck) cnt++;
	}

	// 세로
	for (int j = 0; j < n; j++) {
		bool ck = true;
		for (int i = 0; i < n - 1; i++) {
			if (board[i][j] != board[i + 1][j]) {

				int diff = abs(board[i][j] - board[i + 1][j]);

				if (diff == 1) {
					if (board[i][j] < board[i + 1][j]) {
						for (int k = 0; k < L; k++) {
							if (i - k < 0) ck = false;
							else if (board[i][j] != board[i - k][j]) ck = false;
							else if (sero[i - k][j]) ck = false;
							else sero[i - k][j] = true;
						}
					}
					else if (board[i][j] > board[i + 1][j]) {
						for (int k = 0; k < L; k++) {
							if (i + 1 + k >= n) ck = false;
							else if (board[i + 1][j] != board[i + 1 + k][j]) ck = false;
							else if (sero[i + 1 + k][j]) ck = false;
							else sero[i + 1 + k][j] = true;
						}
					}
				}
				else if (diff >= 2)
					ck = false;
			}
		}
		if (ck) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}
