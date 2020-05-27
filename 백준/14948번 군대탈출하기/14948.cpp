#include <iostream>
#include <queue>
#include <cstring>

#define SIZE 101
#define LIMIT 1e9

using namespace std;

struct node {
	int r, c;
	int crash; // 1 - 특수장비 사용함, 0 - 사용 안함
};

int n, m, level;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE][2]; // 특수장비를 사용한 상태, 사용하지 않은 상태를 따로 방문 처리

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

bool bfs(int lv) {
	memset(isVisit, false, sizeof(isVisit));

	if (board[0][0] > lv) return false; // 시작 칸보다 level이 작으면 false

	queue<node> q;
	q.push({ 0, 0, 0 });
	isVisit[0][0][0] = true;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int crash = q.front().crash;
		q.pop();

		if (r == n - 1 && c == m - 1) {
			return true;
		}

		for (int i = 0; i < 4; i++) {

			int nr = r + dr[i];
			int nc = c + dc[i];
			int nnr = nr + dr[i];
			int nnc = nc + dc[i];

			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (crash) { // 사용한 상태에서는 좌우로 1칸씩 탐색
				if (!isVisit[nr][nc][crash] && board[nr][nc] <= lv) {
					q.push({ nr, nc, crash });
					isVisit[nr][nc][crash] = true;
				}
			}
			else { // 사용하지 않은 상태 

				// 좌우로 1칸씩 탐색
				if (!isVisit[nr][nc][crash] && board[nr][nc] <= lv) {
					q.push({ nr, nc, crash });
					isVisit[nr][nc][crash] = true;
				}
				// 가던 방향 그대로 한칸을 뛰어 넘은 칸까지 조사 (특수장비를 사용한 상태로 바꿈)
				if (nnr < 0 || nnc < 0 || nnr >= n || nnc >= m) continue;
				if (!isVisit[nnr][nnc][crash+1] && board[nnr][nnc] <= lv) {
					q.push({ nnr, nnc, crash+1 });
					isVisit[nnr][nnc][crash+1] = true;
				}
			}
		}
	}
	return false;
}

// level의 최소값 찾기
void binary_search(int st, int end) {
	if (st > end) return;
	int mid = (st + end) / 2;
	bool ck = bfs(mid);
	if (ck) {
		level = mid;
		binary_search(st, mid - 1);
	}
	else {
		binary_search(mid + 1, end);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < m; j++) {
			cin >> board[i][j];
		}
	}

	binary_search(0, LIMIT);

	cout << level << "\n";

	return 0;
}
