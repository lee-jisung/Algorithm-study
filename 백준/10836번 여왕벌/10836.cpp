#include <iostream>

#define SIZE 701

using namespace std;

int n, m;
int board[SIZE * 2];

// 규칙
// 첫째 열을 제외한 나머지 열 -> 0번째 행의 값들과 똑같음
// 첫째 열, 행의 값만 board에 저장 후, 0, 1, 2 만큼 증가해줌

// 출력 때 첫번째 열의 경우 따로 출력해주고
// 2번째 열 부터는 상단의 열로 계속 출력해주는 구조

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	fill(board, board + (SIZE * 2), 1);

	while (n--) {
		int zero, one, two;
		cin >> zero >> one >> two;

		for (int i = zero; i < zero + one; i++)
			board[i] += 1;
		for (int i = zero + one; i < zero + one + two; i++)
			board[i] += 2;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0;j < m;j++) {
			if (j == 0) 
				cout << board[m - i - 1] << " ";
			else 
				cout << board[m + j - 1] << " ";
		}
		cout << "\n";
	}

	return 0;
}
