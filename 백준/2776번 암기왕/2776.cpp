#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/*
   암기한 숫자 입력받고 정렬
   확인할 숫자 하나씩 이분탐색
*/

int T;
int n, m, target;
bool isFind;
vector<int> diary1;

void binary_search(int start, int end) {
	if (start > end) return;
	if (isFind) return;

	int mid = (start + end) / 2;
	if (target == diary1[mid]) {
		isFind = true;
		return;
	}
	else if (target < diary1[mid]) {
		binary_search(start, mid - 1);
	}
	else {
		binary_search(mid + 1, end);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {

		diary1.clear();
		vector<int> result;

		cin >> n;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			diary1.push_back(num);
		}
		sort(diary1.begin(), diary1.end());
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> target;
			isFind = false;
			binary_search(0, n-1); // 범위를 n-1로해야 맞음
			if (isFind) result.push_back(1);
			else result.push_back(0);
		}
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << "\n";
	}

	return 0;
}
