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
#define INF 1e9

using namespace std;

int n, m, k;
const int Mod = 1e9 + 7;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int st, int end) {
	if (st == end) return tree[node] = arr[st];
	int mid = (st + end) / 2;
	return tree[node] = (init(arr, tree, node * 2, st, mid) * init(arr, tree, node * 2 + 1, mid + 1, end)) % Mod;
}

// leaf node의 값을 바꿔주고 그 위의 구간 node들을 새로 계산해서 적용
long long update(vector<long long>& tree, int index, int node, int st, int end, long long chg) {
	if (index < st || index > end) return tree[node] % Mod;
	if (st == end) return tree[node] = chg;

	int mid = (st + end) / 2;
	return tree[node] = (update(tree, index, node * 2, st, mid, chg) * update(tree, index, node * 2 + 1, mid + 1, end, chg)) % Mod;
}

long long multi(vector<long long>& tree, int node, int st, int end, int left, int right) {
	if (right < st || left > end) return 1;
	if (left <= st && end <= right) return tree[node];
	int mid = (st + end) / 2;
	return (multi(tree, node * 2, st, mid, left, right) * multi(tree, node * 2 + 1, mid + 1, end, left, right)) % Mod;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	int h = (int)ceil(log2(n));
	int treeSize = 1 << (h + 1);

	vector<long long> arr(n);
	vector<long long> tree(treeSize);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);

	for (int i = 0; i < m + k; i++) {

		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			cin >> b >> c;
			arr[b - 1] = c;
			update(tree, b - 1, 1, 0, n - 1, c);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << multi(tree, 1, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}
