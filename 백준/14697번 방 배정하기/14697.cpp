#include <iostream>

using namespace std;

/*
   방 => 1, 2, 5인실 이라고 했을 때 인원이 1명, 2명, 5명에 대해서는 방배정이 확실
   그렇다면 2명이 확실하기 때문에 2명에 +1, +2, +5한 3, 4, 7명에 대해서도 확실
  
  예를들어 7명이 빈침대없이 배정 가능한지 확인할때 => 7에서 1, 2, 5를 뺀 6, 5, 2명일 때를 확인하고 
  이때 하나라도 배정가능하다면 7명도 배정가능한것 => 셋다 불가능하면 7은 불가
*/

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c, student;
	int dp[301];

	cin >> a >> b >> c >> student;
	dp[0] = 1;

	for (int i = 1; i <= student; i++) {
		if (i >= a) {
			if (i >= b) {
				if (i >= c) {
					dp[i] = dp[i - a] + dp[i - b] + dp[i - c];
				}
				else {
					dp[i] = dp[i - a] + dp[i - b];
				}
			}
			else {
				dp[i] = dp[i - a];
			}
		}
		else {
			dp[i] = 0;
		}
	}

	if (dp[student] == 0) cout << 0 << "\n";
	else cout << 1 << "\n";

	return 0;

}
