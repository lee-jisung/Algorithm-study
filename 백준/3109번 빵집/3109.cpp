#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 10001
#define INF 987654321

using namespace std;

int R, C, result;
char board[SIZE][501];
bool isVisit[SIZE][501], ck;

void dfs(int r, int c) {

	isVisit[r][c] = true;

	if (c == C-1) {
		ck = true;
		result++;
		return;
	}

	for (int i = -1; i < 2; i++) {
		int nr = r + i;
		int nc = c + 1;

		if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;

		if (board[nr][nc] != 'x' && !isVisit[nr][nc]) {
			if (ck) return;
			dfs(nr, nc);
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string temp; cin >> temp;
		for (int j = 0;j < C; j++) {
			board[i][j] = temp[j];
		}
	}

	for (int i = 0; i < R; i++) {
		ck = false;
		dfs(i, 0);
	}

	cout << result << "\n";

	return 0;
}
