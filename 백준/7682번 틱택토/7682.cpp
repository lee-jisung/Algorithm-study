#include <iostream>
#include <string>

using namespace std;

/*
    O, X, . 의 개수를 각각 센 후
	1. '.' 의 개수가 0개일 때
	  -  X가 O보다 1개 많아야함
	  -  연속된 3개의 O가 없어야함
	2. '.'의 개수가 짝수개일때
	  - X의 개수가 O보다 1개 많아야함
	  - 3개의 연속된 X가 1개 있어야함
	  - 3개의 연속된 O가 없어야함
	3. '.'의 개수가 홀수일 때
	  - X와 O의 개수가 같아야 함
	  - 3개의 연속된 O가 1개 있어야함
	  - 3개의 연속된 X가 없어야함
*/

char board[3][3];

int continuousThree(char c) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == c && board[i][1] == c && board[i][2] == c) cnt++;
	}
	for (int i = 0; i < 3; i++)
		if (board[0][i] == c && board[1][i] == c && board[2][i] == c) cnt++;
	if (board[0][0] == c && board[1][1] == c && board[2][2] == c) cnt++;
	if (board[0][2] == c && board[1][1] == c && board[2][0] == c) cnt++;
	return cnt;
}

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		bool isAvail = true;
		int xCnt, oCnt, dotCnt;

		string input; cin >> input;
		if (input.compare("end") == 0) break;

		xCnt = oCnt = dotCnt = 0;

		for(int i=0; i<3; i++)
			for (int j = 0; j < 3; j++) {
				board[i][j] = input[i * 3 + j];
				if (board[i][j] == 'X') xCnt++;
				else if (board[i][j] == 'O') oCnt++;
				else dotCnt++;
			}

		if (dotCnt == 0) {
			if (xCnt != oCnt + 1) isAvail = false;
			else if (continuousThree('O') >= 1) isAvail = false;
		}
		else if (dotCnt % 2 == 0 && dotCnt != 0) {
			if (xCnt != oCnt + 1) isAvail = false;
			else if (continuousThree('X') != 1) isAvail = false;
			else if (continuousThree('O') != 0) isAvail = false;
		}
		else if (dotCnt % 2 == 1) {
			if (xCnt != oCnt) isAvail = false;
			else if (continuousThree('O') != 1) isAvail = false;
			else if (continuousThree('X') != 0) isAvail = false;
		}

		if (isAvail) cout << "valid\n";
		else cout << "invalid\n";
	}

	return 0;
}
