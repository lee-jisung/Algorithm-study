#include <iostream>
#include <algorithm>
#include <stack>

#define SIZE 100001

using namespace std;

int n, idx, cnt = 1;
int arr[SIZE], seq[SIZE];
pair<int, int> res[SIZE];
stack<int> s;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	seq[idx] = arr[0];
	res[0] = { idx, arr[0] };

	for (int i = 1; i < n; i++) {
		if (seq[idx] < arr[i]) {
			seq[++idx] = arr[i];
			res[i] = { idx, arr[i] };
			cnt++;
		}
		else {
			int idx2 = lower_bound(seq, seq + idx, arr[i]) - seq;
			seq[idx2] = arr[i];
			res[i] = { idx2, arr[i] };
		}
	}

	cout << cnt << "\n";

	for (int i = n - 1; i >= 0; i--) {
		if (res[i].first == idx) {
			s.push(res[i].second);
			idx--;
		}
	}

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";

	return 0;
}
