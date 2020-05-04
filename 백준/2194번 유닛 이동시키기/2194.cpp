#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 501
#define INF 1e9

using namespace std;

struct POS {
	int r, c;
};

struct node {
	POS pos;
	int depth;
};

int n, m, a, b, k, result;

POS st, goal; // a x b의 왼쪽 상단
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1};

// 유닛 크기만큼 장애물에 걸리는지 확인
bool check(int r, int c) {
	for (int i = r; i < r + a; i++) {
		for (int j = c; j < c + b; j++) {
			if (board[i][j]) return false;
		}
	}
	return true;
}
// 유닛의 크기만큼 각 위치에서 맵의 범위를 벗어나는지 확인
bool isRange(int r, int c) {
	if (r <= 0 || c <= 0) return false;
	for (int i = 0; i < a; i++)
		if (r + i > n) return false;
	for (int j = 0; j < b; j++)
		if (c + j > m) return false;
	return true;
}

void bfs() {
	queue<node> q;
	q.push({ st, 0 });
	isVisit[st.r][st.c] = true;

	while (!q.empty()) {

		int r = q.front().pos.r;
		int c = q.front().pos.c;
		int depth = q.front().depth;
		q.pop();

		if (r == goal.r && c == goal.c) {
			result = depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (!isRange(nr, nc)) continue;

			if (!isVisit[nr][nc] && check(nr, nc)) {
				q.push({ {nr, nc}, depth + 1 });
				isVisit[nr][nc] = true;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> a >> b >> k;

	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 1;
	}

	cin >> st.r >> st.c >> goal.r >> goal.c;

	bfs();
	if (result)
		cout << result << "\n";
	else cout << -1 << "\n";

	return 0;
}
