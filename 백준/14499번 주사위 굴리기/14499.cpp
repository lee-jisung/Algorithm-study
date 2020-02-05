#include <iostream>

#define SIZE 20

using namespace std;

// 동: 우 -> 하, 상 -> 우, 좌 -> 상, 하 -> 좌 // 앞, 뒤 그대로
// 서: 하 -> 우, 우 -> 상, 상 -> 좌, 좌 -> 하         "
// 북: 상 -> 뒤, 앞 -> 상, 하 -> 앞, 뒤 -> 하 // 좌, 우 그대로
// 남: 뒤 -> 상, 상 -> 앞, 앞 - >하, 하 -> 뒤         "
// 상 : 1 / 하 : 2 / 좌 : 3 / 우 : 4 / 앞 : 5 / 뒤 : 6

int n, m, x, y, k, result;
int map[SIZE][SIZE], order[1000];
int dice[7][2];

void east() {
	
	for (int i = 1; i <= 6; i++) {
		switch (dice[i][0]) {
		case 1:
			dice[i][0] = 4;
			break;
		case 2:
			dice[i][0] = 3;
			break;
		case 3:
			dice[i][0] = 1;
			break;
		case 4:
			dice[i][0] = 2;
			break;
		}
	}
}

void west() {
	for (int i = 1; i <= 6; i++) {
		switch (dice[i][0]) {
		case 1:
			dice[i][0] = 3;
			break;
		case 2:
			dice[i][0] = 4;
			break;
		case 3:
			dice[i][0] = 2;
			break;
		case 4:
			dice[i][0] = 1;
			break;
		}
	}
}

void north() {
	for (int i = 1; i <= 6; i++) {
		switch (dice[i][0]) {
		case 1:
			dice[i][0] = 6;
			break;
		case 2:
			dice[i][0] = 5;
			break;
		case 5:
			dice[i][0] = 1;
			break;
		case 6:
			dice[i][0] = 2;
			break;
		}
	}
}

void south() {

	for (int i = 1; i <= 6; i++) {
		switch (dice[i][0]) {
		case 1:
			dice[i][0] = 5;
			break;
		case 2:
			dice[i][0] = 6;
			break;
		case 5:
			dice[i][0] = 2;
			break;
		case 6:
			dice[i][0] = 1;
			break;
		}
	}
}

int roll(int x, int y) {
	int up, down;
	for (int i = 1; i <= 6; i++) {
		if (dice[i][0] == 1)
			up = i;
		if (dice[i][0] == 2)
			down = i;
	}
	if (map[y][x]) {
		dice[down][1] = map[y][x];
		map[y][x] = 0;
	}
	else {
		map[y][x] = dice[down][1];
	}
	return dice[up][1];
}

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < m && y < n;
}
int main(void) {

	// y -> 행, x -> 열로 주고 계산
	// 문제 설명에서는 x가 행 y가 열로 표현되어있음
	cin >> n >> m >> y >> x >> k;

	dice[1][0] = 1; dice[2][0] = 5; dice[3][0] = 4;
	dice[4][0] = 3; dice[5][0] = 6; dice[6][0] = 2;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	
	for (int i = 0; i < k; i++)
		cin >> order[i];

	for (int i = 0; i < k; i++) {

		switch (order[i]) {
		case 1: // 동
			if (isRange(x+1, y)) {
				x++;
				east();
				result = roll(x, y);
				cout << result << "\n";
			}
			break;
		case 2: // 서
			if (isRange(x - 1, y)) {
				x--;
				west();
				result = roll(x, y);
				cout << result << "\n";
			}
			break;
		case 3: // 북
			if (isRange(x, y - 1)) {
				y--;
				north();
				result = roll(x, y);
				cout << result << "\n";
			}
			break;
		case 4: // 남
			if (isRange(x, y + 1)) {
				y++;
				south();
				result = roll(x, y);
				cout << result << "\n";
			}
			break;
		}
	}

	return 0;

}
