#include <iostream>
#include <algorithm>

using namespace std;

/*
  1의 제곱수로만 표현 => 숫자가 항의 개수일 것
  1부터 시작, 특정 수에 가장 가까운 제곱수 => a라고 했을 때

  dp[i] = min(dp[i], dp[i-a*a] + 1) => 즉, 뒤에 + 1은 dp[i-a*a]의 개수 + a*a를 더한 경우인 1이 되는것

  ex, dp[5] => min(dp[5], dp[5-1*1] + 1) => dp[4]에 1^2를 더한 경우
      dp[5] => min(dp[5], dp[5-2*2] + 1) => dp[1]에 2^2를 더한 경우가 가능 => 2개가 최소가될것
*/

int n;
int dp[100001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		dp[i] = i;
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	cout << dp[n] << "\n";
	
	return 0;
}
