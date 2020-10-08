#include <iostream>
#include <algorithm>

using namespace std;

/*
  dp[i-1], dp[i-3], dp[i-4]가 모두 1 (상근이 이긴경우) 라면 i는 CY 승 => dp[i] = 0
  셋 중 하나라도 0이면 i는 상근이가 이길 수 있는 경우가 있음 => dp[i] = 1
*/

int n;
int dp[1001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[1] = dp[3] = dp[4] = 1;
	cin >> n;

	for (int i = 5; i <= n; i++) {
		if (min(dp[i - 1], min(dp[i - 3], dp[i - 4])) == 1) {
			dp[i] = 0;
		}
		else dp[i] = 1;
	}

	if (dp[n] % 2 == 0) cout << "CY\n";
	else cout << "SK\n";


	return 0;
}
