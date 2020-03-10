#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 10001
#define INF 987654321

using namespace std;

int n, wine[SIZE];
long long dp[SIZE], result;

// 2579번 계단오르기와 거의 비슷
// dp[n] = max( dp[n-2] + wine[n], dp[n-3] + wine[n-1] + wine[n], dp[n-1])
// dp[n-1]의 경우 --> n-1까지 마시고 n번째를 안마시고 건너뛰는 경우까지 고려

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	dp[1] = wine[1];
	dp[2] = dp[1] + wine[2];
	
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2] + wine[i], max(dp[i - 3] + wine[i - 1] + wine[i], dp[i-1]));
	}

	cout << dp[n] << "\n";

	return 0;
}
