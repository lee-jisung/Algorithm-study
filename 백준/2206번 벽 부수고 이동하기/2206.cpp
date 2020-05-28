#include <iostream>
#include <queue>

#define SIZE 1001

using namespace std;

struct node {
	int r, c;
	int depth;
	int crash; // 1 부신것, 0 아직 안부심
};

int n, m, result;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE][2];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs() {
	queue <node> q;
	q.push({ 1, 1, 1, 0 });
	isVisit[1][1][0] = true;

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
			if (nr < 1 || nc < 1 || nr >n || nc > m) continue;

			if (crash) { // 벽을 이미 부순 경우
				if (board[nr][nc] == 0 && !isVisit[nr][nc][crash]) {
					q.push({ nr,nc,depth + 1, crash });
					isVisit[nr][nc][crash] = true;
				}
			}
			else { // 아직 안 부순 경우
				if (board[nr][nc] == 1 && !isVisit[nr][nc][crash + 1]) {
					q.push({ nr, nc, depth + 1, crash + 1 });
					isVisit[nr][nc][crash] = true;
				}
				else if (board[nr][nc] == 0 && !isVisit[nr][nc][crash]) {
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

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string temp; cin >> temp;
		for (int j = 1;j <= m; j++) {
			board[i][j] = temp[j - 1] - '0';
		}
	}

	result = -1;

	bfs();

	cout << result << "\n";

	return 0;
}
