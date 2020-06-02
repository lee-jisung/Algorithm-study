#include <iostream>

using namespace std;

/*
   0,0에서 출발해서 사과를 전부 수확하여 4,4로 도착하는 경우의수를 구하면 됨
*/

int result, k;
bool apple[5][5], rock[5][5];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

bool ck() {
	for (int i = 0; i < 5; i++)
		for (int j = 0;j < 5; j++)
			if (!rock[i][j] && !apple[i][j]) return false;
	return true;
}

void dfs(int r, int c) {

	if (r == 4 && c == 4) {
		if (ck())
			result++;
		return;
	}

	for (int i = 0; i < 4; i++) {

		int nr = r + dr[i], nc = c + dc[i];

		if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5 || apple[nr][nc]) continue;
		apple[nr][nc] = true;
		dfs(nr, nc);
		apple[nr][nc] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		apple[r-1][c-1] = true;
	}

	apple[0][0] = true;
	dfs(0, 0);

	cout << result << "\n";

	return 0;
}
