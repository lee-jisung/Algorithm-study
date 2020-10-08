#include <iostream>
#include <algorithm>

using namespace std;

/*
  1 or 3개씩 가져갈 수 있음
  => 수가 홀수면 무조건 상근 승 짝수면 창영 승
*/

int n;
int dp[1001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	/*dp[1] = dp[3] = 1;
	dp[2] = 2;

	for (int i = 4; i <= n; i++) {
		dp[i] = min(dp[i - 1], dp[i - 3]) + 1;
	}

	if (dp[n] % 2 == 0) cout << "CY\n";
	else cout << "SK\n";*/

	if (n % 2 == 0) cout << "CY\n";
	else cout << "SK\n";

	return 0;
}
