#include <iostream>

using namespace std;

int n, res;
int board[101][101];
bool ck = true, isVisit[10001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	res = n * (n * n + 1) / 2;


	for (int i = 0; i < n; i++) {
		int col = 0;
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (isVisit[board[i][j]]) ck = false;
			isVisit[board[i][j]] = true;
			col += board[i][j];
		}
		if (col != res) ck = false;
	}

	for (int i = 0; i < n; i++) {
		int row = 0;
		for (int j = 0; j < n; j++)
			row += board[j][i];
		if (row != res) {
			ck = false;
			break;
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (i == j) sum += board[i][j];

	if (sum != res) ck = false;
	sum = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
			if (i == j) sum += board[i][j];

	if (sum != res) ck = false;

	if (ck) cout << "TRUE\n";
	else cout << "FALSE\n";

	return 0;
}
