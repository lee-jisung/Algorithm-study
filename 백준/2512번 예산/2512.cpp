#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 10001
#define INF 987654321

/*
  할당해야 할 예산 총 합 <= 할당 가능 예산 => 할당해야할 예산 중 최대값으로 할당하면 됨
  할당해야 할 예산 총 합 > 할당 가능 예산 --> 총합이 할당가능한 예산을 넘어가지 않는 선에서 찾음 (binary_search)
*/

using namespace std;

int n, m, budget[SIZE], res, total;

void binary_search(int st, int end) {

	if (st > end) return;
	int mid = (st + end) / 2;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (mid >= budget[i]) sum += budget[i];
		else sum += mid;
	}
	if (sum > m) {
		binary_search(st, mid - 1);
	}
	else if (sum <= m) {
		res = mid;
		binary_search(mid + 1, end);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> budget[i];
		res = max(res, budget[i]);
		total += budget[i];
	}
	cin >> m;

	if (total <= m)
		cout << res << "\n";
	else {
		binary_search(0, m);
		cout << res << "\n";
	}
	return 0;
}
