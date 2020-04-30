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

using namespace std;

int n, k, result;
int dp[SIZE], coin[101];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= k; i++) dp[i] = INF;

	// coin[0] = 1이라면 1 ~ k까지는 1원짜리가 각각 J개씩 필요
	// coin[1] = 5면 j=5일때, dp[5] = 5였고, coin[1]이 들어가면 dp[0](=0) + 1이므로 1개가 필요한 값으로 바뀜
	//즉, 동전의 가치마다 사용된 갯수의 최솟값으로 갱신
	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] < INF)
		cout << dp[k] << "\n";
	else cout << -1 << "\n";

	return 0;
}
