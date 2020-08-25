#include <iostream>

using namespace std;

int t, n;
long long koong[68];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	koong[0] = koong[1] = 1;
	koong[2] = 2;
	koong[3] = 4;

	for (int i = 4; i <= 67; i++)
		koong[i] = koong[i - 1] + koong[i - 2] + koong[i - 3] + koong[i - 4];

	cin >> t;
	while (t--) {
		cin >> n;
		cout << koong[n] << "\n";
	}

	return 0;
}
