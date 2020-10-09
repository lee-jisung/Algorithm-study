#include <iostream>
#include <algorithm>

using namespace std;

/*
   dp[i][j] = v => i번째 item 순서에서 가방 무게가 j일 때 최고 가치는 v
   dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]) => 현재 아이템 선택 o vs 선택 x

	선택 x => 이전 아이템 선택했을 때 가방 가치
	선택 o => 현재 가방 무게에서 아이템 무게를 뺀 가방의 가치 + 현재 아이템 가치

*/

int n, k;
int weight[101], value[101];
int dp[101][100001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= weight[i]) {// 가방 무게가 아이템 무게보다 클 때,
				// 이전 아이템까지 선택한 가치, 현재 아이템 가치 + (현재아이템 무게 뺀 상태의 가방 가치) 중 max값
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
			else // 가방무게보다 물건 무게가 많이나가면 이전 아이템 선택한 가치를 그냥 넣음
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k] << "\n";

	return 0;
}
