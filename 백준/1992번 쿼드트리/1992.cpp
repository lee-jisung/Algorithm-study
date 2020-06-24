#include <iostream>
#include <string>

using namespace std;

int n, board[65][65];
string str;

bool isSame(int r, int c, int len) {
	for (int i = r; i < r + len; i++)
		for (int j = c; j < c + len; j++)
			if (board[r][c] != board[i][j]) return false;
	return true;
}

void quadTree(int r, int c, int len) {
	if (isSame(r, c, len)) {
		str += to_string(board[r][c]);
		return;
	}
	int divlen = len / 2; // 영역을 나눌 때 (를 추가
	str += '(';
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			quadTree(r + i * divlen, c + j * divlen, divlen);
		}
	}
	str += ')'; // 4등분 영역 탐색이 끝낫을 때 ) 추가
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < n; j++)
			board[i][j] = tmp[j] - '0';
	}

	quadTree(0, 0, n);

	cout << str << "\n";
	return 0;
}
