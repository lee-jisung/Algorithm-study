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
	int depth;
};

int tc, n, m, result;
node cur;
char map[SIZE][SIZE];
bool isVisit[SIZE][SIZE], escape;

queue<pair<int, int > > fire;
queue<node> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}


/*
   4179번과 똑같은문제

   불 개수만큼 bfs를 이용하여 불을 먼저 퍼뜨리고
   그 이후 사람이 움직일 수 있는 공간을 탐색하여 이동가능한 공간을 nextQ에 넣어줌
   그후 q = nextQ로 업데이트 해줌

   q가 비어있다면 더이상 움직일 수 있는 공간이 없으므로 break;
   가장자리에 도착했다면 탈출 가능하므로 break;
   
*/

int main(void) {
	
	cin >> tc;
	while (tc--) {
		while (!q.empty()) q.pop();
		while (!fire.empty()) fire.pop();
		memset(isVisit, false, sizeof(isVisit));
		escape = false;

		cin >> m >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == '@') {
					map[i][j] = '.';
					cur.r = i, cur.c = j;
				}
				if (map[i][j] == '*') fire.push({ i,j });
			}
		}

		q.push({ cur.r, cur.c, 1 });
		isVisit[cur.r][cur.c] = true;
		while (1) {

			int fire_size = fire.size();
			while (fire_size--) {
				int fx = fire.front().first;
				int fy = fire.front().second;
				fire.pop();

				for (int i = 0;i < 4;i++) {
					int nfx = fx + dx[i];
					int nfy = fy + dy[i];

					if (isRange(nfx, nfy) && map[nfx][nfy] == '.') {
						map[nfx][nfy] = '*';
						fire.push({ nfx, nfy });
					}
				}
			}

			queue<node> nextQ;
			while (!q.empty()) {
				int curx = q.front().r;
				int cury = q.front().c;
				int depth = q.front().depth;
				q.pop();

				if (curx == 0 || cury == 0 || curx == n - 1 || cury == m - 1) {
					result = depth;
					escape = true;
					break;
				}
				for (int i = 0; i < 4; i++) {
					int nx = curx + dx[i];
					int ny = cury + dy[i];

					if (isRange(nx, ny) && map[nx][ny] == '.' && !isVisit[nx][ny]) {
						nextQ.push({ nx, ny, depth + 1 });
						isVisit[nx][ny] = true;
					}
				}

			}
			q = nextQ;

			if (escape || q.empty()) break;
		}
		if (escape) cout << result << "\n";
		else cout << "IMPOSSIBLE\n";

	}
	

	return 0;
}
