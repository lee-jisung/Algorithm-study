#include <iostream>
#include <algorithm>

// dp[i] = (출발 지점 + 지름길 거리) vs (0에서 i까지의 거리)

using namespace std;

int n, d;
int load[12][3], dp[10001];

int main(void) {

	ios_base::sync_with_stdio(0);

	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> load[i][0] >> load[i][1] >> load[i][2];
	}

	for (int i = 1; i <= d;i++) {
		dp[i] = dp[i - 1] + 1;

		for (int j = 0; j < n; j++) {
			if (load[j][1] == i) {
				dp[i] = min(dp[i], dp[load[j][0]] + load[j][2]);
			}
		}
	}

	cout << dp[d] << "\n";

	return 0;
}
