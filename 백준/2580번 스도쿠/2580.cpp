#include <iostream>

using namespace std;

int board[9][9];
bool row[9][10], col[9][10], square[9][10];

int getSquareIdx(int r, int c) {
	return (r / 3) * 3 + c / 3;
}

void sdoku(int idx) {
	if (idx == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
		exit(0);
	}

	int r = idx / 9;
	int c = idx % 9;
	if (board[r][c]) sdoku(idx + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (!col[c][i] && !row[r][i] && !square[getSquareIdx(r, c)][i]) {
				board[r][c] = i;
				col[c][i] = true;
				row[r][i] = true;
				square[getSquareIdx(r, c)][i] = true;
				sdoku(idx + 1);
				board[r][c] = 0;
				col[c][i] = false;
				row[r][i] = false;
				square[getSquareIdx(r, c)][i] = false;
			}
		}
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				row[i][board[i][j]] = true;
				col[j][board[i][j]] = true;
				square[getSquareIdx(i, j)][board[i][j]] = true;
			}
		}
	}

	sdoku(0);

	return 0;
}
