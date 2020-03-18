#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 101
#define INF 987654321

/*
   방문처리 -> 3차원 visit[size][size][4] (동서남북 마다 처리)

   1. 현재 상태에서 1, 2, 3칸을 갈 수 있는 경우를 모두 찾아 큐에 넣어줌

   2. 현재 방향을 제외한 나머지에 대해서 방향전환을 안했었다면 방향전환을 해주고 큐에 넣어줌

*/

using namespace std;

struct node {
	int r;
	int c;
	int dir;
	int depth;
};

int n, m, result; 
int map[SIZE][SIZE];
bool isVisit[SIZE][SIZE][5];

int dx[5] = {0, 0, 0, 1, -1 };
int dy[5] = {0, 1, -1, 0, 0 };

node cur, goal;

bool isRange(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= m;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	cin >> cur.r >> cur.c >> cur.dir;
	cin >> goal.r >> goal.c >> goal.dir;

	queue<node> q;
	q.push(cur);
	isVisit[cur.r][cur.c][cur.dir] = true;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int dir = q.front().dir;
		int depth = q.front().depth;
		q.pop();

		if (r == goal.r && c == goal.c && dir == goal.dir) {
			result = depth;
			break;
		}

		// 1,2,3 칸 이동하는 경우
		for (int i = 1; i <= 3; i++) {

			int nr = r + dx[dir] * i;
			int nc = c + dy[dir] * i;

			// 방문 했던것은 continue로 스킵하면 맞고 
			if (isVisit[nr][nc][dir]) continue;

			// 주석처리 된 것 처럼 방문 처리를 같이 해주면 틀림 왜??????

			if (isRange(nr, nc) && !map[nr][nc] /*&& !isVisit[nr][nc][dir]*/) {
				q.push({ nr, nc, dir, depth + 1 });
				isVisit[nr][nc][dir] = true;
			}
			else break;
		}

		// 방향 전환 (동 1, 서 2, 남 3, 북 4)
		for (int i = 1; i <= 4; i++) {

			if (dir != i && !isVisit[r][c][i]) {

				isVisit[r][c][i] = true;
				// 방향이 서로 반대인 경우 turn을 2번 한 것이기 때문에 depth + 2
				if ((dir == 1 && i == 2) || (dir == 2 && i == 1) || (dir == 3 && i == 4) || (dir == 4 && i == 3))
					q.push({ r, c, i, depth + 2 });
				// 그 이외의 경우 +1
				else
					q.push({ r, c, i, depth + 1 });

			}
		}

	}	

	cout << result << "\n";
	return 0;
}
