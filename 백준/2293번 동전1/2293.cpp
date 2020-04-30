#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 10001
#define INF 987654321

/*
   d[j] => j원을 만드는 경우의 수

   d[j] += d[j-a[i]]  ==> j원을 만드는 방법 중 하나는 j-a[i]원에서 a[i]원을 더한 경우
   
   d[0] = 1 

   d[5] = dp[5-1] + d[5-2] + d[5-5] ==> 4원에서 1원쓴 경우 + 3원에서 2원 쓴 경우 + 0원에서 5원쓴 경우
   이런식으로 1원씩 늘려가면서 이전에 쓴 돈에서 현재 가지고 있는 돈의 가치를 더했을 때 가능한 경우를 모두 더해주면됨
*/

using namespace std;

int n, k;
int dp[SIZE], a[101];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++) { // 각 동전을 가지고서
		for (int j = 1; j <= k; j++) { // j원을 만드는 경우의 수를 하나씩 전부 구해줌
			if (j - a[i] >= 0) {
				dp[j] += dp[j - a[i]];
			}
		}
	}

	cout << dp[k] << "\n";

	return 0;
}
