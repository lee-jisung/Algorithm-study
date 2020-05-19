#include <iostream>
#include <cstring>
#include <algorithm>

#define SIZE 21

using namespace std;

int n, result;
int dp[SIZE][101];
int L[SIZE], J[SIZE];

/*
   dp -> 인사할 사람, 인사하지 않고 지나칠 사람 나눔
   인사할 사람-> dp[i][en] = en - L[i], J[i]를 해주고
   인사하지 않을 사람은 i+1번째로 넘어감
  
*/

int DP(int pos, int en) {

	if (pos == n) return 0;

	if (dp[pos][en]) return dp[pos][en];

	int& ans = dp[pos][en];

	if (en - L[pos] > 0)
		ans = DP(pos + 1, en - L[pos]) + J[pos];
	int temp = DP(pos + 1, en);
	return ans = max(ans, temp);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> L[i];
	for (int i = 0; i < n; i++)
		cin >> J[i];

	result = DP(0, 100);

	cout << result << "\n";
	return 0;
}
