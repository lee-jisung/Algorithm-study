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
	int cnt;
	int block;
};

int n, m, k, result;
int map[SIZE][SIZE];
bool cache[SIZE][SIZE][11];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= m;
}

// 칸 수를 세는 cnt
// 벽을 부순 수를 세는 block을 각각 두고
// 경우에 맞춰서 증가 시키는 방법
int main(void) {

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);

	result = -1;
	queue<node> q;
	q.push({ 1, 1, 1, 0 });
	cache[1][1][0] = true;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		int block = q.front().block;

		q.pop();

		if (r == n && c == m) {
			result = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {

			int nr = r + dx[i];
			int nc = c + dy[i];

			if (isRange(nr, nc)) {

				if (map[nr][nc] == 1 && block < k && !cache[nr][nc][block + 1]) {
					cache[nr][nc][block + 1] = true;
					q.push({ nr, nc, cnt + 1, block + 1 });
				}
				else if (map[nr][nc] == 0 && !cache[nr][nc][block]) {
					cache[nr][nc][block] = true;
					q.push({ nr, nc, cnt+ 1, block });
				}
			}
		}
	}
	cout << result << "\n";

	return 0;
}
