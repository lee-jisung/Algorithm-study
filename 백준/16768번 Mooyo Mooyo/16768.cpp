#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

/*
  n 행 10열로 이루어진 board
   - k개 이상의 똑같은 수로 이루어진 그룹이 있으면 제거
   - 중력에 의해서 모든 수들이 바닥으로 떨어짐
   
   위의 2가지 경우를 반복하다가 k개 이상의 그룹이 없으면 최종 board 상태 출력
*/

int n, k;
int board[100][10];
bool isVisit[100][10], ck;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs(int y, int x, int color) {
	queue<pair<int, int>> q, rm;
	q.push({ y, x });
	isVisit[y][x] = true;
	rm.push({ y, x });

	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= 10) continue;
			if (board[nr][nc] == color && !isVisit[nr][nc]) {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
				rm.push({ nr, nc });
			}
		}
	}

	if (rm.size() >= k) {
		ck = true;
		while (!rm.empty()) {
			auto pos = rm.front();
			board[pos.first][pos.second] = 0;
			rm.pop();
		}
	}
}

void gravity() {

	for (int j = 0; j < 10; j++) {
		queue<int> q;
		int idx = n-1;
		for (int i = n-1; i >=0; i--) {
			if (board[i][j]) {
				q.push(board[i][j]);
				board[i][j] = 0;
			}
		}
		while (!q.empty()) {
			int num = q.front();
			q.pop();
			board[idx][j] = num;
			idx--;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < 10; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	while (1) {

		ck = false;
		memset(isVisit, false, sizeof(isVisit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				if (board[i][j] && !isVisit[i][j])
					bfs(i, j, board[i][j]);
			}
		}

		if (!ck) break;
		gravity();
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
	return 0;
}
