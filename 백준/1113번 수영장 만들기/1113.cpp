#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

/*
   water => 수영장 벽 최대 높이 - 각칸의 높이 값으로 초기화
   maxH ~ minH 까지 각 높이를 한 층으로 생각해서
   해당 높이에서 상하좌우 칸 중 한칸이라도 현재칸의 벽 + 물높이보다 낮은 칸이 있으면 현재칸의 높이인 물을 제거해야함
   => 해당 칸을 기준으로 bfs를 돌려서 같은 높이의 물이 있는 곳은 전부 -1 해주기
*/

int n, m, result;
int maxH, minH;
int pool[51][51], water[51][51];
bool isVisit[51][51];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs(int y, int x, int height) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	isVisit[y][x] = true;
	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		water[r][c]--;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr == 0 || nc == 0 || nr == n - 1 || nc == m - 1 || isVisit[nr][nc]) continue;
			if (water[nr][nc] + pool[nr][nc] == height && water[nr][nc] > 0) {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	minH = 10;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			pool[i][j] = s[j] - '0';
			if (minH > pool[i][j]) minH = pool[i][j];
			if (maxH < pool[i][j]) maxH = pool[i][j];
		}
	}

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			water[i][j] = maxH - pool[i][j];
		}
	}

	for (int h = maxH; h > minH; h--) {
		memset(isVisit, false, sizeof(isVisit));
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (!water[i][j] || isVisit[i][j]) continue;
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (water[nr][nc] + pool[nr][nc] < water[i][j] + pool[i][j]) {
						bfs(i, j, h);
						break;
					}
				}
			}
		}
	}

	for (int i = 1;i < n - 1; i++)
		for (int j = 1; j < m - 1; j++)
			result += water[i][j];
	cout << result << "\n";

	return 0;
}
