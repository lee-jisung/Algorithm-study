#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 1000001
#define INF 987654321

using namespace std;

int n;
int dp[SIZE];

// dp[n] = dp[n-1] + dp[n-2];

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 15746;
	}

	cout << dp[n] << "\n";

	return 0;
}
