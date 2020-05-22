#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define INF 1e9

/*
   dfs로 *이 놓일 수 있는 위치 전부 탐색
   -> *이 놓일 때 마다 원래 놓여 있던 위치에서 움직일 거리를 계산
   -> 최종 거리보다 중간에 놓이는 위치 거리가 더 길어지면 return
   -> *를 다놓았을 때 다 연결이 되어 있다면 -> 최종거리 최솟값으로 갱신
*/

using namespace std;

int result, cnt;
char board[5][5];
bool isVisit[5][5];

vector<pair<int, int>> piece;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int getDist(int x1, int y1, int x2, int y2) {
	return abs(x2 - x1) + abs(y2 - y1);
}

bool bfs(int r, int c) {
	memset(isVisit, false, sizeof(isVisit));
	cnt = 1;
	queue<pair<int, int>> q;
	q.push({ r, c });
	isVisit[r][c] = true;

	while (!q.empty()) {
		auto pos = q.front();
		q.pop();

		for (int i = 0;i < 4;i++) {
			int nr = pos.first + dr[i];
			int nc = pos.second + dc[i];

			if (nr < 0 || nc < 0 || nr > 4 || nc > 4) continue;
			if (!isVisit[nr][nc] && board[nr][nc] == '*') {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
				cnt++;
			}
		}
	}
	if (cnt == piece.size()) return true;
	else return false;

}

void dfs(int len, int dist, int r, int c) {
	if (dist >= result) return;
	if (len == piece.size()) {

		if (bfs(r, c)) {
			result = min(result, dist);
		}

		return;
	}

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			if (board[i][j] == '.') {
				board[i][j] = '*';
				dfs(len + 1, dist + getDist(piece[len].first, piece[len].second, i, j), i, j);
				board[i][j] = '.';
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		string temp; cin >> temp;
		for (int j = 0;j < 5;j++) {
			if (temp[j] == '*') piece.push_back({ i, j });
			board[i][j] = '.';
		}
	}

	result = INF;

	dfs(0, 0, 0, 0);

	cout << result << "\n";

	return 0;
}
