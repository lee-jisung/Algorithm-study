#include <iostream>
#include <vector>

#define SIZE 101

using namespace std;

int n, cnt;
int board[SIZE][SIZE];

/*
   0 = right, 1 = up, 2 = left, 3 = down

   A+1세대의 방향 정보 -> A세대의 방향 정보 + (A세대 방향 역순 +1)을 한 것

   0세대 방향 - 0
   1세대 방향 - 0 1
   2세대 방향 - 0 1 2 1
   3세대 방향 - 0 1 2 1 2 3 2 1
   ...
   >> 4세대일 경우 3 +1 해서 4 가 나오지만 방향은 0 1 2 3 까지 이므로 (num + 1) % 4 를 이용

*/

// E, N, W, S
int dr[4] = { 0, -1, 0, 1 }, dc[4] = { 1, 0, -1, 0 };

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<int> dir;
		dir.push_back(d);
		
		for (int j = 0; j < g; j++){
			vector<int> next = dir;
			for (int k = next.size() - 1; k >= 0; k--) {
				dir.push_back((next[k] + 1) % 4);
			}
		}

		board[y][x] = 1;
		for (int j = 0; j < dir.size(); j++) {
			y += dr[dir[j]];
			x += dc[dir[j]];

			if (y < 0 || x < 0 || y >= SIZE || x >= SIZE) continue;
			board[y][x] = 1;
		}
	}

	for (int i = 0; i < SIZE - 1;i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (board[i][j] && board[i][j + 1] && board[i + 1][j] && board[i + 1][j + 1])
				cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}
