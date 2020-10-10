#include <iostream>
#include <vector>

using namespace std;

/*
   → 를 시계방향으로 돌리면 ↓ 이건데
   문제 상에서 (0, 0)에서 시작하는 0방향이 x가 증가하는 방향으로 그려지므로 → 이거고 방향은 0이고
   →를 돌려서 붙이면 (1,0) -> (1, -1)로 y가 감소하는 방향으로 올라가기때문에 방향이 1이됨
   즉, 90도 돌렷을 때 0 -> 1 -> 2 -> 3 -> 0 의 규칙이므로 (dir + 1) % 4로 다음 방향을 구함

   0세대는 0
   1세대는 0 / 1
   2세대는 0 1  / 2 1
   3세대는 0 1 2 1 / 2 3 2 1 ...
   -> 각 세대별로 다음세대를 구할 때 현재 세대 + 현재세대 끝에서부터 90도 돌린 방향을 추가한 값들임
*/

int n, result;
int board[101][101];
int dr[4] = { 0, -1, 0, 1 }, dc[4] = { 1, 0, -1, 0 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g; 
		cin >> x >> y >> d >> g;
		vector<int> dir;
		dir.push_back(d);
		board[y][x] = 1;
		for (int j = 0; j < g; j++) {
			vector<int> nextDir = dir;
			for (int k = nextDir.size() - 1; k >= 0; k--) {
				dir.push_back((nextDir[k] + 1) % 4);
			}
		}

		for (int j = 0; j < dir.size(); j++) {
			y += dr[dir[j]];
			x += dc[dir[j]];
			if (y < 0 || x < 0 || y > 100 || x > 100) continue;
			board[y][x] = 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
				result++;
		}
	}
	cout << result << "\n";

	return 0;
}
