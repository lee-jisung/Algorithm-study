#include <iostream>
#include <queue>
#include <cstring>

#define SIZE 501

using namespace std;

int R, C;
int board[SIZE][SIZE], chess[SIZE][SIZE];
pair<int, int> chessPos[300001];
int toGo[300001];

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
   각 칸마다 8 방향을 보고 자신이 갈 번호를 parent에 저장
   -> findparent를 이용해서 최종도착할 번호가져옴
   -> 최종 도착 번호를 가지고 chessPos에 저장되어 있는 해당 번호의 좌표에 +1
*/

int findParent(int no) {
	if (toGo[no] == no) return no;
	else return toGo[no] = findParent(toGo[no]);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 1;i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> board[i][j];
			chessPos[board[i][j]] = { i, j };
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int r = i, c = j;
			for (int k = 0; k < 8; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr < 1 || nc< 1 || nr > R || nc > C) continue;

				if (board[r][c] > board[nr][nc])
					r = nr, c = nc;
			}
			toGo[board[i][j]] = board[r][c];
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int num = findParent(board[i][j]);
			pair<int, int> pos = chessPos[num];
			chess[pos.first][pos.second]++;
		}
	}
	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << chess[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
