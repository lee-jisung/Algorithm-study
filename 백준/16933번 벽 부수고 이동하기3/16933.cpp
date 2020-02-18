#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 1001
#define INF 987654321

using namespace std;

struct node {
	int r;
	int c;
	int cnt;
	int block;
	bool day;
};

int n, m, k, result;
int map[SIZE][SIZE];
bool cache[SIZE][SIZE][11];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= m;
}

// 이전 문제들 처럼 칸을 넘어 갈 때마다 block을 증가시키는 것이 아니라
// cnt라는 변수를 두고 칸을 세고
// block은 벽을 깻을 때 +1을 해주고 깨지 않고 갔을 때는 그냥 block을 push
// 그래서 block을 k개 깬 여부를 확인하는 동시에 cnt로 칸의 개수를 증가시켜야함

int main(void) {

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%1d", &map[i][j]);

	queue<node> q;
	q.push({ 1, 1, 1, 0, true });
	cache[1][1][0] = true;
	result = -1;

	while (!q.empty()) {

		int r = q.front().r, c = q.front().c;
		int cnt = q.front().cnt;
		int block = q.front().block;
		bool day = q.front().day;

		q.pop();
		if (r == n && c == m) {
			result = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			
			int nr = r + dx[i], nc = c + dy[i];

			if (isRange(nr, nc)) {
				if (map[nr][nc] == 1 && !cache[nr][nc][block + 1] && block < k ) {
					if (day) {
						q.push({ nr, nc, cnt + 1, block + 1, !day });
						cache[nr][nc][block + 1] = true;
					}
					else {
						q.push({ r, c, cnt + 1, block , !day });
					}
				}
				else if (map[nr][nc] == 0 && !cache[nr][nc][block]) {
					cache[nr][nc][block] = true;
					q.push({ nr, nc, cnt + 1, block, !day });
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}
