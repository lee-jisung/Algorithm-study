#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <limits.h>

#define SIZE 10001
#define INF 987654321

using namespace std;

int n, k;
long long lan[SIZE], cnt, res;

/*
   랜선길이 -> 이진탐색
*/

void binary_search(long long st, long long end) {
	if (st > end) return;
	long long mid = (st + end) / 2;
	cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += lan[i] / mid;
	}
	if (cnt < n) {
		binary_search(st, mid-1);
	}
	else if (cnt >= n) {
		res = mid;
		binary_search(mid + 1, end);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
	}
	
	binary_search(0, LONG_MAX);
	cout << res << "\n";

	return 0;
}
