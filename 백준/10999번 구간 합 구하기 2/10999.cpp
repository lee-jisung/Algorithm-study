#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, m, k;
vector<long long> arr, tree, lazy;

long long init(int node, int st, int ed) {
	if (st == ed) return tree[node] = arr[st];
	else return tree[node] = init(node * 2, st, (st + ed) / 2) + init(node * 2 + 1, (st + ed) / 2 + 1, ed);
}

void update_lazy(int node, int st, int ed) {
	if (lazy[node] != 0) {
		tree[node] += ((ed - st + 1) * lazy[node]);
		if (st != ed) { // leaf가 아니면
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int node, int st, int ed, int left, int right, long long diff) {
	update_lazy(node, st, ed);
	if (left > ed || right < st) return;
	if (left <= st && ed <= right) {
		tree[node] += (ed - st + 1) * diff;
		if (st != ed) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	update_range(node * 2, st, (st + ed) / 2, left, right, diff);
	update_range(node * 2 + 1, (st + ed) / 2 + 1, ed, left, right, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(int node, int st, int ed, int left, int right) {
	update_lazy(node, st, ed);
	if (left > ed || right < st) return 0;
	if (left <= st && ed <= right)
		return tree[node];
	return sum(node * 2, st, (st + ed) / 2, left, right) + sum(node * 2 + 1, (st + ed) / 2 + 1, ed, left, right);
}

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	arr.resize(n);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1)) - 1;
	tree.resize(tree_size);
	lazy.resize(tree_size);

	for (int i = 0; i < n; i++) cin >> arr[i];
	init(1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c, d; cin >> b >> c >> d;
			update_range(1, 0, n - 1, b - 1, c - 1, d);
		}
		else {
			int b, c; cin >> b >> c;
			cout << sum(1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}
