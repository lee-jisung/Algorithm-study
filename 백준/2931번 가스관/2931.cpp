#include <iostream>
#include <queue>

using namespace std;

struct Gas {
	int r, c;
	int dir;
};

int R, C;
char board[26][26], blocks[7] = {'|', '-', '+', '1', '2', '3', '4'};
pair<int, int> moscow, zagreb;

// 상 우 하 좌
int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

// M에서 출발하여 가스관을따라 이동
// 해커가 제거한 공간을 만낫을 때 해당 공간의 직전 좌표와 방향을 return
Gas findEmpty(int y, int x, int d) {

	queue<Gas> q;
	q.push({ y, x, d });

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int dir = q.front().dir;
		q.pop();

		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (board[nr][nc] == '.') {
			return { r, c, dir };
		}

		switch (board[nr][nc]) {
		case '|':
			if (dir == 0 || dir == 2)
				q.push({ nr, nc, dir });
			break;
		case '-':
			if (dir == 1 || dir == 3)
				q.push({ nr, nc, dir });
			break;
		case '+':
			q.push({ nr, nc, dir });
			break;
		case '1':
			if (dir == 3) q.push({ nr, nc, 2 });
			else if (dir == 0) q.push({ nr, nc, 1 });
			break;
		case '2':
			if (dir == 2) q.push({ nr, nc, 1 });
			else if (dir == 3) q.push({ nr, nc, 0 });
			break;
		case '3':
			if (dir == 2) q.push({ nr, nc, 3 });
			else if (dir == 1) q.push({ nr, nc, 0 });
			break;
		case '4':
			if (dir == 1) q.push({ nr, nc, 2 });
			else if (dir == 0) q.push({ nr, nc, 3 });
			break;
		}
	}
}

// 빈공간에 블록을 놓고, 해당 블로으로 목적까지 갈 수 있는지 여부 판단
bool bfs(int y, int x, int d) {
	queue<Gas> q;
	q.push({ y, x, d });
	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int dir = q.front().dir;
		q.pop();

		int nr = r + dr[dir];
		int nc = c + dc[dir];

		if (nr == zagreb.first && nc == zagreb.second) {
			return true;
		}
		if (board[nr][nc] == '.') break;

		switch (board[nr][nc]) {
		case '|':
			if (dir == 0 || dir == 2)
				q.push({ nr, nc, dir });
			break;
		case '-':
			if (dir == 1 || dir == 3)
				q.push({ nr, nc, dir });
			break;
		case '+':
			q.push({ nr, nc, dir });
			break;
		case '1':
			if (dir == 3) q.push({ nr, nc, 2 });
			else if (dir == 0) q.push({ nr, nc, 1 });
			break;
		case '2':
			if (dir == 2) q.push({ nr, nc, 1 });
			else if (dir == 3) q.push({ nr, nc, 0 });
			break;
		case '3':
			if (dir == 2) q.push({ nr, nc, 3 });
			else if (dir == 1) q.push({ nr, nc, 0 });
			break;
		case '4':
			if (dir == 1) q.push({ nr, nc, 2 });
			else if (dir == 0) q.push({ nr, nc, 3 });
			break;
		}
	}
	return false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'M') moscow = { i, j };
			if (board[i][j] == 'Z') zagreb = { i, j };
		}
	}
	int dir = 0;
	for (int i = 0; i < 4; i++) {
		int nr = moscow.first + dr[i];
		int nc = moscow.second + dc[i];
		if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
		// M에 인접한 가스관을 찾고, 방향 지정 (Z가 붙어있을 수 있는 경우가 있어 예외처리)
		if (board[nr][nc] != '.' && board[nr][nc] != 'Z') { 
			dir = i; break;
		}
	}

	// 빈공간을 가기 직전의 좌표와 방향을 return받음
	Gas beforeEmpty = findEmpty(moscow.first, moscow.second, dir);
	// 빈공간의 좌표 계산
	pair<int, int> emptyPlace = { beforeEmpty.r + dr[beforeEmpty.dir], beforeEmpty.c + dc[beforeEmpty.dir] };

	// 빈공간에 각 블록들을 넣어보면서 Z까지 도달할 수 있는지 확인
	// 도달 할 수 있는 경우 빈공간 좌표와 블록 출력
	for (int i = 0; i < 7; i++) {
		int r = emptyPlace.first; 
		int c = emptyPlace.second;
		board[r][c] = blocks[i];
		if (bfs(beforeEmpty.r, beforeEmpty.c, beforeEmpty.dir)) {
			cout << r + 1<< " " << c + 1<< " " << blocks[i] << "\n";
			break;
		}
		board[r][c] = '.';
	}

	return 0;
}
