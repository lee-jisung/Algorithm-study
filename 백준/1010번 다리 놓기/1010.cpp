#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 31
#define INF 987654321

using namespace std;

int tc, n, m; 
int dp[SIZE][SIZE];

/*
   n - 2 , m - 3 일 때
   n 1번째에서 m 1번째를 연결해 놓았을 때
   나머지 n 1개에서 m을 고르는 경우는 dp[1][2] 
   n 1번째에서 2번째로 연결 --> 나머지 n 1개에서는 dp[1][1]

   그렇다면 dp[2][3] = d[1][2] + dp[1][1]이 되는 것 여기서 dp[1][1] = dp[2][2]와 같기때문에
   dp[2][3] = dp[2][2] + dp[1][2] 임

   n - 2, m - 4일 때
   n ->1, m->1 
   나머지 n 1개에서 m 3개 ==> dp[1][3]
   n->1, m->2 ==> dp[1][2]
   n->1, m->3 ==> dp[1][1]

   dp[2][4] = dp[1][1]+ dp[1][2] + dp[1][3] = dp[2][3] + dp [1][3]

*/

// dp[i][j] = dp[i][j-1] + dp[i-1][j-1];

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> tc;
	while (tc--) {
		cin >> n >> m;

		for (int i = 1; i <= m; i++) {
			dp[1][i] = i;
		}

		for (int i = 2; i <= n; i++) {
			for (int j = 2; j <= m; j++) {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
			}
		}

		cout << dp[n][m] << "\n";

	}

	return 0;
}
