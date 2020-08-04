#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>

using namespace std;

/*
   방을 새로 켤 때마다 방문을 초기화해서
   다시 새로운 방을 탐색할 수 있게 만듦
*/

int n, m, result;
bool room[101][101], isVisit[101][101];
vector<pair<int, int>> swt[101][101];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void init() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			isVisit[i][j] = false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> y >> x >> a >> b;
		swt[y][x].push_back({ a, b });
	}

	queue<pair<int, int>> q;
	q.push({ 1, 1});
	room[1][1] = true;
	isVisit[1][1] = true;

	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		bool ck = false;
		q.pop();

		for (int i = 0; i < swt[r][c].size(); i++) {
			int nr = swt[r][c][i].first;
			int nc = swt[r][c][i].second;
			if (!room[nr][nc]) {
				ck = true;
				room[nr][nc] = true;
			}
		}

		if (ck) init(); 

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
			if (room[nr][nc] && !isVisit[nr][nc]) {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;

			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (room[i][j]) result++;
	cout << result << "\n";

	return 0;
}
