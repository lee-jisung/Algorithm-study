# 9376번 탈옥 문제 

## 문제 설명 
- 죄수1,2 & 외부 총 3명이 문을 여는 경우를 BFS로 탐색
-  단, 외부인은 벽의 바깥에서 출발을 해야 하므로 map을 가로세로 양쪽 모두 +1씩 확장시킴
-  3 경우를 모두 구한 뒤 더함. 이 때 겹치는 곳이 문일 경우 -2를 해줌
-  3경우를 모두 더하면 각 지점이 3명이 각각 문을 열고 나와서 마주치는 지점이며
-  이 때 최솟값이 외부인이 문을 최소로 열어 죄수를 모두 탈출 시키는 경우와 같음
-  즉, 더한 값 중에서 최솟값을 찾으면 됨

## BFS에서 Deque 사용
- #을 연 경우를 deque의 뒤쪽으로 보내서
- 가중치가 적은 경우를 먼저 모두 다 처리 한 후에
- 그다음에 +1인 경우를 모두 싹 처리하게 하는 것
- 즉, 문을 1개 연 경우 갈 수 있는 곳 모두 처리 --> 2개 연 경우 싹 처리의 단계로 볼 수 있음
``` 
void bfs(int r, int c, int no) {

	deque<node> dq;
	dq.push_back({ r, c });
	dist[r][c][no] = 0;

	while (!dq.empty()) {

		int rr = dq.front().r;
		int cc = dq.front().c;
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dx[i];
			int nc = cc + dy[i];

			if (isRange(nr, nc) && map[nr][nc] != '*' && dist[nr][nc][no] < 0) {
				if (map[nr][nc] == '#') {
					dist[nr][nc][no] = dist[rr][cc][no] + 1;
					dq.push_back({ nr, nc });
				}
				else if (map[nr][nc] == '.') {
					dist[nr][nc][no] = dist[rr][cc][no];
					dq.push_front({ nr, nc });
				}
			}
		}
	}
}

int main(void) {

	cin >> tc;
	while (tc--) {

		memset(dist, -1, sizeof(dist));
		memset(res, 0, sizeof(res));
		prisoner.clear();
		result = INF;

		cin >> n >> m;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0; j < m + 2; j++) {
				if (i == 0 || j == 0 || i == n + 1 || j == m + 1) map[i][j] = '.';
				else scanf(" %1c", &map[i][j]);
				if (map[i][j] == '$') {
					map[i][j] = '.';
					prisoner.push_back({ i, j });
				}
			}
		}

		bfs(0, 0, 0);
		for (int i = 0; i < prisoner.size(); i++)
			bfs(prisoner[i].r, prisoner[i].c, i + 1);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (int k = 0; k < 3; k++) {
					if (map[i][j] != '*')
						res[i][j] += dist[i][j][k];
				}
				if (map[i][j] == '#') res[i][j] -= 2;
				if (map[i][j] != '*')
					result = min(result, res[i][j]);
			}
		}
		cout << result << "\n";
	}
	return 0;
}

``` 
