#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

/*
   정규분포 => 가운데부터 큰 숫자를 넣고, 양 옆에 차례대로 숫자들을 분포시킴
*/

int T;
int level;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {

		level = 1e9;
		priority_queue<int, vector<int>, greater<int>> pq;
		int n, res[10001];
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num; cin >> num;
			pq.push(num);
		}

		int p = 0, q = n - 1;
		for (int i = 0; i < n / 2; i++) {
			res[p++] = pq.top(); pq.pop();
			res[q--] = pq.top(); pq.pop();
		}

		if (!pq.empty()) res[p] = pq.top();

		int tmp = 0;
		for (int i = 0; i < n-1; i++) {
			tmp = max(tmp, abs(res[i] - res[i + 1]));
		}

		tmp = max(tmp, abs(res[0] - res[n - 1]));
		level = min(tmp, level);

		cout << level << "\n";
	}

	return 0;
}
