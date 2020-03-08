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

int R, C, s, w;
int sheep, wolves;
char map[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

void bfs(int r, int c) {

	queue<pair<int, int > > q;
	q.push({ r, c });
	isVisit[r][c] = true;

	while (!q.empty()) {

		int rr = q.front().first;
		int cc = q.front().second;

		if (map[rr][cc] == 'v') w++;
		if (map[rr][cc] == 'o') s++;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dx[i];
			int nc = cc + dy[i];

			if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
			if (map[nr][nc] != '#' && !isVisit[nr][nc]) {
				isVisit[nr][nc] = true;
				q.push({ nr, nc });
			}
		}
	}
}

int main(void) {

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'o') sheep++;
			if (map[i][j] == 'v') wolves++;
		}
	}
	
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			s = w = 0;
			if (map[i][j] != '#' && !isVisit[i][j]) {
				bfs(i, j);
				if (s > w) wolves -= w;
				else sheep -= s;
			}
		}
	}

	cout << sheep << " " << wolves << "\n";

	return 0;
}
