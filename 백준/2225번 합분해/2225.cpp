#include <iostream>

using namespace std;

/*
   dp[k][n] => 정수 k개를 더해서 n이 되는 경우의 수 저장

   dp[K][N] = dp[k-1][0] + dp[k-1][1] + ... + dp[k-1][N];
*/

const int MOD = 1e9;

int N, K;
long long dp[201][201];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i <= 200; i++) {
		dp[1][i] = 1;
	}

	for (int k = 2; k <= K; k++) {
		for (int n = 0; n <= N; n++) {
			for (int i = 0; i <= n; i++) {
				dp[k][n] += dp[k - 1][i];
				dp[k][n] %= MOD;
			}
		}
	}

	cout << dp[K][N] << "\n";

	return 0;
}
