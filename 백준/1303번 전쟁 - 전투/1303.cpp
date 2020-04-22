#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

int n, m, sumB, sumW; 
char board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int bfs(int R, int C, char sol) {
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ R, C });
	isVisit[R][C] = true;

	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4;i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
			if (!isVisit[nr][nc] && board[nr][nc] == sol) {
				cnt++;
				isVisit[nr][nc] = true;
				q.push({ nr, nc });
			}
		}
	}
	return cnt;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		string temp; cin >> temp;
		for (int j = 0;j < n; j++) {
			board[i][j] = temp[j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisit[i][j]) {
				int cnt = bfs(i, j, board[i][j]);
				if (board[i][j] == 'B') sumB += (cnt * cnt);
				else sumW += (cnt * cnt);
			}
		}
	}

	cout << sumW << " " << sumB << "\n";

	return 0;
}
