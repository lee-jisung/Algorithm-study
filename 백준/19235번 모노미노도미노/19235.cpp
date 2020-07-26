#include <iostream>

using namespace std;

/*
	1. 1x1, 1x2, 2x1 블록
	2. 세로 6 x 4 / 가로 4 x 6
	3. 4x4 위치에 놓은 곳에 따라 각 가로와 세로 board에 경계 or 다른 블록이 닿을 때 까지 이동
	4. 각 행 or 열 마다 꽉 차 있을 경우 한줄 제거 후 점수 ++
	 4-1. 제거 후의 열or행 상단의 블록들을 모두 끌어내림 => 한칸당 중력 작용으로
	 4-2. 다시 검사해서 제거 가능한 곳이 있으면 제거, 점수 ++
	 4-3. 위의 과정을 반복하다가 더이상 없으면 그만
	5. 0, 1의 행 or 열에 블록이 있을 경우 해당 블록 길이 만큼 밑에서부터 제거하여 밑으로 내리기

	x : 행 / y : 열
	t = 1: 1x1
	t = 2: 1x2 (x,y), (x,y+1);
	t = 3: 2x1 (x,y), (x+1, y);
	(4x4에 놓는 기준)
*/

int n;
int t, x, y;
int garo[4][6], sero[6][4];
int result, cnt;

void putBlock() {
	int r, c;

	switch (t) {
	case 1:
		r = 0;
		for (int i = 0; i < 6; i++)
			if (sero[i][x]) {
				r = i;
				break;
			}
		if (r == 0) sero[5][x] = 1;
		else sero[r - 1][x] = 1;
		break;
	case 2:
		r = 0;
		for (int i = 0; i < 6; i++)
			if (sero[i][x] || sero[i][x + 1]) {
				r = i;
				break;
			}
		if (r == 0) sero[5][x] = sero[5][x + 1] = 2;
		else sero[r - 1][x] = sero[r - 1][x + 1] = 2;
		break;
	case 3:
		r = 0;
		for (int i = 0;i < 6;i++)
			if (sero[i][x]) {
				r = i;
				break;
			}
		if (r == 0) sero[5][x] = sero[4][x] = 3;
		else sero[r - 1][x] = sero[r - 2][x] = 3;
		break;
	}

	switch (t) {
	case 1:
		c = 0;
		for (int i = 0; i < 6; i++)
			if (garo[y][i]) {
				c = i;
				break;
			}
		if (c == 0) garo[y][5] = 1;
		else garo[y][c - 1] = 1;
		break;
	case 2:
		c = 0;
		for (int i = 0; i < 6; i++)
			if (garo[y][i]) {
				c = i;
				break;
			}
		if (c == 0) garo[y][5] = garo[y][4] = 2;
		else garo[y][c - 1] = garo[y][c - 2] = 2;
		break;
	case 3:
		c = 0;
		for (int i = 0; i < 6; i++)
			if (garo[y][i] || garo[y + 1][i]) {
				c = i;
				break;
			}
		if (c == 0) garo[y][5] = garo[y + 1][5] = 3;
		else garo[y][c - 1] = garo[y + 1][c - 1] = 3;
		break;
	}
}

void removeSeroBlock() {

	bool ck = false;
	for (int r = 2; r < 6; r++) {
		bool isClear = true;
		for (int c = 0; c < 4; c++) {
			if (!sero[r][c]) {
				isClear = false;
				break;
			}
		}
		if (!isClear) continue;
		result++;
		ck = true;
		for (int c = 0; c < 4; c++)
			sero[r][c] = 0;
	}

	if (!ck) return;

	int index = 0;
	for (int r = 4; r >= 0; r--) {
		for (int c = 0; c < 4; c++) {

			index = 0;
			if (sero[r][c] == 2) {
				for (int i = r + 1; i < 6; i++) 
					if (sero[i][c] || sero[i][c + 1]) {
						index = i;
						break;
					}
				if (index == 0) {
					sero[5][c] = sero[5][c + 1] = 2;
					sero[r][c] = sero[r][c + 1] = 0;
					c++;
					continue;
				}
				if (index == r + 1) {
					c++;
					continue;
				}

				sero[index - 1][c] = sero[index - 1][c + 1] = 2;
				sero[r][c] = sero[r][c + 1] = 0;
				c++;
			}

			if (sero[r][c]) {

				for(int i=r+1; i<6; i++)
					if (sero[i][c]) {
						index = i;
						break;
					}
				if (index == 0) {
					sero[5][c] = sero[r][c];
					sero[r][c] = 0;
					continue;
				}
				if (index == r + 1) continue;

				sero[index - 1][c] = sero[r][c];
				sero[r][c] = 0;
			}
		}
	}

	removeSeroBlock();
}

void removeGaroBlock() {

	bool ck = false;
	for (int c = 2; c < 6; c++) {
		bool isClear = true;
		for (int r = 0; r < 4; r++) 
			if (!garo[r][c]) {
				isClear = false;
				break;
			}
		if (!isClear) continue;
		result++;
		ck = true;
		for (int r = 0; r < 4; r++)
			garo[r][c] = 0;
	}

	if (!ck) return;

	int index = 0;
	for (int c = 4; c >= 0; c--) {
		for (int r = 0; r < 4; r++) {
			index = 0;
			if (garo[r][c] == 3) {

				for (int i = c + 1; i < 6; i++) 
					if (garo[r][i] || garo[r+1][i]) {
						index = i;
						break;
					}
				if (index == 0) {
					garo[r][5] = garo[r + 1][5] = 3;
					garo[r][c] = garo[r+1][c] = 0;
					r++;
					continue;
				}
				if (index == c + 1) {
					r++;
					continue;
				}
				garo[r][index - 1] = garo[r + 1][index - 1] = 3;
				garo[r][c] = garo[r + 1][c] = 0;
				r++;
			}


			if (garo[r][c]) {

				for (int i = c + 1; i < 6; i++)
					if (garo[r][i]) {
						index = i;
						break;
					}

				if (index == 0) {
					garo[r][5] = garo[r][c];
					garo[r][c] = 0;
					continue;
				}
				if (index == c + 1) continue;

				garo[r][index - 1] = garo[r][c];
				garo[r][c] = 0;
			}
		}
	}
	removeGaroBlock();
}

void removeFadeBlock() {

	int fade = 0;
	for (int i = 0;i < 2; i++) 
		for (int j = 0; j < 4; j++) 
			if (sero[i][j]) {
				fade++;
				break;
			}
	for (int k = 0; k < fade; k++) {
		for (int j = 0; j < 4; j++) {
			for (int i = 5; i > 0; i--) 
				sero[i][j] = sero[i - 1][j];
			sero[0][j] = 0;
		}
	}
	fade = 0;
	for (int j = 0; j < 2; j++)
		for(int i=0; i<4; i++)
			if (garo[i][j]) {
				fade++;
				break;
			}
	for (int k = 0; k < fade; k++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 5; j > 0; j--)
				garo[i][j] = garo[i][j - 1];
			garo[i][0] = 0;
		}
	}
}


void getBlockCount() {
	for (int i = 0; i < 6;i++)
		for (int j = 0; j < 4; j++)
			if (sero[i][j]) cnt++;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 6; j++)
			if (garo[i][j]) cnt++;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> t >> y >> x;

		putBlock();
		removeSeroBlock();
		removeGaroBlock();
		removeFadeBlock();
	}
	getBlockCount();
	cout << result << "\n" << cnt << "\n";

	return 0;
}
