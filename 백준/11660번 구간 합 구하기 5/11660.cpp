#include <iostream>

#define SIZE 1025

using namespace std;

int n, m;
int arr[SIZE][SIZE], tree[SIZE][SIZE];

int sum(int y, int x) {
	int ans = 0;
	while (y > 0) {
		int i = x;
		while (i > 0) {
			ans += tree[y][i];
			i -= (i & -i);
		}
		y -= (y & -y);
	}
	return ans;
}

void update(int y, int x, int diff) {
	while (y <= n) {
		int i = x;
		while (i <= n) {
			tree[y][i] += diff;
			i += (i & -i);
		}
		y += (y & -y);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <=n; j++) {
			cin >> arr[i][j];
			update(i, j, arr[i][j]);
		}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << sum(y2, x2) - sum(y2, x1 - 1) - sum(y1 - 1, x2) + sum(y1-1, x1-1) << "\n";
	}

	return 0;
}
