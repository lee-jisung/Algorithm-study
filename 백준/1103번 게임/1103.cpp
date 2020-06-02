#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

/*
   isVisit -> 현재 탐색 경로로 진행하다 방문한곳으로 다시 돌아올 경우 사이클 -> 무한히 반복 가능 > -1 출력 후 프로그램 종료

   dp[r][c] = a > (r, c)에서는 최대 a번 움직일 수 있다는 의미
   dp[r][c]를 -1로 전부 초기화 하고
   dp[r][c] != -1이라는 것은 이미 이전에 방문했던 좌표이기 때문에 dp[r][c]를 그대로 return
*/

int n, m, result;
int board[51][51];
int dp[51][51];
bool isVisit[51][51];
int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int dfs(int r, int c) {

	if (r < 0 || c < 0 || r >= n || c >= m || board[r][c] == -1)
		return 0;

	if (isVisit[r][c]) {
		cout << -1 << "\n";
		exit(0);
	}
	if (dp[r][c] != -1) return dp[r][c];

	isVisit[r][c] = true;
	dp[r][c] = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i] * board[r][c];
		int nc = c + dc[i] * board[r][c];
		dp[r][c] = max(dp[r][c], dfs(nr, nc) + 1);
	}
	isVisit[r][c] = false;
	return dp[r][c];
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < m; j++) {
			if (tmp[j] == 'H') board[i][j] = -1;
			else board[i][j] = tmp[j] - '0';
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << "\n";
	return 0;

}
