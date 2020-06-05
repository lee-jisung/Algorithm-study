#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define SIZE 8

using namespace std;

int n, m, result;
int board[SIZE][SIZE], temp[SIZE][SIZE];

vector<pair<int, int>> virus;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = board[i][j];
}

void spread() {
	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++)
		q.push(virus[i]);
	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0;i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (temp[nr][nc] == 0) {
				temp[nr][nc] = 2;
				q.push({ nr, nc });
			}
		}
	}
}

void dfs(int cur, int no) {
	
	if (no == 3) {
		copy();
		spread();
		int cnt = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				if (temp[i][j] == 0) cnt++;

		result = max(result, cnt);
		return;
	}

	for (int i = cur; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				board[i][j] = 1;
				dfs(i, no + 1);
				board[i][j] = 0;
			}
		}
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus.push_back({ i, j });
		}
	}

	dfs(0, 0);

	cout << result << "\n";

	return 0;
}
