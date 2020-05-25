#include <iostream>
#include <algorithm>

#define SIZE 501

using namespace std;

int n, result;
int board[SIZE][SIZE];
int dp[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

/*
   DFS로 방문처리만 해서 최대 일수 구하기 -> 시간초과
   DP를 사용해서 (y, x)지점에서 시작했을 때 최대 일수를 저장해놓고
   다른 지점에서 이전에 최대일수를 구했던 지점을 방문하게 되면 그 지점의 최대일수를 그냥 더해서 시간초과 해결
*/

int dfs(int y, int x) {

	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int nr = y + dr[i];
		int nc = x + dc[i];

		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		if (board[y][x] < board[nr][nc]) {
			dp[y][x] = max(dp[y][x], dfs(nr, nc) + 1);
		}
	}
	return dp[y][x];
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n; j++) {
			result = max(result, dfs(i, j));
		}
	}

	cout << result << "\n";

	return 0;
}
