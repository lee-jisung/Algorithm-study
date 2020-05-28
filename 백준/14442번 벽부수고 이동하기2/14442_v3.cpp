#include <iostream>
#include <queue>

#define SIZE 1001

using namespace std;

struct node {
	int r, c;
	int depth;
	int crash; // 부실 수 있는 벽의 남은 개수
};

int n, m, k, result;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE][11];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs() {
	queue<node> q;
	q.push({ 1, 1, 1, k });
	isVisit[1][1][k] = true;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int depth = q.front().depth;
		int crash = q.front().crash;
		q.pop();

		if (r == n && c == m) {
			result = depth;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
			
			if (crash) {
				if (board[nr][nc] == 0 && !isVisit[nr][nc][crash]) {
					q.push({ nr, nc, depth + 1, crash });
					isVisit[nr][nc][crash] = true;
				}
				else if (board[nr][nc] == 1 && !isVisit[nr][nc][crash - 1]) {
					q.push({ nr,nc,depth + 1, crash - 1 });
					isVisit[nr][nc][crash - 1] = true;
				}
			}
			else {
				if (board[nr][nc] == 0 && !isVisit[nr][nc][crash]) {
					q.push({ nr, nc, depth + 1, crash });
					isVisit[nr][nc][crash] = true;
				}
			}

		}


	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string temp; cin >> temp;
		for (int j = 1; j <= m; j++) {
			board[i][j] = temp[j - 1] - '0';
		}
	}
	
	result = -1;

	bfs();

	cout << result << "\n";

	return 0;
}
