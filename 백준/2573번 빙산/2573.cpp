#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 301
#define INF 987654321

using namespace std;

struct node {
	int r;
	int c;
};

int n, m, result, island, ck; 
int map[SIZE][SIZE], melting[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void copy_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = melting[i][j];
		}
	}
}

void bfs(int r, int c) {

	queue<node> q;
	q.push({ r, c });
	isVisit[r][c] = true;

	while (!q.empty()) {

		int rr = q.front().r;
		int cc = q.front().c;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dx[i];
			int nc = cc + dy[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (!isVisit[nr][nc] && map[nr][nc]) {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
			}
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		
		island = 0;
		ck = 0;
		memset(isVisit, false, sizeof(isVisit));

		for (int i = 0; i < n; i++) {
			for (int j = 0;j < m; j++) {
				if (map[i][j] && !isVisit[i][j]) {
					bfs(i, j);
					island++;
				}
				else ck++;
			}
		}
		if (island >= 2) {
			break;
		}
		if (ck == n * m) {
			result = 0;
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int ni = i + dx[k];
						int nj = j + dy[k];
						if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
						if (map[ni][nj] == 0) cnt++;
					}
					melting[i][j] = map[i][j] - cnt;
					if (melting[i][j] < 0) melting[i][j] = 0;
				}
				else
					melting[i][j] = 0;
			}
		}

		copy_map();
		result++;
	}

	cout << result << "\n";
	return 0;
}
