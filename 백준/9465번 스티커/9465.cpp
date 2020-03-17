#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100001
#define INF 987654321

using namespace std;

int tc, n, m; 
int dp[2][SIZE], card[2][SIZE];
/*
   
   50  10  100  20  40
   30  50   70  10  60

   --> 50을 선택했을 때 2열 50 or 70 고르는 경우
   --> 30을 선택했을 때 1열 10 or 100 고르는 경우 의 규칙

   반대로 생각했을 때 dp[0][3] ==> 100을 골랐을 때 왼쪽 하단에 30 과 50 중 하나를 고르는 경우임

   ==> dp[0][n] = max(dp[1][n-1], dp[1][n-2]) +arr[0][n]

   --> 단 구현은 반대로 --> dp[0][i] = max(dp[1][i-1], dp[1][i-2]) + arr[0][i]
                            dp[1][i] = max(dp[0][i-1], dp[0][i-2]) = arr[1][i]
  
*/

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1;j <= n; j++) {
                cin >> card[i][j];
            }
        }
        dp[0][1] = card[0][1];
        dp[1][1] = card[1][1];

        for (int i = 2;i <= n; i++) {
            
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + card[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + card[1][i];

        }
        cout << max(dp[0][n], dp[1][n]) << "\n";

    }

	return 0;
}
