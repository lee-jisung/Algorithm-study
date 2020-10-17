#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int n, result;
int board[101][101];
vector<pair<int, int>> emptySpace;
vector<pair<int, int>> wormhole[5];

// dir => 0: 상, 1:우, 2:하, 3:좌
int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

void init() {
	result = 0;
	emptySpace.clear();
	for (int i = 0; i < 5; i++)
		wormhole[i].clear();
}

int getReverseDir(int dir) {
	switch (dir) {
	case 0: return 2;
	case 1: return 3;
	case 2: return 0;
	case 3: return 1;
	}
}

int hitBlock(int dir, int no) {
	switch (no) {
	case 1:
		if (dir == 0 || dir == 1) return getReverseDir(dir);
		else if (dir == 2) return 1;
		else if (dir == 3) return 0;
	case 2:
		if (dir == 1 || dir == 2) return getReverseDir(dir);
		else if (dir == 0) return 1;
		else if (dir == 3) return 2;
	case 3:
		if (dir == 2 || dir == 3) return getReverseDir(dir);
		else if (dir == 1) return 2;
		else if (dir == 0) return 3;
	case 4:
		if (dir == 0 || dir == 3) return getReverseDir(dir);
		else if (dir == 1) return 0;
		else if (dir == 2) return 3;
	case 5:
		return getReverseDir(dir);
	}
}

int playGame(int r, int c, int str, int stc, int dir) {
	int score = 0;
	while (1) {

		r += dr[dir];
		c += dc[dir];
		// 시작 or 블랙홀이면 게임 끝
		if ((r == str && c == stc) || board[r][c] == -1) break;

		// 벽 부딪히면 방향 반대, 점수 +1
		if (r < 0 || c < 0 || r >= n || c >= n) {
			dir = getReverseDir(dir);
			score++;
		}
		// 블록 부딪히면 진행방향대로 방향 바꾸고 점수 +1
		else if (board[r][c] >= 1 && board[r][c] <= 5) {
			dir = hitBlock(dir, board[r][c]);
			score++;
		}
		// 웜홀만나면 반대편 웜홀 좌표로 바꾸기
		else if (board[r][c] >= 6 && board[r][c] <= 10) {
			pair<int, int> w1, w2;
			w1 = wormhole[board[r][c] - 6][0];
			w2 = wormhole[board[r][c] - 6][1];
			if (w1.first == r && w1.second == c) {
				r = w2.first; 
				c = w2.second;
			}
			else {
				r = w1.first;
				c = w1.second;
			}
		}
	}
	return score;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				if (board[i][j] == 0) emptySpace.push_back({ i, j });
				if (board[i][j] >= 6 && board[i][j] <= 10) {
					wormhole[board[i][j] - 6].push_back({ i, j });
				}
			}
		}
		for (int i = 0; i < emptySpace.size(); i++) {
			int y = emptySpace[i].first;
			int x = emptySpace[i].second;
			for (int k = 0; k < 4; k++) {
				int score = playGame(y, x, y, x, k);
				result = max(result, score);
			}
		}
		cout << "#" << tc << " " << result << "\n";
	}
	

	return 0;
}
