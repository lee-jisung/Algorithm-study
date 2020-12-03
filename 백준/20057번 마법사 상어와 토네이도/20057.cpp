#include <iostream>

using namespace std;

/*
    좌표 중앙부터 (1,1)까지 [r, c] 좌표를 하나씩 확인해가면서 이동하는 방향에 따라 맞는 모레 비율좌표로 날려주기

	각 방향마다 모레를 날리는 함수를 call
*/

int n, r, c, result;
int board[500][500];

double percent[9] = { 0.1, 0.07, 0.01, 0.02, 0.1, 0.07, 0.01, 0.02, 0.05 };

bool isRange(int nr, int nc) {
	return nr >= 1 && nc >= 1 && nr <= n && nc <= n;
}

void spreadLeft() {
	int nr, nc, sand = board[r][c], sum = 0, tmp;
	board[r][c] = 0;

	int dr[9] = { -1, -1, -1, -2, 1, 1, 1, 2, 0 };
	int dc[9] = { -1, 0, 1, 0, -1, 0, 1, 0, -2 };
	
	for (int i = 0; i < 9; i++) {
		nr = r + dr[i], nc = c + dc[i];
		if (!isRange(nr, nc)) {  // 모레 비율의 좌표가 범위 넘어갔을 경우
			tmp = sand * percent[i];
			result += tmp;
			sum += tmp;
			continue;
		}
		// 넘어가지 않으면 새 좌표에 모레를 + 해주고, sum에 누적
		tmp = sand * percent[i];
		board[nr][nc] += tmp;
		sum += tmp;
	}

	sand -= sum; // a로 이동할 남은 모레 계산

	nr = r; nc = c - 1;
	// a의 범위가 벗어나면 벗어난 결과에 누적
	if (!isRange(nr, nc)) {
		result += sand;
	}
	// 아니면 새로운 좌표에 + 
	else {
		board[nr][nc] += sand;
	}
}

void spreadDown() {
	int nr, nc, sand = board[r][c], sum = 0, tmp;
	board[r][c] = 0;

	int dr[9] = { 1, 0, -1, 0, 1, 0, -1, 0, 2 };
	int dc[9] = { -1, -1, -1, -2, 1, 1, 1, 2, 0 };

	for (int i = 0; i < 9; i++) {
		nr = r + dr[i], nc = c + dc[i];
		if (!isRange(nr, nc)) {
			tmp = sand * percent[i];
			result += tmp;
			sum += tmp;
			continue;
		}
		tmp = sand * percent[i];
		board[nr][nc] += tmp;
		sum += tmp;
	}
	sand -= sum;
	nr = r + 1; nc = c;
	if (!isRange(nr, nc)) {
		result += sand;
	}
	else {
		board[nr][nc] += sand;
	}
}

void spreadRight() {
	int nr, nc, sand = board[r][c], sum = 0, tmp;
	board[r][c] = 0;

	int dr[9] = { -1, -1, -1, -2, 1, 1, 1, 2, 0 };
	int dc[9] = { 1, 0, -1, 0, 1, 0, -1, 0, 2 };

	for (int i = 0; i < 9; i++) {
		nr = r + dr[i], nc = c + dc[i];
		if (!isRange(nr, nc)) {
			tmp = sand * percent[i];
			result += tmp;
			sum += tmp;
			continue;
		}
		tmp = sand * percent[i];
		board[nr][nc] += tmp;
		sum += tmp;
	}
	sand -= sum;
	nr = r; nc = c + 1;
	if (!isRange(nr, nc)) {
		result += sand;
	}
	else {
		board[nr][nc] += sand;
	}
}

void spreadUp() {
	int nr, nc, sand = board[r][c], sum = 0, tmp;
	board[r][c] = 0;

	int dr[9] = { -1, 0, 1 ,0, -1, 0, 1, 0, -2 };
	int dc[9] = { -1, -1, -1, -2, 1, 1, 1, 2, 0 };

	for (int i = 0; i < 9; i++) {
		nr = r + dr[i], nc = c + dc[i];
		if (!isRange(nr, nc)) {
			tmp = sand * percent[i];
			result += tmp;
			sum += tmp;
			continue;
		}
		tmp = sand * percent[i];
		board[nr][nc] += tmp;
		sum += tmp;
	}
	sand -= sum;
	nr = r - 1; nc = c;
	if (!isRange(nr, nc)) {
		result += sand;
	}
	else {
		board[nr][nc] += sand;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1;i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	r = c = (n / 2) + 1;

	for (int t = 1; t <= n - 1; t++) {

		if (t % 2 == 1) {
			for (int k = 0; k < t; k++) { // 좌 
				c--;
				spreadLeft();
			}
			for (int k = 0; k < t; k++) { // 하
				r++;
				spreadDown();
			}
		}
		else {

			for (int k = 0; k < t; k++) { // 우
				c++;
				spreadRight();
			}
			for (int k = 0; k < t; k++) { // 상
				r--;
				spreadUp();
			}
		}
	}

	for (int k = 0; k < n - 1; k++) {
		c--;
		spreadLeft();
	}

	cout << result << "\n";

	return 0;
}
