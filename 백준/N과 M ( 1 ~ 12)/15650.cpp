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

int n, m, a[SIZE];
bool cache[SIZE];

void solve(int k) {

	if (k == m) {
		bool asc = true;
		for (int i = 0; i < m-1; i++) {
			if (a[i] > a[i + 1]) asc = false;
		}
		if (asc) {
			for (int i = 0; i < m; i++)
				cout << a[i] + 1 << " ";
			cout << "\n";
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!cache[i]) {
			a[k] = i;
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

	solve(0);

	return 0;
}
