#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

#define INF 1e9

using namespace std;

struct node {
	int h, r, c;
	int depth;
};

int result;
int board[5][5][5], maze[5][5][5], tmp[5][5][5];
int turn[5], order[5];

bool used[5], isVisit[5][5][5];

int dh[6] = { -1, 1, 0, 0, 0, 0 }, dr[6] = { 0, 0, -1, 1, 0, 0 }, dc[6] = { 0, 0, 0, 0, -1, 1 };

pair<int, int> st[4] = { {0, 0},  {0, 4}, {4, 0}, {4, 4} };

void copy() {
	for (int h = 0; h < 5; h++)
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				tmp[h][i][j] = board[h][i][j];
}


// 출발지점으로부터 면을 공유하지 않는 도착점 확인
int bfs(int r, int c) {

	memset(isVisit, false, sizeof(isVisit));
	queue<node> q;
	q.push({ 0, r, c, 0 });
	isVisit[0][r][c] = true;

	while (!q.empty()) {

		auto pos = q.front();
		q.pop();

		if (pos.h == 4 && pos.r == abs(r - 4) && pos.c == abs(c - 4)) {
			return pos.depth;
		}

		for (int i = 0; i < 6; i++) {

			int nh = pos.h + dh[i];
			int nr = pos.r + dr[i];
			int nc = pos.c + dc[i];

			if (nh < 0 || nr < 0 || nc < 0 || nh > r || nr > 4 || nc > 4) continue;
			if (maze[nh][nr][nc] && !isVisit[nh][nr][nc]) {
				q.push({ nh, nr, nc, pos.depth + 1 });
				isVisit[nh][nr][nc] = true;
			}
		}
	}
	return -1;
	
}

// 판을 쌓는 순서에 따라 쌓아줌
void stackboard() {
	for (int h = 0; h < 5; h++)
		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 5; c++)
				maze[h][r][c] = tmp[order[h]][r][c];
}

// 쌓는 순서 
void ordering(int cnt) {
	if (cnt == 5) {
		stackboard();
		for (int i = 0; i < 4; i++)
			if (maze[0][st[i].first][st[i].second]) {
				int dist = bfs(st[i].first, st[i].second);
				if (dist != -1) result = min(result, dist);
			}
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (!used[i]) {
			used[i] = true;
			order[cnt] = i;
			ordering(cnt + 1);
			used[i] = false;
		}
	}
}

// 회전 
void clockwise(int no) {
	int temp[5][5];
	for (int i = 0; i < 5; i++)
		for (int j = 0;j < 5;j++)
			temp[i][j] = tmp[no][i][j] ;

	for (int i = 0; i < 5; i++)
		tmp[no][0][i] = temp[4 - i][0];
	for (int i = 0; i < 5; i++)
		tmp[no][1][i] = temp[4 - i][1];
	for (int i = 0; i < 5; i++)
		tmp[no][2][i] = temp[4 - i][2];
	for (int i = 0; i < 5; i++)
		tmp[no][3][i] = temp[4 - i][3];
	for (int i = 0; i < 5; i++)
		tmp[no][4][i] = temp[4 - i][4];
}

// 각 판마다 시계방향으로 몇 번 회전할건지 정함 (0, 1, 2, 3)
void turning(int cnt) {
	if (cnt == 5) {
		copy();
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < turn[i]; j++)
				clockwise(i);
		}
		//순서를 정함
		ordering(0);
		return;
	}
	for (int i = 0; i < 4; i++) {
		turn[cnt] = i;
		turning(cnt + 1);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int h = 0; h < 5; h++)
		for (int r = 0; r < 5; r++)
			for (int c = 0; c < 5; c++)
				cin >> board[h][r][c];

	result = INF;

	turning(0);

	if (result == INF) cout << "-1\n";
	else cout << result << "\n";

	return 0;
}
