#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 1001
#define INF 987654321

using namespace std;

int n, m; 
long long dp[SIZE], pay[SIZE];
// dp[n] = max(dp[n], dp[n-i] + p[i]) => i= 1 ~ n까지
// 매번 최적화된 답을 dp[n]에 저장

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> pay[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + pay[j]);
		}
	}
	
	cout << dp[n] << "\n";
	return 0;
}
