#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
long long card[1001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> card[i];

	for (int i = 0; i < m; i++) {
		sort(card, card + n);
		long long sum = card[0] + card[1];
		card[0] = card[1] = sum;
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) sum += card[i];

	cout << sum << "\n";

	return 0;
}
