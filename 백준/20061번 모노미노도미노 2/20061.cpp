#include <iostream>

using namespace std;

/*
   t = 1 : 1 x 1
   t = 2 : 1 x 2
   t = 3 : 2 x 1
*/

int n, score, blockCnt;
int sero[6][4], garo[4][6];

// 블럭 놓기
// 세로를 예로 들어서 
// 1 ~ 6 행 중 이미 놓인 블럭이 있다면 해당 r - 1에 블럭 놓기
// 만약 r이 그대로 0이라면 마지막까지 다 탐색해도 놓인 블럭이 없다는 의미 => 제일 마지막 줄에 놓기
// 가로도 동일하게
void putBlock(int t, int y, int x) {

	int r, c;
	// sero
	r = 0, c = x;
	switch (t) {
	case 1:
		for (int i = 1; i < 6; i++) {
			if (sero[i][c]) {
				r = i;
				break;
			}
		}
		if (r == 0) sero[5][c] = 1;
		else sero[r - 1][c] = 1;
		break;
	case 2:

		for (int i = 1; i < 6; i++) {
			if (sero[i][c] || sero[i][c + 1]) {
				r = i;
				break;
			}
		}
		if (r == 0) sero[5][c] = sero[5][c + 1] = 1;
		else sero[r - 1][c] = sero[r - 1][c + 1] = 1;
		break;
	case 3:

		for (int i = 1; i < 6; i++) {
			if (sero[i][c]) {
				r = i;
				break;
			}
		}
		if (r == 0) sero[5][c] = sero[4][c] = 1;
		else sero[r - 1][c] = sero[r - 2][c] = 1;
		break;
	}

	// garo
	r = y; c = 0;
	switch (t) {
	case 1:
		for (int i = 1; i < 6; i++) {
			if (garo[r][i]) {
				c = i;
				break;
			}
		}
		if (c == 0) garo[r][5] = 1;
		else garo[r][c - 1] = 1;
		break;
	case 2:
		for (int i = 1; i < 6; i++) {
			if (garo[r][i]) {
				c = i;
				break;
			}
		}
		if (c == 0) garo[r][5] = garo[r][4] = 1;
		else garo[r][c - 1] = garo[r][c - 2] = 1;
		break;
	case 3:
		for (int i = 1; i < 6; i++) {
			if (garo[r][i] || garo[r + 1][i]) {
				c = i;
				break;
			}
		}
		if (c == 0) garo[r][5] = garo[r + 1][5] = 1;
		else garo[r][c - 1] = garo[r + 1][c - 1] = 1;
		break;
	}

}

// 세로의 경우 
// 블럭 1줄 제거하고, 그 줄부터 맨 위 줄까지 한칸씩 땡겨서 내리고, 맨 윗줄은 0으로 초기화
// 단, i값을 ++ 해줘야 한칸 내린 줄부터 탐색할 수 있음
// 가로도 동일
void removeBlock() {

	//sero
	for (int i = 5; i >= 0; i--) {
		bool isClean = true;
		for (int j = 0; j < 4; j++) {
			if (!sero[i][j]) {
				isClean = false;
				break;
			}
		}
		if (!isClean) continue;
		score++;
		for (int j = 0; j < 4; j++) {
			for (int idx = i; idx > 0; idx--)
				sero[idx][j] = sero[idx - 1][j];
			sero[0][j] = 0;
		}
		i++; // 한줄을 위에서 내렷기 때문에 다시 i++해줘서 그 행을 다시 탐색
	}

	//garo
	for (int i = 5; i >= 0; i--) {
		bool isClean = true;
		for (int j = 0; j < 4; j++) {
			if (!garo[j][i]) {
				isClean = false;
				break;
			}
		}
		if (!isClean) continue;
		score++;
		for (int j = 0; j < 4; j++) {
			for (int idx = i; idx > 0; idx--)
				garo[j][idx] = garo[j][idx - 1];
			garo[j][0] = 0;
		}
		i++;
	}
}

// 세로의 경우
// 0, 1 행을 탐색하면서 블럭이 놓여있으면 카운트
// 카운트 한 만큼 맨 아래줄에서 한칸씩 당기기
// 동일하게 맨위는 0으로 초기화

// 가로도 동일

void removeFadeBlock() {
	//sero
	int fadeCnt = 0;
	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (sero[i][j]) {
				fadeCnt++;
				break;
			}
		}
	}

	for (int k = 0; k < fadeCnt; k++) {
		for (int j = 0; j < 4; j++) {
			for (int i = 5; i >= 1; i--)
				sero[i][j] = sero[i - 1][j];
			sero[0][j] = 0;
		}
	}

	//garo
	fadeCnt = 0;
	for (int i = 1; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			if (garo[j][i]) {
				fadeCnt++;
				break;
			}
		}
	}

	for (int k = 0; k < fadeCnt; k++) {
		for (int j = 0; j < 4; j++) {
			for (int i = 5; i >= 1; i--)
				garo[j][i] = garo[j][i - 1];
			garo[j][0] = 0;
		}
	}

}

// 남은 블럭 수 가져오기
void getBlockCnt() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 4; j++)
			if (sero[i][j]) blockCnt++;

	for (int i = 0; i < 4; i++)
		for (int j = 0;j < 6;j++)
			if (garo[i][j]) blockCnt++;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int t, x, y; cin >> t >> y >> x;
		putBlock(t, y, x);
		removeBlock();
		removeFadeBlock();
	}

	getBlockCnt();

	cout << score << "\n" << blockCnt << "\n";

	return 0;
}
