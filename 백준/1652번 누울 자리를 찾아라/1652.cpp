#include <iostream>
#include <string>

using namespace std;

int n, area;
char board[101][101];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '.') cnt++;
			else if (board[i][j] == 'X') {
				if (cnt >= 2) area++;
				cnt = 0;
			}
		}
		if (cnt >= 2) area++;
	}

	cout << area << " ";

	area = 0;
	for (int j = 0; j < n; j++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (board[i][j] == '.') cnt++;
			else if (board[i][j] == 'X') {
				if (cnt >= 2) area++;
				cnt = 0;
			}
		}
		if (cnt >= 2) area++;
	}
	cout << area << "\n";

	return 0;
}
