#include <iostream>
#include <algorithm>

#define SIZE 10
#define INF 1e9

using namespace std;

/*
   DFS - 0인 부분을 찾아 색종이를 붙일 수 있는지 확인 (5x5 부터 1x1순으로)
       - 색종이를 붙일 수 있으면 해당 좌표들의 1을 제거 (0으로), 해당 색종이 사용 숫자 +1
	   - dfs 통해 탐색 (색종이 숫자가 최소사용갯수보다 커지면 return) -> 가지치기
	   - 색종이 붙인자리를 다시 떼고 0을 1로 바꿔줌
	   - 사용했던 색종이 카운트 -1
*/

int result;
int board[SIZE][SIZE], confetti[6];

bool ck(int r, int c, int confettiNo) {
	for (int i = r; i < r + confettiNo; i++)
		for (int j = c; j < c + confettiNo; j++)
			if (!board[i][j]) return false;
	return true;
}

void attach_confetti(int r, int c, int confettiNo, int isAttach) {
	for (int i = r; i < r + confettiNo; i++)
		for (int j = c; j < c + confettiNo; j++)
			board[i][j] = isAttach;
}

void dfs(int r, int c, int confettiCnt) {

	while (board[r][c] == 0) {
		if (++c >= SIZE) {
			if (++r >= SIZE) {
				result = min(result, confettiCnt);
				return;
			}
			c = 0;
		}
	}

	if (result <= confettiCnt) return;
	for (int i = 5; i >= 1; i--) {

		if (ck(r, c, i)) {

			if (r + i > SIZE || c + i > SIZE || confetti[i] == 5) continue;
			attach_confetti(r, c, i, 0);
			confetti[i]++;
			dfs(r, c, confettiCnt + 1);
			attach_confetti(r, c, i, 1);
			confetti[i]--;
		}
	}
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			cin >> board[i][j];

	result = INF;
	dfs(0, 0, 0);

	if (result == INF) cout << "-1\n";
	else cout << result << "\n";

	return 0;
}
