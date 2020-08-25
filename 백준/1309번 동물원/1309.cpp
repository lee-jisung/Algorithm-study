#include <iostream>

#define MOD 9901

using namespace std;

int n, res;
int dp[100001][3];

/*
   1. 단순 덧셈 점화식 => dp[i] = dp[i-2] + dp[i-1] * 2 

   2. 사자 배치 가능한 경우 3가지
     1 => N번째 줄에 사자가 모두 없는 경우
	      => 현재 줄에 사자가 모두 없다면 윗줄에는 사자 왼쪽 or 오른쪽 or 미배치 가능
	      => dp[n][0] = dp[n-1][0] + dp[n-1][1] + dp[n-1][2]

	 2 => N번째 줄에 왼쪽칸에만 사자가 있는 경우
	      => N-1번쨰 줄에 사자 오른쪽칸 or 미배치 가능
	      => dp[n][1] = dp[n-1][0] + dp[n-1][2];

	 3 => N번째 줄 오른쪽 칸에만 사자가 있는 경우
	      => N-1번째 줄에 사자 왼쪽 or 미배치 가능
          => dp[n][2] = dp[n-1][0] + dp[n-1][1];
   
 */

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[1][0] = 1; dp[1][1] = 1; dp[1][2] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
	}

	res = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
	cout << res << "\n";

	return 0;
}
