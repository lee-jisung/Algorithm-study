#include <iostream>
#include <algorithm>

using namespace std;

int n;
int dp[1000001], trace[1000001];

void print(int x) {
	if (trace[x] == 1) {
		cout << trace[x] << " ";
		return;
	}
	cout << trace[x] << " ";
	print(trace[x]);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	trace[2] = 1; trace[3] = 1;
	dp[2] = 1; dp[3] = 1;

	for (int i = 4; i <= n; i++) {
		int ck = 1;
		dp[i] = dp[i-1] + 1;
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				ck = 2;
			}
		}
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				ck = 3;
			}
		}
		if (ck == 1) trace[i] = i - 1;
		else if (ck == 2) trace[i] = i / 2;
		else trace[i] = i / 3;
	}

	cout << dp[n] << "\n";
	cout << n << " ";
	print(n);

	return 0;
}
