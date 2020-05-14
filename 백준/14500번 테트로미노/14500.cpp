#include <iostream>
#include <algorithm>

#define SIZE 501

using namespace std;

/*
   ㅗ 모양을 제외한 나머지 -> depth가 3일 때 까지의 합을 구하면 되는 문제
   dfs로 탐색하여 depth가 3이면 그때의 합을 return해주고 max값을 찾으면 됨

   단, ㅗ의 경우만 4가지 경우를 만들어주어서 max값 찾고

   최종 result값과 비교해서 도출하면 끝
*/

int n, m, result;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int dfs(int r, int c, int cnt) {

	if (cnt == 3) return board[r][c];

	int sum = 0;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (0 <= nr && nr < n && 0 <= nc && nc < m && !isVisit[nr][nc]) {
			isVisit[nr][nc] = true;
			sum = max(sum, board[r][c] + dfs(nr, nc, cnt + 1));
			isVisit[nr][nc] = false;
		}
	}
	return sum;
}

// ㅗ들의 모양 중 r, c,가 ㅡ부분의 가운데 위치하는 경우일 때의 조건
int exceptTet(int r, int c) {
	
	int sum = 0;
	if (r > 0 && c > 0 && c < m - 1) // ㅗ모양
		sum = max(sum, board[r][c] + board[r][c - 1] + board[r][c + 1] + board[r - 1][c]);
	if (r > 0 && r < n - 1 && c < m - 1) // ㅏ 모양
		sum = max(sum, board[r][c] + board[r - 1][c] + board[r + 1][c] + board[r][c + 1]);
	if (r < n - 1 && 0 < c && c < m - 1) // ㅜ 모양
		sum = max(sum, board[r][c] + board[r][c - 1] + board[r][c + 1] + board[r + 1][c]);
	if (r > 0 && r < n - 1 && c > 0) // ㅓ모양
		sum = max(sum, board[r][c] + board[r - 1][c] + board[r + 1][c] + board[r][c - 1]);

	return sum;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0;j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			isVisit[i][j] = true;
			result = max(result, dfs(i, j, 0));
			result = max(result, exceptTet(i, j));
			isVisit[i][j] = false;
		}
	}

	cout << result << "\n";

	return 0;
}	
