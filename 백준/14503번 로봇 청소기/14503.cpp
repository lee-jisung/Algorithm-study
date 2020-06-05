#include <iostream>
#include <queue>

#define SIZE 51

using namespace std;

struct robot {
	int r, c;
	int d;
};

int n, m, cnt;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];
int robot_r, robot_c, robot_d;

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 }; // N E S W

int reverse(int dir) {
	if (dir == 0) return 2;
	else if (dir == 1) return 3;
	else if (dir == 2) return 0;
	else if (dir == 3) return 1;
}

void bfs() {

	queue<robot> q;
	q.push({ robot_r, robot_c, robot_d });
	isVisit[robot_r][robot_c] = true;
	cnt++;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();

		bool ck = false;

		for (int i = 0; i < 4; i++) {
			int nd = (d + (3-i)) %4;
			int nr = r + dr[nd], nc = c + dc[nd];
			if (board[nr][nc] == 1) continue;
			if (board[nr][nc] == 0 && !isVisit[nr][nc]) {
				q.push({ nr, nc, nd });
				isVisit[nr][nc] = true;
				ck = true;
				cnt++;
				break;
			}
		}

		if(!ck) {
			int nd = reverse(d);
			int nr = r + dr[nd], nc = c + dc[nd];
			if (board[nr][nc] == 1) break;
			else {
				q.push({ nr, nc, d });
			}
		}
	}
}
int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> m;
	cin >> robot_r >> robot_c >> robot_d;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	bfs();

	cout << cnt << "\n";


	return 0;

}
