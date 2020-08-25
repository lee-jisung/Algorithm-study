#include <iostream>
#include <algorithm>

using namespace std;

/* 
   D[i] = i번째 항을 마지막으로 사용하는 수열의 합 중 최댓값
   D[k] = max(0, D[k-1]) + A[k];
*/

int n;
int arr[100001], dp[100001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(0, dp[i - 1]) + arr[i];
	}

	cout << *max_element(dp + 1, dp + n + 1);

	return 0;
}
