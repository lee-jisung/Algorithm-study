#include <iostream>
#include <queue>

#define SIZE 17

using namespace std;

/*
   가로 -> 가로 or 대각
   대각 -> 가로, 대각, 세로 
   세로 -> 대각 or 세로

   가로 or 세로일 경우 같은 방향의 한칸 앞이 1인지만 확인
   대각으로 회전시킬경우 움직일 방향의 3칸을 확인해서 1이있으면 진행 x

*/

struct node {
	int r1, c1;
	int r2, c2;
	int dir; // 0 가로, 1 대각, 2 세로
};

int n, cnt;
int board[SIZE][SIZE];

int dr[3] = { 0, 1, 1 }, dc[3] = { 1, 1, 0 };

void bfs() {
	
	queue<node> q;
	q.push({ 1, 1, 1, 2, 0 });
	
	while (!q.empty()) {

		int r1 = q.front().r1;
		int c1 = q.front().c1;
		int r2 = q.front().r2;
		int c2 = q.front().c2;
		int dir = q.front().dir;
		q.pop();

		if (r2 == n && c2 == n) {
			cnt++;
			continue;
		}

		int nr, nc;

		switch (dir) {
		
        // 가로, 세로일 경우 진행방향의 한칸 앞만 확인
		// 대각으로 가야 할 때 -> 세칸을 모두 확인
		case 0: // 가로
			for (int i = 0; i <= 1; i++) {
				nr = r2 + dr[i], nc = c2 + dc[i];
				if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
				if (i == 0 && board[nr][nc]) continue;
				else if (i == 1 && (board[nr][nc] || board[nr - 1][nc] || board[nr][nc - 1])) continue;
				q.push({ r2, c2, nr, nc, i });
			}
			break;
		case 1: // 대각
			for (int i = 0; i <= 2; i++) {
				nr = r2 + dr[i], nc = c2 + dc[i];
				if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
				if ((i ==0 || i == 2) && board[nr][nc]) continue;
				else if (i == 1 && (board[nr][nc] || board[nr - 1][nc] || board[nr][nc - 1])) continue;
				q.push({ r2, c2, nr, nc, i });
			}
			break;
		case 2: // 세로
			for (int i = 1; i <= 2; i++) {
				nr = r2 + dr[i], nc = c2 + dc[i];
				if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
				if (i == 2 && board[nr][nc]) continue;
				else if (i == 1 && (board[nr][nc] || board[nr - 1][nc] || board[nr][nc - 1])) continue;
				q.push({ r2, c2, nr, nc, i });
			}
			break;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];

	bfs();

	cout << cnt << "\n";

	return 0;
}
