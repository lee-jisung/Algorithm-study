#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 101
#define INF 987654321

using namespace std;

int tc, n; 
long long dp[SIZE];

// dp[9] 부터 1번째 전 + 5번째 전의 합과 같음
// dp[n] = dp[n-1] + dp[n-5]

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;
	dp[6] = 3; dp[7] = 4; dp[8] = 5;

	for (int i = 9; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}

	cin >> tc;

	while (tc--) {

		cin >> n;
		cout << dp[n] << "\n";
	}
		
	return 0;
}
