#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1000001
#define INF 987654321

using namespace std;

/*
   lower_bound(v.begin(), v.end(), key) -> key값 이상인 수가 처음 등장하는 위치
*/

int n, m, max_len; 
long long res;
vector<int> tree;

void binary_search(long long start, long long end) {
	if (start > end) return;
	long long mid = (start + end) / 2;
	long long sum = 0;
	int idx = lower_bound(tree.begin(), tree.end(), mid) - tree.begin();
	for (int i = idx; i < tree.size(); i++) {
		sum += tree[i] - mid;
	}
	if (sum >= m) {
		res = mid;
		binary_search(mid + 1, end);
	}
	else if (sum < m) {
		binary_search(start, mid - 1);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		tree.push_back(temp);
	}

	sort(tree.begin(), tree.end());
	max_len = tree[tree.size() - 1];
	// 시간초과 난 방법
	/*while (1) {
		sum = 0;
		idx = lower_bound(tree.begin(), tree.end(), max_len) - tree.begin();
		for (int i = idx; i < tree.size(); i++) {
			sum += tree[i] - max_len;
		}
		if (sum >= m) break;
		max_len--;
	}*/
	binary_search(0, max_len);
	cout << res << " ";

	return 0;
}
