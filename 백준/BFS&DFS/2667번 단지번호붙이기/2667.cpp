#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define SIZE 25

using namespace std;

int n, cnt;
int map[SIZE][SIZE];
bool check[SIZE][SIZE];
vector<int> result;
queue<pair<int, int> > q;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool isRange(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n)
		return false;
	return true;
}

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (map[i][j] && !check[i][j]) {
				q.push({ i, j });
				check[i][j] = true;
				cnt = 1;

				while (!q.empty()) {

					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int new_x = x + dx[k];
						int new_y = y + dy[k];
						if (map[new_x][new_y] && !check[new_x][new_y] && isRange(new_x, new_y)) {
							q.push({ new_x, new_y });
							check[new_x][new_y] = true;
							cnt++;
						}
					}
				}
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}
