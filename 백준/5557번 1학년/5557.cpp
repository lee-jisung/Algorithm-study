#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

#define INF 1e9
#define SIZE 100

using namespace std;

/*
   i번째 수 arr[i]에 대해서, 임의의 수 0 <= j <= 20인 j

   j + arr[i] <= 20 이라면, d[i][j+arr[i]] += dp[i-1][j];
   j - arr[i] >= 0 , dp[i][j - arr[i]] += d[i-1][j];

   즉, dp[i-1][j]가 만들어질 수 있는 경우가 있고,
   dp[i][j+ arr[i]] or dp[i][j-arr[i]]에서 j값이 0 이상, 20 이하인 수라면

   d[i-1][j]를 만든 경우의 수를 더해준다.
*/

int n, arr[101];
long long dp[101][21]; // 2 ^ 98개 경우의 수가 있을 수 있으므로 long long

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[1][arr[1]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j]) {
				if (j + arr[i] <= 20) dp[i][j + arr[i]] += dp[i - 1][j];
				if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}

	// n-1번째까지 +, -를 이용해서 n번째 수를 만들 수 있는 경우의 수
	cout << dp[n - 1][arr[n]] << "\n";

	return 0;
}
