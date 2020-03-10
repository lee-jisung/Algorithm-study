//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring>
//#include <queue>
//#include <vector>
//#include <deque>
//#include <cmath>
//
//#define SIZE 101
//#define INF 987654321
//
//using namespace std;
//
//// 처음 1 2 3 4 5 6 7 8 9 의 각 숫자가 1개씩 존재할 때
//// dp[1][1] ~ dp[9][1] = 1을 넣어주고 
//// dp[1][n] ~ dp[9][n]은 그 전 양옆 숫자 갯수의 합이 됨
//// 즉, dp[1][n] = dp[0][n-1] + d[2][n-1]임
//
//// 여기서 덧셈 연산, 결과 덧셈, 결과 출력 모든 곳에서 1000000000으로 나누어주어야 답맞음
//
//int n, m; 
//long long dp[10][SIZE], result;
//
//int main(void) {
//
//	cin.tie(NULL);
//	ios_base::sync_with_stdio(false);
//
//	cin >> n;
//	
//	for (int i = 1;i <= 9; i++)
//		dp[i][1] = 1;
//
//	for (int i = 2; i <= n; i++) {
//
//		dp[0][i] += dp[1][i - 1] % 1000000000;
//		for (int j = 1; j <= 8; j++) {
//			dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % 1000000000;
//		}
//		dp[9][i] += dp[8][i - 1] % 1000000000;
//	}
//
//	for (int i = 0; i <= 9; i++) {
//		result = (result + dp[i][n]) % 1000000000;
//	}
//
//	cout << result % 1000000000 << "\n";
//
//	return 0;
//}
