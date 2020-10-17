#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, result;
int board[11][11], flowers[11][11];

bool isPut(int r, int c) {
	if (flowers[r][c] || flowers[r + 1][c] || flowers[r - 1][c] || flowers[r][c + 1] || flowers[r][c - 1]) return false;
	return true;
}

void putFlower(int no) {
	if (no == 3) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (flowers[i][j]) sum += board[i][j];
		result = min(result, sum);
		return;
	}

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (isPut(i, j)) {
				flowers[i][j] = flowers[i + 1][j] = flowers[i - 1][j] = flowers[i][j + 1] = flowers[i][j - 1] = 1;
				putFlower(no + 1);
				flowers[i][j] = flowers[i + 1][j] = flowers[i - 1][j] = flowers[i][j + 1] = flowers[i][j - 1] = 0;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	result = INF;

	putFlower(0);

	cout << result << "\n";

	return 0;
}
