#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

#define INF 1e9

using namespace std;

int n, m, result, emptySpace, tc;
char board[31][31];
bool isVisit[31][31];
int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n&& c < m;
}

void dfs(int r, int c, int dir, int cnt, int visitEmpty) {
	
	// 방문할 수 있는 모든곳 방문한 경우
	if (visitEmpty == emptySpace) {
		result = min(result, cnt);
		return;
	}
	
	// 전달받은 방향으로 계속 이동
	int nr = r + dr[dir];
	int nc = c + dc[dir];

	// 이동 가능한 경우엔 다음 위치
	if (isRange(nr, nc) && board[nr][nc] != '*' && !isVisit[nr][nc]) {
		isVisit[nr][nc] = true;
		dfs(nr, nc, dir, cnt, visitEmpty+1);
		isVisit[nr][nc] = false;
	}
	else {
		// 이동 불가능한 경우 방향 바꾸고, 이동 횟수 +1
		for (int i = 0; i < 4; i++) {
			if (i == dir) continue;
			nr = r + dr[i];
			nc = c + dc[i];
			if (isRange(nr, nc) && board[nr][nc] != '*' && !isVisit[nr][nc]) {
				isVisit[nr][nc] = true;
				dfs(nr, nc, i, cnt + 1, visitEmpty+1);
				isVisit[nr][nc] = false;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n >> m) {

		memset(isVisit, false, sizeof(isVisit));
		emptySpace = 0;

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) {
				board[i][j] = s[j];
				if (board[i][j] == '.') emptySpace++;
			}
		}

		// 모두가 장애물로만 이루어진 경우는 없기 때문에
		// 빈칸이 1개인 경우 이동 횟수가 0번
		if (emptySpace == 1) {
			cout << "Case " << ++tc << ": 0\n";
			continue;
		}

		result = INF;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '*') continue;
				// 장애물 아닌 빈칸에 놓고, 4방향 정해서 탐색
				for (int k = 0; k < 4; k++) {
					isVisit[i][j] = true;
					dfs(i, j, k, 1, 1);
					isVisit[i][j] = false;
				}
			}
		}

		cout << "Case " << ++tc << ": ";
		if (result == INF) cout << -1 << "\n";
		else cout << result << "\n";
	}

	return 0;
}
