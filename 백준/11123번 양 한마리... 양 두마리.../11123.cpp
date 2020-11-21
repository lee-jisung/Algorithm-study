#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int t, h, w, result;
char board[101][101];
bool isVisit[101][101];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

void findSheep(int r, int c) {

	isVisit[r][c] = true;
	
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
		if (isVisit[nr][nc] || board[nr][nc] == '.') continue;
		findSheep(nr, nc);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t ;
	while (t--) {
		cin >> h >> w;

		result = 0;
		memset(isVisit, false, sizeof(isVisit));

		for (int i = 0; i < h; i++) {
			string str; cin >> str;
			for (int j = 0; j < w; j++) {
				board[i][j] = str[j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (board[i][j] != '#' || isVisit[i][j]) continue;
				findSheep(i, j);
				result++;
			}
		}
		cout << result << "\n";
	}

	return 0;
}
