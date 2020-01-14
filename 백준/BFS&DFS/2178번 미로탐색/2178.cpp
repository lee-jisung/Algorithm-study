#include <iostream>
#include <stdio.h>
#include <queue>

#define SIZE 101

using namespace std;

int n, m, result;
int maze[SIZE][SIZE];
bool check[SIZE][SIZE];

queue<pair<pair<int, int>, int> > q;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}

int main(void) {

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
	
	q.push({ {0, 0}, 1 });
	check[0][0] = true;

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == n-1 && y == m-1) {
			result = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (maze[new_x][new_y] && !check[new_x][new_y]) {
				if (isRange(new_x, new_y)) {
					q.push({ {new_x, new_y}, cnt + 1 });
					check[new_x][new_y] = true;
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}
