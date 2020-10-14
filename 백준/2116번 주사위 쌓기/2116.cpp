#include <iostream>
#include <algorithm>

using namespace std;

/*
   abcdef => a - f, b - d, c - e 랑 마주보는 형태
   abcfde로 입력을 받으면 dice[6]에서 012와 345가 마주보는 형태로 입력될 수 있음 => (x + 3) % 6으로 접근 가능

   putDice => 재귀로 매번 주사위를 놓을 수 있는 모든 경우 탐색
   putDice (no, preDiceUp) => 이전 주사위 윗면 숫자 전달받음
	=> 주사위 6면에 대해서 이전 윗면 숫자와 같은 경우에 해당 면을 아랫면, 마주보는 면을 윗면으로 고정
	=> 나머지 4면에서 최대값을 찾아 누적하고 최대값 찾으면 됨
*/

int n, dice[10001][6];
int result, sum;

void putDice(int no, int prevDiceUp) {
	if (no == n) {
		result = max(result, sum);
		return;
	}

	for (int side = 0; side < 6; side++) {
		if (dice[no][side] != prevDiceUp) continue; // 현재 주사위의 아랫면 정하기 (윗면이랑 다르면 pass)
		int val = 0;
		for (int i = 0; i < 3; i++) {
			if (i == side || i + 3 == side) continue; // 현재 주사위 윗면인 경우는 pass
			// side 4면 중 최대값 찾기
			val = max(val, dice[no][i]);
			val = max(val, dice[no][i + 3]);
		}
		sum += val;
		putDice(no + 1, dice[no][(side + 3) % 6]); // 윗면 값 넘기기
		sum -= val;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		//abcdef로 주어진 것
		//def를 f d e 순으로 저장하기 위해서 4, 5, 3순으로 받음
		// => 0 - 3, 1 - 4, 2 - 5로 연결
		cin >> dice[i][0] >> dice[i][1] >> dice[i][2] >> dice[i][4] >> dice[i][5] >> dice[i][3];
	}

	for (int i = 0; i < 6; i++)
		putDice(0, dice[0][i]);

	cout << result << "\n";

	return 0;
}
