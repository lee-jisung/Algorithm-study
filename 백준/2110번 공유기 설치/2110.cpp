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


#define SIZE 200001
#define INF 987654321

/*
   1. 공유기의 거리를 줄이거나 늘려가면서
   1-1. 설치할 수 있는 집의 개수가 c개 이상--> 길이 = mid / mid + 1 ~ end 재탐색
   1-2. 설치 가능한 집 개수가 c개 미만 -> 길이가 너무 긺 --> st ~ mid-1 재탐색
*/

using namespace std;

int n, c, house[SIZE], res;

void binary_search(int st, int end) {
	if (st > end) return;
	int mid = (st + end) / 2;
	int cnt = 1, pre = house[0];
	for (int i = 1; i < n; i++) {
		if (pre + mid <= house[i]) {
			cnt++;
			pre = house[i];
		}
	}
	if (cnt < c) {
		binary_search(st, mid-1);
	}
	else if (cnt >= c) {
		res = mid;
		binary_search(mid +1, end);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> house[i];
	sort(house, house + n);

	binary_search(0, INT_MAX);

	cout << res << "\n";
	return 0;
}
