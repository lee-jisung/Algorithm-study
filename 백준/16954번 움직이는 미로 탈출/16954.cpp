#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 8
#define INF 987654321

struct NODE {
	int r;
	int c;
};

using namespace std;

int wok_r, wok_c, goal_r, goal_c, result, wall_cnt;
int map[SIZE][SIZE], moved_map[SIZE][SIZE];

int dr[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dc[9] = { -1, 0, 1, -1, 1, 0, -1, 0, 1 };

// 1초 -> 이동 후 벽 한행씩 밑으로 이동 --> 새로 만드는 행 = 모든칸이 0

void move() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i == 0)
				moved_map[i][j] = 0;
			else {
				moved_map[i][j] = map[i - 1][j];

			}
		}
	}
}

// 맨 밑의 없어진 벽의 개수만큼 빼줌
void copy() {
	for (int j = 0;j < 8; j++) {
		if (map[7][j]) wall_cnt--;
	}
	for (int i = 0; i < 8;i++) {
		for (int j = 0;j < 8; j++) {
			map[i][j] = moved_map[i][j];
		}
	}
}

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < 8 && c < 8;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	wok_r = 7; wok_c = 0;
	goal_r = 0; goal_c = 7;

	for (int i = 0; i < 8; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			// 0 - 빈칸, 1 - 벽
			if (str[j] == '.') map[i][j] = 0;
			if (str[j] == '#') {
				wall_cnt++;
				map[i][j] = 1;
			}
		}
	}

	queue<NODE> q;
	q.push({ wok_r, wok_c });

	while (!q.empty()) {
		int p = q.size();
		move();
		while (p--) {
			int r = q.front().r;
			int c = q.front().c;
			q.pop();

			// 벽의 개수가 0이면 무조건 갈 수 있음
			if (!wall_cnt) {
				result = 1;
				break;
			}

			if (r == goal_r && c == goal_c) {
				result = 1;
				break;
			}

			// 벽 이동 전 갈 수 있는 공간 + 벽 이동 후 갈 수 있는 공간
			// 에서 남아있는 공간만 큐에 넣음
			for (int i = 0; i < 9; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (isRange(nr, nc)) {
					if (!map[nr][nc] && !moved_map[nr][nc]) {
						q.push({ nr, nc});
					}
				}
			}
		}
		copy();
	}

	cout << result << "\n";

	return 0;
}
