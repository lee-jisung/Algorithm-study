#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1001
#define INF 987654321

using namespace std;

int n, m; 
int candy[SIZE][SIZE], dp[SIZE][SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> candy[i][j];
		}
	}

	dp[0][0] = candy[0][0];
	for (int i = 1; i < n; i++)
		dp[i][0] += dp[i - 1][0] + candy[i][0];
	for (int j = 1; j < m; j++)
		dp[0][j] += dp[0][j - 1] + candy[0][j];

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + candy[i][j];
		}
	}

	cout << dp[n - 1][m - 1] << "\n";

	return 0;
}
