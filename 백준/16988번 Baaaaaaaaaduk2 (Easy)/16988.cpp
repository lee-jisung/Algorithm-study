#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

#define SIZE 21

using namespace std;

/*
   돌을 놓을 위치 -> dfs 조합으로 선정

   2개의 돌을 놓았을 때, 상대 돌(2)를 찾아 bfs를 하고 방문처리를 해주면서 만약 0과 맞닿은 곳이 있다면 
   개수를 0으로 return해주고, 없다면 2의 개수를 return해줌

   각각의 경우의 수 마다 개수를 구해서 최대 갯수를 출력
*/

int n, m, result;
int board[SIZE][SIZE], temp[SIZE][SIZE];
bool isVisit[SIZE][SIZE], sel[SIZE * SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

vector<pair<int, int>> v;

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	isVisit[y][x] = true;
	bool ck = true;
	int cnt = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
			if (board[nr][nc] == 0) {
				ck = false;
			}
			if (board[nr][nc] == 2 && !isVisit[nr][nc]) {
				isVisit[nr][nc] = true;
				q.push({ nr, nc });
				cnt++;
			}
		}
	}
	if (!ck) cnt = 0;
	return cnt;
}

int getDol() {
	int sum = 0;
	memset(isVisit, 0, sizeof(isVisit));
	for (int i = 1;i <= n; i++)
		for (int j = 1;j <= m; j++)
			if (board[i][j] == 2 && !isVisit[i][j]) sum += bfs(i, j);
	return sum;
}

void put_dol(int cur, int cnt) {
	if (cnt == 2) {
		result = max(result, getDol());
		return;
	}

	for (int i = cur; i < v.size(); i++) {
		if (!sel[i]) {
			sel[i] = true;
			board[v[i].first][v[i].second] = 1;
			put_dol(i + 1, cnt + 1);
			sel[i] = false;
			board[v[i].first][v[i].second] = 0;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) v.push_back({ i, j });
		}
	}

	put_dol(0, 0);

	cout << result << "\n";

	return 0;
}
