#include <iostream>
#include <vector>

using namespace std;

struct Shark {
	int r, c;
	int dir;
	int no;
	bool isEat;
};

int n, m, k, time;
int board[21][21];
pair<int, int> smell[21][21];
int prior[401][5][4];
Shark sharks[401];

int dr[5] = { 0, -1, 1, 0, 0 }, dc[5] = { 0, 0, 0, -1, 1 };

void spreadSmell() {
	for (int i = 1; i <= m; i++) {
		if (sharks[i].isEat) continue;
		int r = sharks[i].r, c = sharks[i].c;
		smell[r][c] = { sharks[i].no, k };
	}
}

void moveShark() {
	for (int i = 1; i <= m; i++) {
		if (sharks[i].isEat) continue;
		int dir = sharks[i].dir;
		int r = sharks[i].r, c = sharks[i].c;
		int nr, nc, nDir;
		bool findArea = false, eatBySharks = false;;
		for (int j = 0; j < 4; j++) {
		    nDir = prior[sharks[i].no][dir][j];
			nr = r + dr[nDir]; 
			nc = c + dc[nDir];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n|| smell[nr][nc].first != 0) continue;
			if (board[nr][nc] != 0 && board[nr][nc] < sharks[i].no)
				eatBySharks = true;
			findArea = true;
			break;
		}

		if (eatBySharks) {
			sharks[i].isEat = true;
			board[r][c] = 0;
			continue;
		}

		if (findArea) {
			board[r][c] = 0; board[nr][nc] = sharks[i].no;
			sharks[i].r = nr; sharks[i].c = nc;
			sharks[i].dir = nDir;
		}
		else {
			for (int j = 0; j < 4; j++) {
				nDir = prior[sharks[i].no][dir][j];
				nr = r + dr[nDir];
				nc = c + dc[nDir];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
				if (smell[nr][nc].first == sharks[i].no) {
					board[r][c] = 0; board[nr][nc] = sharks[i].no;
					sharks[i].r = nr; sharks[i].c = nc;
					sharks[i].dir = nDir;
					break;
				}
			}
		}
	}
}

void removeSmell() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (smell[i][j].second > 0) {
				if (--smell[i][j].second == 0) smell[i][j].first = 0;
			}
		}
	}
}

bool isEnd() {
	for (int i = 2; i <= m; i++) {
		if (sharks[i].isEat == false) return false;
	}
	return true;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < n; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				sharks[board[i][j]] = { i, j, 0, board[i][j], false };
			}
		} 
	}

	for (int i = 1; i <= m; i++) cin >> sharks[i].dir;

	for (int i = 1; i <= m; i++) 
		for (int j = 1; j <= 4; j++) 
			for (int d = 0; d < 4; d++) 
				cin >> prior[i][j][d];

	while (1) {

		if (time > 1000) {
			cout << -1 << "\n";
			return 0;
		}
		if (isEnd()) {
			cout << time << "\n";
			return 0;
		}
		spreadSmell();
		moveShark();
		removeSmell();
		time++;
	}
	return 0;
}
