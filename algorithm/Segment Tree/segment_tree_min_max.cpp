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
#define INF 1e9 + 1

/*
   tree -> pair형태로 만들어 first는 min값, second는 max값을 갖도록 초기화
   구간합을 구하는 것이 아니기 때문에 각 구간에 해당하는 최소값 또는 최댓값을 갖도록 만드는 것
  
   min_val, max_val은 각 구간 (left ~ right)에 해당하는 node의 최소값 및 최댓값을 return
   (범위를 넘어가는 경우는 INF or -1을 return해줌)
   
*/

using namespace std;

int n, m;

long long initMin(vector<long long> &arr, vector<pair<long long, long long> > &tree, int node, int st, int end) {
	if (st == end) return tree[node].first = arr[st];
	int mid = (st + end) / 2;
	return tree[node].first = min(initMin(arr, tree, node * 2, st, mid), initMin(arr, tree, node * 2 + 1, mid + 1, end));
}

long long initMax(vector<long long>& arr, vector<pair<long long, long long> >& tree, int node, int st, int end) {
	if (st == end) return tree[node].second = arr[st];
	int mid = (st + end) / 2;
	return tree[node].second = max(initMax(arr, tree, node * 2, st, mid), initMax(arr, tree, node * 2 + 1, mid + 1, end));
}

long long min_val(vector<pair<long long, long long> >& tree, int node, int st, int end, int left, int right) {
	if (right < st || left > end) return INF;
	if (left <= st && end <= right) return tree[node].first;
	int mid = (st + end) / 2;
	long long leftMin = min_val(tree, node * 2, st, mid, left, right);
	long long rightMin = min_val(tree, node * 2 + 1, mid + 1, end, left, right);
	return min(leftMin, rightMin);
}

long long max_val(vector<pair<long long, long long> >& tree, int node, int st, int end, int left, int right) {
	if (right < st || left > end) return -1;
	if (left <= st && end <= right) return tree[node].second;
	int mid = (st + end) / 2;
	long long leftMax = max_val(tree, node * 2, st, mid, left, right);
	long long rightMax = max_val(tree, node * 2 + 1, mid + 1, end, left, right);
	return max(leftMax, rightMax);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int h = (int)ceil(log2(n));
	int treeSize = 1 << (h + 1);

	vector<long long> arr(n);
	vector<pair<long long, long long >> tree(treeSize);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	initMin(arr, tree, 1, 0, n - 1);
	initMax(arr, tree, 1, 0, n - 1);

	for (int i = 0;i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << min_val(tree, 1, 0, n - 1, a - 1, b - 1) << " " << max_val(tree, 1, 0, n - 1, a - 1, b - 1) << "\n";;
	}

	return 0;
}
