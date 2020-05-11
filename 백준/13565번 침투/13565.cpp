#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define SIZE 1000
#define INF 1e9

using namespace std;

/*
   board의 위아래를 +1씩 확장하여 bfs 탐색
*/

int board[SIZE+2][SIZE];
bool isVisit[SIZE+2][SIZE];
int n, m;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

bool bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 1 });
	isVisit[0][1] = true;
	
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (r == m + 1) {
			return true;
		}

		for (int i = 0; i < 4;i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 1 || nr > m + 1 || nc > n) continue;
			if (!isVisit[nr][nc] && !board[nr][nc]) {
				isVisit[nr][nc] = true;
				q.push({ nr, nc });
			}
		}
	}
	return false;
}

int main(void) {

	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	if (bfs()) {
		cout << "YES\n";
	}
	else cout << "NO\n";

	return 0;
}
