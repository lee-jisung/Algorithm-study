#include <iostream>
#include <cstring>
#include <queue>

#define SIZE 51

using namespace std;

int N, L, R;
int moving;
int board[SIZE][SIZE], temp[SIZE][SIZE];
int united[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

bool same() {
	for (int i = 0; i < N;i++)
		for (int j = 0; j < N; j++)
			if (board[i][j] != temp[i][j]) return false;
	return true;
}

void copy() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			board[i][j] = temp[i][j];
}

void bfs(int y, int x, int no) {
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	q.push({ y, x });
	united[y][x] = no;
	int people = board[y][x];
	int cnt = 1;
	v.push_back({ y, x });
	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || united[nr][nc]) continue;
			int diff = abs(board[r][c] - board[nr][nc]);
			if (diff >= L && diff <= R) {
				united[nr][nc] = no;
				q.push({ nr, nc });
				people += board[nr][nc];
				cnt++;
				v.push_back({ nr, nc });
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		temp[v[i].first][v[i].second] = people / cnt;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
		for (int j = 0;j < N;j++)
			cin >> board[i][j];

	while (1) {

		memset(united, 0, sizeof(united));
		int no = 0;
		for (int i = 0;i < N;i++) {
			for (int j = 0; j < N; j++) {
				if (!united[i][j]) {
					no++;
					bfs(i, j, no);
				}
			}
		}
		if (same()) break;
		moving++;
		copy();
	}
	
	cout << moving << "\n";

	return 0;
}
