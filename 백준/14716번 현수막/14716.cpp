#include <iostream>

using namespace std;

/*
  영역 찾기 - 상, 하, 좌, 우, 대각선
*/

int n, m;
int board[251][251], letter;
bool isVisit[251][251];

int dr[8] = { -1, 0, 1, 0, -1, -1, 1, 1 }, dc[8] = { 0, 1, 0, -1, 1, -1, 1, -1};

void findLetter(int r, int c) {

	if (r < 0 || c < 0 || r >= n || c >= m) return;
	if (board[r][c] == 0 || isVisit[r][c]) return;
	isVisit[r][c] = true;
	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		findLetter(nr, nc);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] && !isVisit[i][j]) {
				findLetter(i, j);
				letter++;
			}
		}
	}

	cout << letter << "\n";

	return 0;
}
