#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 301
#define INF 987654321

using namespace std;

int n, m; 
int stairs[SIZE], dp[SIZE];

// 1. dp[n] = dp[n-3] + stairs[n-1] + stairs[n] -> n번째 바로 전 계단을 밟은 경우 3연속은 불가하기때문에 n-3으로 감
// 2. dp[n] = dp[n-2] + stairs[n] -> 그냥 2번째 전에서 올라온 경우

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stairs[i];

	dp[1] = stairs[1];
	dp[2] = dp[1] + stairs[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
	}

	cout << dp[n] << "\n";

	return 0;
}
