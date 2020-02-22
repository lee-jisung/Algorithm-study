#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 8
#define INF 987654321

using namespace std;

int n, m, a[SIZE], res[SIZE];
bool cache[SIZE];

void solve(int k) {

	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!cache[i]) {
			res[k] = a[i];
			cache[i] = true;
			solve(k + 1);
			cache[i] = false;
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	solve(0);

	return 0;
}
