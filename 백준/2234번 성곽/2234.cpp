#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 51
#define INF 987654321

using namespace std;

int n, m, room, room_size, max_size;
int rooms[SIZE * SIZE];
int map[SIZE][SIZE], section[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

// 0 ~ 3 ==> 서, 북, 동, 남 순
int dx[4] = { 0, -1, 0, 1 }, dy[4] = { -1, 0, 1, 0 };

/*

   bfs ==> 1 << (0~3)을 값에 & 연산을 돌리면서 0이면 벽이 없는곳

   bfs시 방에 숫자로 표시 --> section[n][m]

   section의 매 칸마다 동서남북으로 확인해서 방 숫자가 다른경우 두개의 방 크기를 더해서
   최대의 크기 ==> 벽을 하나 부셨을 때 방 크기

*/

bool isRange(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= m;
}

void bfs(int x, int y, int sec) {

	int size = 1;
	queue<pair<int, int> > q;
	q.push({ x, y });
	isVisit[x][y] = true;
	section[x][y] = sec;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {

			int nr = r + dx[i];
			int nc = c + dy[i];

			if (!isRange(nr, nc) || isVisit[nr][nc]) continue;

			// map[r][c] & (1 << i) 의 값이 0이면 벽이 없는 곳임
			if (!(map[r][c] & (1 << i))) {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
				size++;
				section[nr][nc] = sec;
			}
		}
	}
	// 방 숫자마다의 크기 저장 배열
	rooms[sec] = size;
	room_size = max(room_size, size);
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			if (!isVisit[i][j]) {
				room++;
				bfs(i, j, room);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			int room_no = section[i][j];
			for (int k = 0; k < 4; k++) {
				int nr = i + dx[k];
				int nc = j + dy[k];
				if (isRange(nr, nc)) {
					if (section[nr][nc] != room_no) {
						max_size = max(max_size, rooms[room_no] + rooms[section[nr][nc]]);
					}
				}
			}
		}
	}

	cout << room << "\n";
	cout << room_size << "\n";
	cout << max_size << "\n";

	return 0;
}
