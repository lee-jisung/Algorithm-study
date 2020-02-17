#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>

#define SIZE 1001
#define INF 987654321

using namespace std;

struct node {
	int r;
	int c;
	int block;  // block -> k로 주고 0이면 더이상 벽을 뿌술 수 없는 상태가 되면 됨
};

int n, m, k, result;
int map[SIZE][SIZE];
int cache[SIZE][SIZE][11];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= m;
}

int main(void) {

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);

	result = -1;
	queue<node> q;
	q.push({ 1, 1, k });
	cache[1][1][k] = 1;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int block = q.front().block;

		q.pop();

		if (r == n && c == m) {
			result = cache[r][c][block];
			break;
		}

		for (int i = 0; i < 4; i++) {

			int nr = r + dx[i];
			int nc = c + dy[i];

			if (isRange(nr, nc)) {
				// if (map[nr][nc] == 1 && block) << 이럴 경우 벽을 한번 부수고 방문했던 곳이지만 벽을 부술 수 있으면 다시 한번 방문을 하게 되므로
				// 여러번 재방문 하는 곳이 많아져 시간초과가 발생함 따라서 이전에 벽을 부쉈던 곳이 아닌 경우에만 방문하도록 아래 처럼조건 추가
				if (map[nr][nc] == 1 && block && cache[nr][nc][block-1] == 0) {
					cache[nr][nc][block - 1] = cache[r][c][block] + 1;
					q.push({ nr, nc, block - 1 });
				}
				else if (map[nr][nc] == 0 && cache[nr][nc][block] == 0) {
					cache[nr][nc][block] = cache[r][c][block] + 1;
					q.push({ nr, nc, block });
				}
			}
		}
	}
	cout << result << "\n";

	return 0;
}
