#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

/*
   try1.
   2차원 배열 - board[a][b] = 1인 경우 board[a][b+1]로 가야 하는 행

   possible -> j행을 1개씩 내려가면서 현재 칸이 1이면 다음 열로 r ++
   만약 현재 칸 옆 칸에 1이면 이전 열로 가야하므로 r--

   ladder -> 사다리 만드는 방법을 재귀로 해서 
   양옆, 현재가 1인 칸일경우 pass, 아닐경우 1로 체크해 준 후 
   매번 사다리 조작이 맞는지 확인


*/

using namespace std;

int N, M, H, result;
int board[31][11], temp[31][11];

bool possible() {

	for (int i = 1;i <= N; i++) {
		int r = i;
		for (int j = 1; j <= H; j++) {
			if (board[j][r]) r++;
			else if (board[j][r - 1]) r--;
		}
		if (r != i) return false;
	}
	return true;
}

void ladder(int cur, int cnt) {
	if (cnt >= 4) return;
	if (possible()) {
		result = min(result, cnt);
		return;
	}

	for (int i = cur; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] || board[i][j - 1] || board[i][j + 1]) continue;
			board[i][j] = 1;
			ladder(i, cnt + 1);
			board[i][j] = 0;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> H;

	result = INF;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
	}

	ladder(1, 0);
	if (result == INF) cout << "-1\n";
	else cout << result << "\n";

	return 0;
}
