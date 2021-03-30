#include <iostream>
#include <queue>

/*
*  1. 문명 상하좌우로 같은 문명에 속해있지 않은 문명들을 하나의 문명으로 합하기
*    -> union Find 사용
*    -> 문명을 합할때 문명의 개수를 1개씩 줄여서 문명이 1개가 남게되면 종료
* 
*  2. 문명 상하좌우로 퍼뜨리기 
*    -> BFS
*
*/

using namespace std;

int N, civilCnt, minCnt;
int parent[100001], board[2001][2001];

queue<pair<int, int>> civil, bfs_q;

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, -1, 0, 1 };

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

void union_civil() {

	while (!civil.empty()) {

		int r = civil.front().first;
		int c = civil.front().second;
		bfs_q.push({ r, c });
		civil.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 1 || nc < 1 || nr > N || nc > N || board[nr][nc] == 0) continue;
			if (board[r][c] == board[nr][nc] || findParent(board[r][c], board[nr][nc])) continue;

			// 문명을 합하고, 문명의 개수가 1개 준다.
			unionParent(board[r][c], board[nr][nc]);
			civilCnt--;
		}
	}
}

void spread_civil() {

	while (!bfs_q.empty()) {

		int r = bfs_q.front().first;
		int c = bfs_q.front().second;
		bfs_q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 1 || nc < 1 || nr > N || nc > N || board[nr][nc] != 0) continue;

			board[nr][nc] = board[r][c];
			civil.push({ nr, nc });
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> civilCnt;

	for (int i = 0; i <= civilCnt; i++) parent[i] = i;

	for (int i = 0; i < civilCnt; i++) {
		int x, y; cin >> x >> y;
		board[y][x] = i + 1;
		civil.push({ y, x });
	}

	while (civilCnt > 1) {

		union_civil();

		if (civilCnt == 1) {
			cout << minCnt << "\n";
			return 0;
		}

		spread_civil();
		minCnt++;
	}

	return 0;
}
