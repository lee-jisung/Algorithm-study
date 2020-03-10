#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 91
#define INF 987654321

using namespace std;

int n, m; 
long long dp[SIZE];

// 1, 1, 2, 3, 5, .... --> 개수가 피보나치 수열로 증가
// dp[n] = dp[n-1] + dp[n-2];

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;

	dp[1] = 1; dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << "\n";

	return 0;
}
