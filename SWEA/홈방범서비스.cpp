#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int TC;
int n, m, result;
int city[21][21];
bool isVisit[21][21];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;

int bfs(){ 
	int homeCnt = 0;
	int size = q.size();
	while (size--) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (city[r][c]) homeCnt++;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n || isVisit[nr][nc]) continue;
			q.push({ nr, nc });
			isVisit[nr][nc] = true;
		}
	}
	return homeCnt;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		result = 0;
		vector<pair<int, int>> homes;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> city[i][j];
			}
		}

		// queue에 처음 시작 위치를 넣고
		// k번째 일 때 마다 queue size만큼 한번씩 돌면서 큐에 들어가있는 위치에 집의 개수를 세고,
		// 다음 확장될 영역의 위치를 큐에 넣어줌 => bfs()에서 함
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				memset(isVisit, false, sizeof(isVisit));
				int cost = 0, homeCnt = 0, revenue = 0;
				while (!q.empty()) q.pop();
				q.push({ i, j });
				isVisit[i][j] = true;
				// k=> n+1크기만큼 해줘야 함
				for (int k = 1; k <= n + 1; k++) {
					cost = (k * k) + ((k - 1) * (k - 1));
					homeCnt += bfs();
					revenue = homeCnt * m - cost;
					if (revenue >= 0) // 손해가 아닌 경우에 집의 최대 개수 찾기
						result = max(result, homeCnt);
				}
			}
		}
		cout << "#" << tc << " " << result << "\n";
	}
	return 0;
}
