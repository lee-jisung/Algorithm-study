#include <iostream>
#include <algorithm>

using namespace std;

int n, result;
int t[16], p[16];

void counsil(int day, int sum) { 

	if (day >= n+1) {
		result = max(result, sum);
		return;
	}
	if (day + t[day] <= n+1)
		counsil(day + t[day], sum + p[day]);
	counsil(day + 1, sum);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	counsil(1, 0);

	cout << result << "\n";

	return 0;
}
