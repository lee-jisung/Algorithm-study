#include <iostream>

#define SIZE 100001

using namespace std;

int n, m;
int arr[SIZE], tree[SIZE];

long long sum(int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(int i, int val) {
	while (i <= n) {
		tree[i] += val;
		i += (i & -i);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum(b) - sum(a - 1) << "\n";
	}

	return 0;
}
