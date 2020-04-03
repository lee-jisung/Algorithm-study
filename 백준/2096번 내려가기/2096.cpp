#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100001
#define INF 987654321

using namespace std;

int n, board[SIZE][3];
int max_dp[2][3], min_dp[2][3];

/*
   dp[i][j] = max(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + a[i][j];
   dp의 행을 SIZE만큼 선언하면 메모리 초과가 발생
   --> 해결 = 2행으로 바로 직전 값을 계속 갱신해가면서 저장
*/

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {

		for (int j = 0; j < 3; j++) {

			if (j == 0) {
				max_dp[1][j] = max(max_dp[0][j], max_dp[0][j+1]) + board[i][j];
				min_dp[1][j] = min(min_dp[0][j], min_dp[0][j+1]) + board[i][j];
			}
			else if (j == 1) {
				max_dp[1][j] = max(max_dp[0][j-1], max(max_dp[0][j], max_dp[0][j + 1])) + board[i][j];
				min_dp[1][j] = min(min_dp[0][j-1], min(min_dp[0][j], min_dp[0][j + 1])) + board[i][j];
			}
			else {
				max_dp[1][j] = max(max_dp[0][j - 1], max_dp[0][j]) + board[i][j];
				min_dp[1][j] = min(min_dp[0][j - 1], min_dp[0][j]) + board[i][j];
			}
		}
		for (int j = 0; j < 3; j++) {
			max_dp[0][j] = max_dp[1][j];
			min_dp[0][j] = min_dp[1][j];
		}

	}
	int res1 = max(max_dp[1][0], max(max_dp[1][1], max_dp[1][2]));
	int res2 = min(min_dp[1][0], min(min_dp[1][1], min_dp[1][2]));
	
	cout << res1 << " " << res2 << "\n";
	return 0;
}
