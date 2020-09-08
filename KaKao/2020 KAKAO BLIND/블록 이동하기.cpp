#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
	int r1, c1;
	int r2, c2;
	int cnt;
	int dir;
};

int n, res;
int boards[101][101];
bool isVisit[101][101][101][101];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

bool isRange(int r, int c) {
	if (r < 0 || c < 0 || r >= n || c >= n) return false;
	return true;
}

void bfs() {
	queue<node> q;
	q.push({ 0, 0, 0, 1, 0, 0});
	isVisit[0][0][0][1] = true;

	while (!q.empty()) {

		int r1 = q.front().r1, c1 = q.front().c1;
		int r2 = q.front().r2, c2 = q.front().c2;
		int cnt = q.front().cnt; 
		int dir = q.front().dir;
		q.pop();
		if ((r1 == n-1 && c1 == n-1) || (r2 == n-1 && c2 == n-1)) {
			res = min(res, cnt);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr1 = r1 + dr[i], nc1 = c1 + dc[i];
			int nr2 = r2 + dr[i], nc2 = c2 + dc[i];
			if (!isRange(nr1, nc1) || !isRange(nr2, nc2)) continue;
			if (isVisit[nr1][nc1][nr2][nc2] || boards[nr1][nc1] || boards[nr2][nc2]) continue;
			q.push({ nr1, nc1, nr2, nc2, cnt + 1, dir });
			isVisit[nr1][nc1][nr2][nc2] = true;
		}

		if (dir == 0) { // 가로
			
			if (r1 + 1 < n && !boards[r1 + 1][c1] && !boards[r2 + 1][c2] && !isVisit[r2][c2][r2 + 1][c2]) {
				q.push({ r2, c2, r2 + 1, c2, cnt + 1, 1 });
				isVisit[r2][c2][r2 + 1][c2] = true;
			}
			if (r1 - 1 >= 0 && !boards[r1 - 1][c1] && !boards[r2 - 1][c2] && !isVisit[r2 - 1][c2][r2][c2]) {
				q.push({ r2 - 1, c2, r2, c2, cnt + 1, 1 });
				isVisit[r2 - 1][c2][r2][c2] = true;
			}
			if (r2 + 1 < n && !boards[r2 + 1][c2] && !boards[r1+1][c1] && !isVisit[r1][c1][r1 + 1][c1]) {
				q.push({ r1, c1, r1 + 1, c1, cnt + 1 , 1 });
				isVisit[r1][c1][r1 + 1][c1] = true;
			}
			if (r2 - 1 >= 0 && !boards[r2 - 1][c2] && !boards[r1-1][c1] && !isVisit[r1 - 1][c1][r1][c1]) {
				q.push({ r1 - 1, c1, r1, c1, cnt + 1, 1 });
				isVisit[r1 - 1][c1][r1][c1] = true;
			}
		}
		else { // 세로
			if (c1 + 1 < n && !boards[r1][c1 + 1] && !boards[r2][c2 + 1] && !isVisit[r2][c2][r2][c2 + 1]) {
				q.push({ r2, c2, r2, c2 + 1, cnt + 1, 0 });
				isVisit[r2][c2][r2][c2 + 1] = true;
			}
			if (c1 - 1 >= 0 && !boards[r1][c1 - 1] && !boards[r2][c2 - 1] && !isVisit[r2][c2 - 1][r2][c2]) {
				q.push({ r2, c2 - 1, r2, c2, cnt + 1, 0 });
				isVisit[r2][c2 - 1][r2][c2] = true;
			}
			if (c2 + 1 < n && !boards[r2][c2 + 1] && !boards[r1][c1 + 1] && !isVisit[r1][c1][r1][c1 + 1]) {
				q.push({ r1, c1, r1, c1 + 1, cnt + 1, 0 });
				isVisit[r1][c1][r1][c1 + 1] = true;
			}
			if (c2 -1 >=0 && !boards[r2][c2 - 1] && !boards[r1][c1 - 1] && !isVisit[r1][c1 - 1][r1][c1]) {
				q.push({ r1, c1 - 1, r1, c1, cnt + 1, 0 });
				isVisit[r1][c1 - 1][r1][c1] = true;
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;
	n = board.size();
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			boards[i][j] = board[i][j];
	res = 1e9;
	bfs();
	answer = res;
	return answer;
}

int main(void) {

	vector<vector<int>> boards = {
		 {0, 0, 0, 1, 1},
	{0, 0, 0, 1, 0},
	{0, 1, 0, 1, 1},
	{1, 1, 0, 0, 1},
	{0, 0, 0, 0, 0}
	};

	solution(boards);


	return 0;
}
