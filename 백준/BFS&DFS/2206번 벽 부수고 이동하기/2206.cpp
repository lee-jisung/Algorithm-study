#include <iostream>
#include <queue>

#define SIZE 1001

using namespace std;

struct node {
	int x;
	int y;
	int block;
};

int n, m, result;
int map[SIZE][SIZE];
int cache[SIZE][SIZE][2]; // 0에는 벽을 뚫은 상태에서 각 좌표별로 가는 거리 저장
                          // 1에는 벽을 뚫지 않은 상태에서 각 좌표별 가는 거리 저장
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isRange(int x, int y) {
	return (x >= 0 && y >= 0 && x < n && y < m);
}

int main(void) {

	cin >> n >> m;
	for (int  i = 0; i < n; i++)
		for (int j = 0; j < m;j++)
			scanf("%1d", &map[i][j]);

	queue<node> q;
	q.push({ 0, 0, 1 }); // block값: 1이면 벽 아직 안뚫음 || 0이면 벽 뚫은 상태
	cache[0][0][1] = 1;
	result = -1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int block = q.front().block;
		q.pop();
		if (x == n - 1 && y == m - 1) {
			result = cache[x][y][block];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];

			if (isRange(nX, nY)) {
				if (map[nX][nY] == 1 && block) {
					cache[nX][nY][block - 1] = cache[x][y][block] + 1;
					q.push({ nX, nY, block - 1 });
				}
				else if (map[nX][nY] == 0 && cache[nX][nY][block] == 0) { // cache[nX][nY][block]가 0이면 아직 방문 전 상태
					cache[nX][nY][block] = cache[x][y][block] + 1;
					q.push({ nX, nY, block});
				}
			}
		}
	}

	cout << result << "\n";
	return 0;
}
