#include <iostream>

#define SIZE 501

/*
   DFS + DP 
   DP[a][b] = c => a,b에서는 (m-1, n-1)까지 c개의 경로로 도달 가능

   (m-1, n-1)에서 0,0으로 역순으로 가는 dp라고 생각하면 됨

*/

using namespace std;

int n, m, res;
int board[SIZE][SIZE], dp[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

// TLE
//void findPath(int r, int c) {
//
//	if (r == m - 1 && c == n - 1) {
//		res++;
//		return;
//	}
//
//	for (int i = 0; i < 4; i++) {
//		int nr = r + dr[i];
//		int nc = c + dc[i];
//		if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
//		if (board[nr][nc] >= board[r][c]) continue;
//		findPath(nr, nc);
//	}
//}

int findPath(int r, int c) {
	if (r == m - 1 && c == n - 1) {
		return 1;
	}
	if (dp[r][c] != -1) return dp[r][c];
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
		if (board[nr][nc] >= board[r][c]) continue;
		sum += findPath(nr, nc);
	}

	return dp[r][c] = sum;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	cout << findPath(0, 0) << "\n";
	return 0;
}
