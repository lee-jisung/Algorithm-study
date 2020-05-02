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
#define INF 987654321

using namespace std;
/*
 initialize segment tree
 a = value array
 tree = segment tree
 node = 몇 번째 노드인지 (st ~ end) 구간 합 저장 노드 or leaf 노드
*/
long long init(vector<long long>& a, vector<long long>& tree, int node, int st, int end) {
	if (st == end) // node가 leaf인 경우
		return tree[node] = a[st];
	else // node의 왼쪽자식 + 오른쪽 자식의 합을 구해서 해당 node에 저장
		return tree[node] = init(a, tree, node * 2, st, (st + end) / 2) + init(a, tree, node * 2 + 1, (st + end) / 2, end);
}

// left ~ right 까지의 구간 합 구하기
long long sum(vector<long long>& tree, int node, int st, int end, int left, int right) {

	// left,right이 st, end와 겹치지 않는 경우
	if (left > end || right < st) { 
		return 0;
	}
	//left, right이 st~end 구간에 포함되는 경우
	if (left <= st && end <= right) {
		return tree[node];
	}
	// st, end가 left, right을 포함하거나 left, right과 st, end가 겹치는 경우 --> 재 탐색
	return sum(tree, node * 2, st, (st + end) / 2, left, right) + sum(tree, node * 2 + 1, (st + end) / 2, end, left, right);
}

// index번째 수 변경하기 --> 수를 변경하면 그 상위 노드들의 합이 모두 변경됨
void update(vector<long long>& tree, int node, int st, int end, int index, long long diff) {
	if (index < st || index > end) return;
	tree[node] = tree[node] + diff; // 변경된 수의 합 (+든 -든) 더해줌
	if (st != end) {
		update(tree, node * 2, st, (st + end) / 2, index, diff);
		update(tree, node * 2 + 1, (st + end) / 2, end, index, diff);
	}
}

int n, m;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; // n - 수의 개수

	int h = (int)ceil(log2(n));
	int treeSize = 1 << (h + 1);

	vector<long long> arr(n);
	vector<long long> tree(treeSize);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	init(arr, tree, 1, 0, n - 1);

	int a, b;
	cin >> a >> b;
	// a번째 수를 c로 바꾸는 경우
	long long diff = b - arr[a-1];
	arr[a - 1] = b;
	update(tree, 1, 0, n - 1, a - 1, diff);

	cin >> a >> b; // a번째 ~ b번째 구간의 합 구하기
	long long res = sum(tree, 1, 0, n - 1, a - 1, b - 1);

	return 0;
}
