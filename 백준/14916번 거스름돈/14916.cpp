#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
   거스름돈 => 2, 5원만 가지고 있음
   2, or 5로 만들 수 있는 수 아니면 전부 -1로 return

   따라서 dp를 전부 -1로 해놓고, 2 or 5의 배수인 수에 대해서만 최소갯수로 갱신
*/

int n;
int dp[100001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[2] = 1; dp[4] = 2;
	dp[5] = 1;

	for (int i = 6; i <= n; i++) {
		if (dp[i - 2] != -1)
			dp[i] = dp[i-2] + 1;
		if (dp[i - 5] != -1)
			dp[i] = min(dp[i], dp[i - 5] + 1);
	}

	cout << dp[n] << "\n";
	return 0;
}
