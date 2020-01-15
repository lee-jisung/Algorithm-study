#include <iostream>
#include <queue>
#include <cstring>

#define SIZE 101

using namespace std;

int n, result;
int map[SIZE][SIZE];
bool check[SIZE][SIZE];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int h = 0; h <= 100; h++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				check[i][j] = false;
		int cnt = 0;
		queue<pair<int, int> > q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {

				if (!check[i][j] && map[i][j] > h) {
					q.push({ i, j });
					check[i][j] = true;
					cnt++;
				}
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						if (!check[x + dx[k]][y + dy[k]] && map[x+dx[k]][y+dy[k]] > h && isRange(x + dx[k], y + dy[k])) {
							q.push({ x + dx[k], y + dy[k] });
							check[x + dx[k]][y + dy[k]] = true;
						}
					}
				}

			}
		}
		result = max(result, cnt);
	}
	cout << result << "\n";

	return 0;
}
