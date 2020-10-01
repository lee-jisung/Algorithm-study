#include <iostream>
#include <algorithm>

using namespace std;

/*
  1. 번호가 작은 물고기 순 부터 방향대로 움직임
   1.1 움직일 수 있는 칸 만날때까지 반시계 45도 회전
   1.2 빈칸이면 칸 움직이고, 물고기칸이면 서로 스위칭
   1.3 이동할 수 있는 칸 없으면 움직이지않음
  2. 상어 이동 -> (0,0)부터 시작 
   2.1 먹은 물고기의 방향을 가짐
   2.2 물고기가 없는 칸으로는 이동 x, 경계 넘어서까지 이동 x
  
  3. 1,2 과정 반복해서 먹을 수 있는 물고기 번호의 최대 합 반환
*/

struct Fish {
	int r, c;
	int no;
	int dir;
	bool isEat;
};

int result;
pair<int, int> board[4][4];
Fish fish[17];

int dr[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1}, dc[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

bool isRange(int r, int c) {
	if (r < 0 || c < 0 || r >= 4 || c >= 4) return false;
	return true;
}

int getDir(int dir) {
	if (dir == 8) return 1;
	return dir + 1;
}

void moveFish(int r, int c) {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].isEat) continue;
		Fish f = fish[i];
		int nr, nc;
		while (1) {
			nr = f.r + dr[f.dir];
			nc = f.c + dc[f.dir];
			if ((nr != r || nc != c) && isRange(nr, nc)) break;
			f.dir = getDir(f.dir);
		}
		int no = board[nr][nc].first;
		Fish tmp = fish[no];
		board[nr][nc] = { f.no, f.dir };
		fish[i] = { nr, nc, f.no, f.dir, false };
		board[f.r][f.c] = { tmp.no, tmp.dir };
		fish[no] = { f.r, f.c, no, tmp.dir, false };
	}
}

void eatFish(int r, int c, int dir, int sum) {

	pair<int, int> prevBoard[4][4];
	Fish prevFish[17];

	// eat
	sum += board[r][c].first;
	dir = board[r][c].second;
	fish[board[r][c].first].isEat = true;
	board[r][c] = { 0, 0 };
	result = max(result, sum);
	//move Fish
	moveFish(r, c);

	// save previous
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			prevBoard[i][j] = board[i][j];
	for (int i = 1; i <= 16; i++) prevFish[i] = fish[i];
	
	for (int k = 1; k <= 3; k++) {
		int nr = r + dr[dir] * k, nc = c + dc[dir] * k;
		if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4 || board[nr][nc].first == 0) continue;

		eatFish(nr, nc, dir, sum);

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				board[i][j] = prevBoard[i][j];
		for (int i = 1; i <= 16; i++) fish[i] = prevFish[i];
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b; cin >> a >> b;
			board[i][j] = { a, b };
			fish[a] = { i, j, a, b, false };
		}
	}

	eatFish(0, 0, 0, 0);

	cout << result << "\n";

	return 0;
}
