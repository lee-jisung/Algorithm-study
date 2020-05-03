#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 1e9+1

using namespace std;

int n, m; 

int init(vector<int>& arr, vector<int>& tree, int node, int st, int end) {
	if (st == end) return tree[node] = arr[st];
	int mid = (st + end) / 2;
	return tree[node] = min(init(arr, tree, node * 2, st, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

int findMin(vector<int>& tree, int node, int st, int end, int left, int right) {
	if (right < st || left > end) return INF;
	if (left <= st && end <= right) return tree[node];
	int mid = (st + end) / 2;
	return min(findMin(tree, node * 2, st, mid, left, right), findMin(tree, node * 2 + 1, mid + 1, end, left, right));
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int h = (int)ceil(log2(n));
	int treeSize = 1 << (h + 1);

	vector<int> arr(n), minTree(treeSize);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, minTree, 1, 0, n - 1);
	
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << findMin(minTree, 1, 0, n - 1, a - 1, b - 1) << "\n";
	}

	return 0;
}
