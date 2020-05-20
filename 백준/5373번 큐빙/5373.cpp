#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
   1. 돌아가는 면의 시계 / 반시계 방향 회전할 함수 구현
   2. 돌아가는 면 옆에 있는 면들의 알파벳이 다른 면으로 넘어가는 함수 구현

   3. 기준면 시계 or 반시계로 먼저 돌린 후, 해당면이 돌아갔을 때 그 옆의 알파벳을 다른 면으로 옮겨주는 함수 호출
*/

string color = "wyrogb", turn;
char cube[6][3][3], tmp[3][3];
int tc, n;

void clockwise(int no) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp[i][j] = cube[no][i][j];

	// cube의 윗줄
	for (int i = 0; i < 3; i++)
		cube[no][0][i] = tmp[2 - i][0];
	// cube의 중간
	cube[no][1][0] = tmp[2][1]; cube[no][1][2] = tmp[0][1];
	// cube의 아랫줄
	for (int i = 0; i < 3;i++)
		cube[no][2][i] = tmp[2 - i][2];
}


void counterclockwise(int no) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp[i][j] = cube[no][i][j];

	// cube의 윗줄
	for (int i = 0; i < 3; i++)
		cube[no][0][i] = tmp[i][2];
	// cube의 중간
	cube[no][1][0] = tmp[0][1]; cube[no][1][2] = tmp[2][1];
	// cube의 아랫줄
	for (int i = 0; i < 3;i++)
		cube[no][2][i] = tmp[i][0];
}

// no은 돌아갈 인덱스를 뜻함 (행 or 열)
// 각 면을 시계방향으로 돌렸을 때, 옆에 붙어잇는 면의 알파벳이 움직이는 경우들 구현 (no = 0)
// 윗면을 반시계로 돌리기 -> down(0)을 호출하면 됨
void up(int no) {
	
	int temp[3];
	for (int i = 0; i < 3; i++)
		temp[i] = cube[4][no][i];
	for (int i = 0; i < 3; i++)
		cube[4][no][i] = cube[2][no][i];
	for (int i = 0; i < 3; i++)
		cube[2][no][i] = cube[5][no][i];
	for (int i = 0; i < 3; i++)
		cube[5][no][i] = cube[3][no][i];
	for (int i = 0; i < 3; i++)
		cube[3][no][i] = temp[i];
}
// no = 2(시계방향 기준)
// 바닥면 반시계 -> up(2);
void down(int no) {
	int temp[3];
	for (int i = 0; i < 3; i++)
		temp[i] = cube[4][no][i];
	for (int i = 0; i < 3; i++)
		cube[4][no][i] = cube[3][no][i];
	for (int i = 0; i < 3; i++)
		cube[3][no][i] = cube[5][no][i];
	for (int i = 0; i < 3; i++)
		cube[5][no][i] = cube[2][no][i];
	for (int i = 0; i < 3; i++)
		cube[2][no][i] = temp[i];
}

// no = 2
// 앞면 반시계 --> rear(2);
void front(int no) {

	int temp[3];
	int no2 = abs(no - 2);
	
	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][no][i];
	for (int i = 0; i < 3; i++)
		cube[0][no][i] = cube[4][2 - i][no];
	for (int i = 0; i < 3; i++)
		cube[4][i][no] = cube[1][no2][i];
	for (int i = 0; i < 3; i++)
		cube[1][no2][i] = cube[5][2 - i][no2];
	for (int i = 0; i < 3; i++)
		cube[5][i][no2] = temp[i];
}

// no = 0
// 뒷면 반시계 -> front(0);
void rear(int no) {
	int temp[3];
	int no2 = abs(no - 2);

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][no][i];
	for (int i = 0; i < 3; i++)
		cube[0][no][i] = cube[5][i][no2];
	for (int i = 0; i < 3; i++)
		cube[5][i][no2] = cube[1][no2][2 - i];
	for (int i = 0; i < 3;i++)
		cube[1][no2][i] = cube[4][i][no];
	for (int i = 0;i < 3; i++)
		cube[4][i][no] = temp[2 - i];
}

// no = 0
// 왼쪽면 반시게 -> right(0);
void left(int no) {
	int temp[3];
	int no2 = abs(no - 2);

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][i][no];
	for (int i = 0; i < 3; i++)
		cube[0][i][no] = cube[3][2 - i][no2];
	for (int i = 0; i < 3; i++)
		cube[3][i][no2] = cube[1][2 - i][no];
	for (int i = 0; i < 3; i++)
		cube[1][i][no] = cube[2][i][no];
	for (int i = 0; i < 3; i++)
		cube[2][i][no] = temp[i];

}

// no = 2
// 오른쪽면 반시계 -> left(2);
void right(int no) {
	int temp[3];
	int no2 = abs(no - 2);

	for (int i = 0; i < 3; i++)
		temp[i] = cube[0][i][no];
	for (int i = 0; i < 3; i++)
		cube[0][i][no] = cube[2][i][no];
	for (int i = 0; i < 3; i++)
		cube[2][i][no] = cube[1][i][no];
	for (int i = 0; i < 3; i++)
		cube[1][i][no] = cube[3][2 - i][no2];
	for (int i = 0; i < 3; i++)
		cube[3][i][no2] = temp[2 - i];
}

void init() {
	for (int h = 0; h < 6; h++)
		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				cube[h][r][c] = color[h];
}

void print() {
	for (int i = 0;i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << cube[0][i][j];
		}
		cout << "\n";
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		init();
		cin >> n;
		while (n--) {

			cin >> turn;
			switch (turn[0]) {
			case 'U':
				if (turn[1] == '+') {
					clockwise(0);
					up(0);
				}
				else {
					counterclockwise(0);
					down(0);
				}
				break;
			case 'D':
				if (turn[1] == '+') {
					clockwise(1);
					down(2);
				}
				else {
					counterclockwise(1);
					up(2);
				}
				break;
			case 'F':
				if (turn[1] == '+') {
					clockwise(2);
					front(2);
				}
				else {
					counterclockwise(2);
					rear(2);
				}
				break;
			case 'B':
				if (turn[1] == '+') {
					clockwise(3);
					rear(0);
				}
				else {
					counterclockwise(3);
					front(0);
				}
				break;
			case 'L':
				if (turn[1] == '+') {
					clockwise(4);
					left(0);
				}
				else {
					counterclockwise(4);
					right(0);
				}
				break;
			case 'R':
				if (turn[1] == '+') {
					clockwise(5);
					right(2);
				}
				else {
					counterclockwise(5);
					left(2);
				}
				break;
			}
		}
		print();

	}

	return 0;
}
