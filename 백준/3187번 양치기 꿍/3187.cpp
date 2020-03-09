#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 250
#define INF 987654321

using namespace std;

int n, m, sheep, wolves; 
char map[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

void bfs(int r, int c) {

	int s = 0, w = 0;
	queue<pair<int, int > > q;
	q.push({ r, c });
	isVisit[r][c] = true;

	while (!q.empty()) {

		int rr = q.front().first;
		int cc = q.front().second;
		q.pop();

		if (map[rr][cc] == 'k') s++;
		if (map[rr][cc] == 'v') w++;

		for (int i = 0; i < 4; i++) {
			int nr = rr + dx[i];
			int nc = cc + dy[i];

			if (isRange(nr, nc) && !isVisit[nr][nc] && map[nr][nc] != '#') {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
			}
		}
	}
	if (s > w) sheep += s;
	else wolves += w;
}

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '#' && !isVisit[i][j]) {
				bfs(i, j);
			}
		}
	}

	cout << sheep << " " << wolves << "\n";
	return 0;
}
