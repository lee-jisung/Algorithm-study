#include <iostream>

using namespace std;

// dp[i][j] => i ~ j 까지 곱셈 연산 최솟값

// dp[i][j] = min(dp[i][k] + dp[k+1][j] + matrix[i][[0] * matrix[k][1] * matrix[j][1]);
// ex), 행렬 => A, B, C, D, E라고 했을 때


// i = A, j = E, k = C라고 하고,

// A = 3 x 2, B = 2 x 2, C = 2 x 6, D = 6 x 3, E = 3 x 7이라고 하면
// A ~ C까지 결과 => 3 x 6 행렬이 만들어 지고
// k+1 -> D, j가 E이기 때문에 => 6 x 7의 행렬이 만들어 졋다고 쳤을 때,

// 3x 6, 6x7의 연산이 나와야함 => matrix[i][0] = 3이되고, matrix[k][1] = 6이되고, matrix[j][1] = 7이 되서
// 이 셋을 곱한 것에 dp[i][k] + dp[k+1][j]를 더한값이 최소가 되는 구간을 찾으면 됨

int n;
int matrix[501][2], dp[501][501];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> matrix[i][0] >> matrix[i][1];

	// 행렬 곱셈 i, i+1번째 곱
	for (int i = 1; i <= n; i++)
		dp[i][i + 1] = matrix[i][0] * matrix[i][1] * matrix[i + 1][1];

	// i ~ j 구간 최소 합 구하기 (interval 만큼 씩)
	for (int interval = 2; interval <= n; interval++) {
		// i는 1 부터 n-interval
		for (int i = 1; i <= n - interval; i++) {
			int j = i + interval; // j => 마지막 행렬 index
			// i, j 사이의 index ==> k
			for (int k = i; k < j; k++) {
				int sum = dp[i][k] + dp[k + 1][j] + matrix[i][0] * matrix[k][1] * matrix[j][1];
				if (!dp[i][j] || dp[i][j] > sum) dp[i][j] = sum;
			}
		}
	}
	cout << dp[1][n] << "\n";

	return 0;
}
