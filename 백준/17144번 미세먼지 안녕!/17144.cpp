#include <iostream>
#include <vector>

#define SIZE 51

using namespace std;

// 미세먼지를 확산시킨 map
// 확산 후 남은 미세먼지만 남은 map
// 2개를 더해서 1초동안 확산 후 map을 만든 후
// 공기 청정기 이동
// T초동안 반복

int map[SIZE][SIZE], spread_map[SIZE][SIZE];
int r, c, t, result;

vector<pair<int, int> > pos;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < r && y < c;
}

void spread(int x, int y) {
	int cnt = 0;
	for (int k = 0; k < 4; k++) {
		int nR = x + dx[k];
		int nC = y + dy[k];
		if (map[nR][nC] != -1 && isRange(nR, nC)) {
			spread_map[nR][nC] += map[x][y] / 5;
			cnt++;
		}
	}
	map[x][y] -= (map[x][y] / 5) * cnt;
}

void clean() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			spread_map[i][j] = 0;
}

void air_up() {
	for (int i = pos[0].first - 1; i > 0; i--)
		map[i][0] = map[i - 1][0];

	for (int j = 0; j < c-1; j++)
		map[0][j] = map[0][j + 1];

	for (int i = 0; i < pos[0].first; i++)
		map[i][c - 1] = map[i + 1][c - 1];

	for (int j = c - 1; j >0; j--) {
		map[pos[0].first][j] = map[pos[0].first][j - 1];
		if (map[pos[0].first][j - 1] == -1) map[pos[0].first][j] = 0;
	}
}

void air_down() {
	for (int i = pos[1].first + 1; i < r-1; i++)
		map[i][0] = map[i + 1][0];

	for (int j = 0; j < c - 1; j++)
		map[r-1][j] = map[r-1][j + 1];

	for (int i = r-1; i > pos[1].first; i--)
		map[i][c - 1] = map[i - 1][c - 1];

	for (int j = c - 1; j > 0; j--) {
		map[pos[1].first][j] = map[pos[1].first][j - 1];
		if (map[pos[1].first][j - 1] == -1) map[pos[1].first][j] = 0;
	}
}

int main(void) {

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1)
				pos.push_back(make_pair(i, j));
		}
	}

	while (t--) {
		clean();
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] > 0) {
					spread(i, j);
				}
			}
		}
		for (int i = 0; i < r; i++) 
			for (int j = 0; j < c; j++) 
				if (map[i][j] != -1) 
					map[i][j] += spread_map[i][j];

		air_up();
		air_down();
	}

	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) 
			if (map[i][j] > 0) result += map[i][j];

	cout << result << "\n";

	return 0;
}
