#include <iostream>
#include <cstring>
#include <queue>

#define SIZE 51

using namespace std;

int tc, n, r, y, x, idx;
int razer[SIZE + 2][SIZE + 2];

int dr[4] = { 0, 1, 0, -1 }, dc[4] = { 1, 0, -1, 0 }; // E, S, W, N

/*
   idx의 방향에 따라서 현재 좌표에서 새롭게 이동할 좌표 계산 (nr, nc)
   새롭게 이동한 좌표가 보드를 넘어가면 해당 좌표 출력 후 종료

   넘어가지 않았을 경우 거울이 있는 곳이면 방향을 바꿔줌 (오른쪽으로)
   거울이 없는 곳이면 방향을 유지한채 새로운 좌표 값으로 재탐색

*/
void dfs(int i, int j) {

	int nr = i + dr[idx], nc = j + dc[idx];

	if (nr < 1 || nc < 1 || nr > n || nc > n) {
		cout << nr << " " << nc << "\n";
		return;
	}

	if (razer[nr][nc]) {
		idx = (idx + 1) % 4;
		dfs(nr, nc);
	}
	else {
		dfs(nr, nc);
	}
}

int main(void) {

	cin >> tc;
	while (tc--) {
		memset(razer, 0, sizeof(razer));

		cin >> n >> r;
		for (int i = 0; i < r;i++) {
			int a, b;
			cin >> a >> b;
			razer[a][b] = 1;
		}
		cin >> y >> x;
		// 레이저의 위치에 따라 idx 방향 정해주기
		if (y > n) idx = 3;
		else if (y < 1) idx = 1;
		else if (x > n) idx = 2;
		else idx = 0;
		// dfs 탐색
		dfs(y, x);
	}

	return 0;
}
