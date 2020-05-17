#include <iostream>
#include <string>

using namespace std;

int board[5][5], result;
bool arr[1000000];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void dfs(int r, int c, string str) {
	if (str.length() == 6) {
		int tmp = stoi(str);
		if (!arr[tmp]) {
			arr[tmp] = true;
			result++;
		}
		return;
	}

	for (int i = 0; i < 4;i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5) continue;
		if (str.length() != 6) {
			dfs(nr, nc, str + to_string(board[nr][nc]));
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5;j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(i, j, to_string(board[i][j]));
		}
	}

	cout << result << "\n";

	return 0;

}
