#include <iostream>
#include <queue>

#define SIZE 21

using namespace std;

int n, m, x, y, k;
int up, down, le, ri, front, rear;
int dice[7];
int board[SIZE][SIZE];
queue<int> q;

int dr[4] = { 0, 0, -1, 1 }, dc[4] = { 1, -1, 0, 0 }; // E W N S

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> x >> y >> k;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	for (int i = 0; i < k; i++) {
		int tmp; cin >> tmp;
		q.push(tmp);
	}
	up = 1; down = 6;
	le = 4; ri = 3;
	front = 5; rear = 2;
	
	while (!q.empty()) {

		int dir = q.front();
		q.pop();

		int nx = x + dr[dir-1];
		int ny = y + dc[dir-1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		switch (dir) {
			int tmp;
		case 1:
			tmp = dice[up];
			dice[up] = dice[le];
			dice[le] = dice[down];
			dice[down] = dice[ri];
			dice[ri] = tmp;
			break;
		case 2:
			tmp = dice[up];
			dice[up] = dice[ri];
			dice[ri] = dice[down];
			dice[down] = dice[le];
			dice[le] = tmp;
			break;
		case 3:
			tmp = dice[up];
			dice[up] = dice[front];
			dice[front] = dice[down];
			dice[down] = dice[rear];
			dice[rear] = tmp;
			break;
		case 4:
			tmp = dice[up];
			dice[up] = dice[rear];
			dice[rear] = dice[down];
			dice[down] = dice[front];
			dice[front] = tmp;
			break;
		}
		if (board[nx][ny] == 0) {
			board[nx][ny] = dice[down];
		}
		else {
			dice[down] = board[nx][ny];
			board[nx][ny] = 0;
		}
		cout << dice[up] << "\n";

		x = nx;
		y = ny;
	}

	return 0;

}
