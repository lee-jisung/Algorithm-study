#include <iostream>

using namespace std;

int r, c, w, sum;
int pascalTriangle[31][31];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c >> w;

	for (int i = 1; i <= 30; i++) pascalTriangle[i][1] = pascalTriangle[i][i] = 1;
	for (int i = 3; i <= 30; i++) {
		for (int j = 2; j < i; j++) {
			pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
		}
	}

	for (int i = r; i < r + w; i++) {
		for (int j = c; j <= c + (i - r); j++) {
			sum += pascalTriangle[i][j];
		}
	}

	cout << sum << "\n";

	return 0;
}
