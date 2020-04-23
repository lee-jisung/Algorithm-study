#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 101
#define INF 987654321

using namespace std;

struct Robot {
	int r, c;
	int dir;
};

struct info {
	int no;
	char type;
	int rep;
};

int R, C, n, m, no = 1; 
int board[SIZE][SIZE];

vector<Robot> robot;
queue<info> order;

int dr[4] = {0, -1, 0, 1}, dc[4] = {1, 0, -1, 0}; // E, S, W, N

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> C >> R;
	cin >> n >> m;
	robot.push_back({ -1, -1, -1 });

	for (int i = 0; i < n; i++) {
		int x, y, dir; char d;
		cin >> x >> y >> d;
		if (d == 'E') dir = 0; else if (d == 'W') dir = 2; 
		else if (d == 'S') dir = 1; else if(d =='N') dir = 3;
		robot.push_back({ y, x, dir });
		board[y][x] = no;
		no++;
	}

	for (int i = 0; i < m; i++) {
		int no, rep; char ty;
		cin >> no >> ty >> rep;
		order.push({ no, ty, rep });
	}
	while (!order.empty()) {

		int no = order.front().no;
		char ty = order.front().type;
		int rep = order.front().rep;
		order.pop();

		while (rep--) {
			switch (ty) {

			case 'L':
				if (robot[no].dir - 1 < 0) robot[no].dir = 3;
				else robot[no].dir--;
				break;

			case 'R':
				if (robot[no].dir + 1 > 3) robot[no].dir = 0;
				else robot[no].dir++;
				break;

			case 'F':
				int nr = robot[no].r + dr[robot[no].dir];
				int nc = robot[no].c + dc[robot[no].dir];

				if (nr <= 0 || nc <= 0 || nr > R || nc > C) { // 영역 벗어남
					cout << "Robot " << no << " crashes into the wall\n";
					return 0;
				}
				else if (board[nr][nc] != 0) { // 부딪힘
					cout << "Robot " << no << " crashes into robot " << board[nr][nc] << "\n";
					return 0;
				}
				else {
					board[nr][nc] = no;
					board[robot[no].r][robot[no].c] = 0;
					robot[no].r = nr, robot[no].c = nc;
				}
				break;
			}
		}
	}

	cout << "OK\n";

	return 0;
}
