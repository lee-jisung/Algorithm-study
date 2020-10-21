#include <iostream>
#include <queue>

using namespace std;

struct node {
	int r, c;
	int f;
};

int T;
int W, H, O, F;
int board[101][101];
bool isVisit[101][101];
pair<int, int> start, goal;
bool finish;

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			board[i][j] = 0;
			isVisit[i][j] = false;
		}
	}
	finish = false;
}

void bfs() {
	queue<node> q;
	q.push({ start.first, start.second, F });
	isVisit[start.first][start.second] = true;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int force = q.front().f;
		q.pop();

		if (r == goal.first && c == goal.second) {
			finish = true;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr <= 0 || nc <= 0 || nr > H || nc > W) continue;
			if (isVisit[nr][nc]) continue;
			if (board[nr][nc] < board[r][c]) {
				q.push({ nr, nc, force - 1 });
				isVisit[nr][nc] = true;
			}
			else if (board[nr][nc] >= board[r][c] && (board[nr][nc] - board[r][c]) <= force) {
				q.push({ nr, nc, force - 1 });
				isVisit[nr][nc] = true;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		init();

		cin >> H >> W >> O >> F;
		cin >> start.first >> start.second >> goal.first >> goal.second;

		for (int i = 0; i < O; i++) {
			int x, y, l; cin >> y >> x >> l;
			board[y][x] = l;
		}

		bfs();

		if (finish) cout << "잘했어!!\n";
		else cout << "인성 문제있어??\n";
	}

	return 0;
}
