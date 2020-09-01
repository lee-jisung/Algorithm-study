#include <iostream>

using namespace std;

/*
   0 ~ n까지 정수 k개를 사용해서 n 만들기
   1개 사용 => n 인 수

   n=2, k=2일 때, 
   (0,2), (1, 1), (2,0) 으로 3개

   dp[k][n] = dp[k-1][0] + d[k-1][1] + ... + dp[k-1][n];
*/

const int MOD = 1e9;

int N, K;
long long dp[201][201];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < 201; i++)
		dp[1][i] = 1;

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
