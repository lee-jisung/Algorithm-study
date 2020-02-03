#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int x;
	int y;
	int dis;
};

int n, eat_cnt, shark_size, result;
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };
int map[21][21];
bool isVisit[21][21];

vector<pos> fish_pos;
pair<int, int> shark_pos;

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			isVisit[i][j] = false;
	fish_pos.clear();
}

bool cmp(pos a, pos b) {
	if (a.dis == b.dis) {
		if (a.x == b.x)
			return a.y < b.y;
		return a.x < b.x;
	}
	return a.dis < b.dis;
}

// 매번 상어 위치에서 BFS를 이용하여
// 이동 가능한 칸을 q에 넣으면서 distance를 매번 갱신해주고
// 먹는게 가능한 물고기일 경우 fish_pos에 넣어줌
// 같거나 작은 물고기일 경우만 이동 가능함
void find_fish() {

	init();
	queue<pos> q;
	q.push({ shark_pos.first, shark_pos.second, 0 });
	isVisit[shark_pos.first][shark_pos.second] = true;

	while (!q.empty()) {
		int nx = q.front().x;
		int ny = q.front().y;
		int dis = q.front().dis;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (isRange(nx + dx[i], ny + dy[i]) && !isVisit[nx + dx[i]][ny + dy[i]] && shark_size >= map[nx+dx[i]][ny+dy[i]]) {
				q.push({ nx + dx[i], ny + dy[i], dis + 1 });
				isVisit[nx + dx[i]][ny + dy[i]] = true;
				if (map[nx + dx[i]][ny + dy[i]] != 0 && map[nx + dx[i]][ny + dy[i]] < shark_size) {
					fish_pos.push_back({ nx + dx[i], ny + dy[i], dis + 1 });
				}
			}
		}
	}
}

int main(void) {

	cin >> n;
	shark_size = 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark_pos = { i ,j };
				map[i][j] = 0;
			}
		}
	}

	do {
		// 물고기 위치를 전부 찾음
		find_fish(); 
		// 최단 거리 > 상단 > 왼쪽 순으로 정렬
		sort(fish_pos.begin(), fish_pos.end(), cmp);

		if (fish_pos.size() != 0) {
			result += fish_pos[0].dis;
			map[fish_pos[0].x][fish_pos[0].y] = 0;

			shark_pos = { fish_pos[0].x, fish_pos[0].y };
			eat_cnt++;

			if (eat_cnt == shark_size) {
				shark_size++;
				eat_cnt = 0;
			}
		}
	} while (fish_pos.size() != 0);

	cout << result << "\n";

	return 0;
}
