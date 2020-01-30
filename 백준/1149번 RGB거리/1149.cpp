#include <iostream>
#include <algorithm>
#include <cstring>

#define SIZE 1001

using namespace std;

int n, result;
int color[SIZE][3], dp[SIZE][3];

// dp[i][0], dp[i][1], dp[i][2] 에 각각 RGB를 선택해서 더하여 최솟값으로 만드는 모든 경우를 계산하고
// 최종적으로 셋중에서 가장 최솟값을 선택하면 됨.

int main(void) {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + color[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
	}

	result = min(dp[n][0], min(dp[n][1], dp[n][2]));

	cout << result << "\n";

	return 0;
}
