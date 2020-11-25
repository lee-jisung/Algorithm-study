#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*
   Segment Tree
   x ~ y 번째 구간 구할 때 
     x > y => y ~ x
	 y > x => x ~ y
	구간으로 보고 구해야 함
*/

int n, q, height, treeSize;
vector<long long> arr, tree;

long long init(int node, int start, int end) {
	if (start == end)
		return tree[node] = arr[start];
	return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

long long sum(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(int node, int start, int end, int idx, long long diff) {
	if (idx < start || idx > end) return;
	tree[node] += diff;
	if (start != end) {
		update(node * 2, start, (start + end) / 2, idx, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, idx, diff);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	
	height = (int)ceil(log2(n));
	treeSize = 1 << (height + 1);

	arr.resize(n); tree.resize(treeSize);
	
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(1, 0, n - 1);

	while (q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		x--; y--;
		long long result;
		x > y ? result = sum(1, 0, n - 1, y, x) : result = sum(1, 0, n - 1, x, y);
		cout << result << "\n";

		long long diff = b - arr[a - 1];
		arr[a - 1] = b;
		update(1, 0, n - 1, a - 1, diff);
	}

	return 0;
}
