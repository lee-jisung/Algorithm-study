#include <iostream>

using namespace std;

int n, st;
bool swt[101];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <=n; i++) cin >> swt[i];
	cin >> st;
	for (int i = 0; i < st; i++) {
		int a, b; cin >> a >> b;
		if (a == 1) {
			for (int j = b; j <= n; j += b) swt[j] = !swt[j];
		}
		else {
			swt[b] = !swt[b];
			for (int p = b - 1, q = b + 1; (p >= 1 && q <= n && swt[p] == swt[q]); p--, q++) {
				swt[p] = !swt[p];
				swt[q] = !swt[q];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (swt[i]) cout << 1 << " ";
		else cout << 0 << " ";
		if (i % 20 == 0) cout << "\n";
	}
	cout << "\n";

	return 0;
}
