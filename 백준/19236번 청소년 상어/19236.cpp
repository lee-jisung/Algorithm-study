#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
   1. (0,0)에서 물고기를 먹고 물고기의 방향을 가짐
   2. 물고기가 작은 번호 순으로 이동
    2-1. 현재 방향이 경계 밖 or 상어가 있는 칸 이라면 이동할 수 있는 칸을 향할 때 까지 방향으로 45도 반시계 회전
	2-2. 이동할 칸에 물고기가 있다면 서로의 위치를 바꾼다. 
   3. 상어는 자신이 향한 방향으로 한 번에 여러 칸 이동 할 수 있음 
    3-1. 물고기를 먹는 경우 중 최대값을 갖는 경우 출력
*/


struct FISH {
	int r, c;
	int no;
	int dir;
	bool isEat;
};

FISH fish[17];
FISH board[4][4];
int result, shark_r, shark_c;
// 0   1   2   3   4   5   6   7 
// ↑, ↖, ←, ↙, ↓, ↘, →, ↗
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void copy(FISH prevState[17], FISH prevFish[4][4]) {
	for (int i = 1; i <= 16; i++)
		prevState[i] = fish[i];
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4;j++)
			prevFish[i][j] = board[i][j];
}

void copy_origin(FISH prevState[17], FISH prevFish[4][4]) {
	for (int i = 1; i <= 16; i++)
		fish[i] = prevState[i];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4;j++)
			board[i][j] = prevFish[i][j];
}

bool isGo(int r, int c) {
	if (r < 0 || c < 0 || r >= 4 || c >= 4) return false;
	if (r == shark_r && c == shark_c) return false;
	return true;
}

void swap(FISH a, FISH b) {
	FISH temp = b;
	fish[b.no].r = a.r; fish[b.no].c = a.c;
	fish[a.no].r = temp.r; fish[a.no].c = temp.c;

	board[b.r][b.c] = fish[a.no];
	board[a.r][a.c] = fish[b.no];
}

// 물고기 이동
void move() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i].isEat) continue;
		while (!isGo(fish[i].r + dr[fish[i].dir], fish[i].c + dc[fish[i].dir])) {
			if (fish[i].dir == 7) fish[i].dir = 0;
			else fish[i].dir++;
		}
		int nr = fish[i].r + dr[fish[i].dir], nc = fish[i].c + dc[fish[i].dir];
		swap(fish[i], board[nr][nc]);
	}
}

// 물고기를 먹고, 물고기들을 이동시킴
// 이동 시킨 상태를 prevState, prevFish에 저장해놓고
// 다음 이동할 곳으로 dfs를 통해 탐색
// 상어가 이동할 곳이 경계를 넘거나, 빈칸일 경우 탐색이 불가하므로 return
// 다시 이전 단계로 돌아오면 이전 상태를 통해 board를 복원

void dfs(int r, int c, int dir, int sum) {
	// eat fish
	if (r < 0 || c < 0 || r >= 4 || c >= 4 || board[r][c].isEat) return;
	if (!board[r][c].isEat) {
		int no = board[r][c].no;
		sum += board[r][c].no;
		board[r][c].isEat = fish[no].isEat = true;
		dir = board[r][c].dir;
	}
	shark_r = r; shark_c = c;
	result = max(result, sum);

	move();// 물고기 이동
	for (int i = 1; i <= 3; i++) {
		FISH prevState[17], prevFish[4][4];
		int nr = r + dr[dir] * i;
		int nc = c + dc[dir] * i;
		copy(prevState, prevFish); // 상태 저장
		dfs(nr, nc, dir, sum);
		copy_origin(prevState, prevFish); // 상태 복원
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) { // a = no, b = dir
			int a, b; cin >> a >> b; b--;
			fish[a] = { i, j, a, b, false };
			board[i][j] = fish[a];			
		}
	}

	dfs(0, 0, 0, 0);

	cout << result << "\n";

	return 0;
}
