#include <iostream>

using namespace std;

int n;
int dp[1000001], trace[1000001];

int main(void) {


	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	dp[1] = 0;
	trace[1] = -1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);

		if (dp[i] == dp[i - 1] + 1) trace[i] = i - 1;
		else if (i % 2 == 0 && dp[i] == dp[i / 2] + 1) trace[i] = i / 2;
		else if (i % 3 == 0 && dp[i] == dp[i / 3] + 1) trace[i] = i / 3;
	}

	cout << dp[n] << "\n";

	int idx = n;
	cout << idx << " ";

	while (trace[idx] != -1) {
		idx = trace[idx];
		cout << idx << " ";
	}
	return 0;
}
