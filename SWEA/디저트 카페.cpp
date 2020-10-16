#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int TC, tc;
int n, result;
int cafe[21][21];
bool isEat[101], isVisit[21][21];

int dr[4] = { -1, 1, 1, -1 }, dc[4] = { 1, 1, -1, -1 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n&& c < n;
}

// turn => 회전을 4번 이상한 경우는 탐색 x

void dfs(int st_r, int st_c, int r, int c, int dir, int turn, int sum) {
	if (turn > 4) return;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!isRange(nr, nc)) continue;
		if (isVisit[nr][nc]) {
			//이미 방문한 곳이 시작점인지 확인해야 함
			//turn>=3 인경우를 확인 => 칸이 4칸인 사각형의 경우 마지막 칸에서 시작점으로 갈 때
			// 회전 값이 아직 3이기 때문
			// sum>=4인 경우 => 사각형이면 최소 4개 이상 먹었어야 하기 때문
			if (nr == st_r && nc == st_c && turn >= 3 && sum >= 4) {
				result = max(result, sum);
				return;
			}
			continue;
		}

		if (isEat[cafe[nr][nc]]) continue;
		isVisit[nr][nc] = true;
		isEat[cafe[nr][nc]] = true;
		if (dir == i) dfs(st_r, st_c, nr, nc, i, turn, sum + 1);
		else dfs(st_r, st_c, nr, nc, i, turn + 1, sum + 1);
		isEat[cafe[nr][nc]] = false;
		isVisit[nr][nc] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	while (TC--) {
		memset(isEat, false, sizeof(isEat));
		memset(isVisit, false, sizeof(isVisit));
		result = -1;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cafe[i][j];
			}
		}

		// 열의 1 ~ n-1 칸만 탐색
		// 첫 탐색방향은 오른쪽 아래로만 탐색 (시간초과 줄이기)
		// 모든 방향을 탐색하는 경우 아래행에서 위로 그려지는 사각형은 위에서 이미 탐색했던 것
		// => 중복 발생으로 시간초과
		// 따라서 오른쪽 아래로만 탐색하며 중복 제거
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < n - 1; j++) {
				isEat[cafe[i][j]] = true;
				isVisit[i][j] = true;
				int nr = i + dr[1];
				int nc = j + dc[1];
				if (isRange(nr, nc) && isEat[cafe[nr][nc]] == false) {
					isVisit[nr][nc] = true;
					isEat[cafe[nr][nc]] = true;
					dfs(i, j, nr, nc, 1, 1, 2);
					isVisit[nr][nc] = false;
					isEat[cafe[nr][nc]] = false;
				}
				isEat[cafe[i][j]] = false;
				isVisit[i][j] = false;
			}
		}

		cout << "#" << ++tc << " " << result << "\n";
	}

	return 0;
}
