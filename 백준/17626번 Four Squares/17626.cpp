#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

/*
   dp[i] => i를 만드는 제곱수들의 개수 중 최소값
   dp[i] = min(dp[i-j*j]) + 1
   어떤 수 i의 최소 제곱수 -> i보다 작은 제곱수들 중 i - (j*j)의 최솟값 + 1
 */

int n,minVal;
int dp[50001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		minVal = INF;
		for (int j = 1; j * j <= i; j++) {
			minVal = min(minVal, dp[i - j * j]);
		}
		dp[i] = minVal + 1;
	}
	cout << dp[n] << "\n";
	
	return 0;

}
