#include <iostream>

using namespace std;

int n;
long long tile[81], squareRound[81];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	tile[1] = 1, tile[2] = 1;
	squareRound[1] = 4;

	for (int i = 3; i <= 80; i++) tile[i] = tile[i - 1] + tile[i - 2];

	for (int i = 2; i <= 80; i++) {
		squareRound[i] = squareRound[i - 1] + tile[i] * 2;
	}

	cout << squareRound[n] << "\n";

	return 0;
}
