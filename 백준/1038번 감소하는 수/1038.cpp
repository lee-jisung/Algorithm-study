#include <iostream>
#include <queue>

using namespace std;

int n, idx;
queue<long long> q;
long long digit[1000001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		q.push(i);
		digit[i] = i;
	}

	idx = 10;
	while (idx <= n) {
		if (q.empty()) break;
		long long num = q.front();
		q.pop();
		int limit = num % 10;
		for (int i = 0; i < limit; i++) {
			q.push(num * 10 + i);
			digit[idx++] = num * 10 + i;
		}
	}

	if (n >= 1023 || (!digit[n] && n != 0)) cout << -1 << "\n";
	else cout << digit[n] << "\n";

	return 0;
}
