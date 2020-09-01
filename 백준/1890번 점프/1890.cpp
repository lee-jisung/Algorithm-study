#include <iostream>

/*
   DP + DFS (BOJ 1520 내리막길과 비슷)
   2^63 -1개 => long long 자료형 사용
*/

using namespace std;

int n;
int board[101][101];
long long dp[101][101];

int dr[2] = { 1, 0 }, dc[2] = { 0, 1 };

long long findPath(int r, int c) {
	if (r == n - 1 && c == n - 1) return 1;
	if (dp[r][c] != -1) return dp[r][c];

	long long sum = 0;
	for (int i = 0; i < 2; i++) {
		int nr = r + dr[i] * board[r][c];
		int nc = c + dc[i] * board[r][c];
		if (nr == r && nc == c) continue;
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		sum += findPath(nr, nc);
	}
	return dp[r][c] = sum;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}

	cout << findPath(0, 0) << "\n";

	return 0;
}
