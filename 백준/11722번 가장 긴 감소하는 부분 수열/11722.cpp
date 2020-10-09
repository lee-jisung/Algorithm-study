#include <iostream>
#include <algorithm>

using namespace std;

int n, result;
int arr[1001], dp[1001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		result = max(result, dp[i]);
	}

	cout << result << "\n";
	return 0;
}
