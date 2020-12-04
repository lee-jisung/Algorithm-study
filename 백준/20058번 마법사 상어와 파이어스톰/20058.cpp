#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*
   회전 => 제자리에서 돌리기\
*/

int N, Q, L, sum, iceCnt, bigCnt;
int board[64][64], temp[64][64];
bool isVisit[64][64];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, -1, 0, 1 };

// 가장 큰 덩어리 찾기
// dfs 이용
void findIce(int r, int c) {

	isVisit[r][c] = true;
	iceCnt++;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N || board[nr][nc] == 0 || isVisit[nr][nc]) continue;
		findIce(nr, nc);
	}
}

// 회전 함수 (L 범위에 따라서 temp에 회전값 옮겨놓고 다시 board로 옮기기)
void rotate(int r, int c) {
	for (int i = r; i < r + L; i++) {
		for (int j = c; j < c + L; j++) {
			temp[j - c][r + L - i - 1] = board[i][j];
		}
	}
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			board[i + r][j + c] = temp[i][j];
		}
	}
}

// 얼음 녹이기
// 조건에 맞는 얼음만 골라서 나중에 한번에 녹여야함
void melt() {
	vector<pair<int, int>> meltIce;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			int cnt = 0;
			for (int k = 0;k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N || board[nr][nc] == 0) continue;
				cnt++;
			}
			// 녹일 얼음 좌표 빼기, 전체 얼음에서 미리 녹인 값 빼기
			if (cnt < 3) {
				meltIce.push_back({ i, j });
				sum--;
			}
		}
	}
	for (int i = 0; i < meltIce.size(); i++) {
		board[meltIce[i].first][meltIce[i].second]--;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	N = pow(2, N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			sum += board[i][j];
		}

	while (Q--) {
		cin >> L;
		// L이 0이면 회전할 필요 없으므로 pass
		if (L != 0) { 
			L = pow(2, L);
			for (int i = 0; i < N; i += L) {
				for (int j = 0; j < N; j += L) {
					rotate(i, j);
				}
			}
		}
		melt();
	}

	cout << sum << "\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisit[i][j] || board[i][j] == 0) continue;
			iceCnt = 0;
			findIce(i, j);
			if (bigCnt < iceCnt) bigCnt = iceCnt;
		}
	}
	cout << bigCnt << "\n";

	return 0;
}
