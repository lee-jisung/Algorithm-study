#include <iostream>

using namespace std;

int board[5][5], callNumber[25], result;
pair<int, int> position[26];
bool bingo[5][5];


bool isEnd() {
	int bingoLine = 0;
	bool clearLine = true;
	for (int i = 0; i < 5; i++) {
		clearLine = true;
		for (int j = 0; j < 5; j++) if (!bingo[i][j]) clearLine = false;
		if (clearLine) bingoLine++;
	}

	for (int i = 0; i < 5; i++) {
		clearLine = true;
		for (int j = 0; j < 5; j++) if (!bingo[j][i]) clearLine = false;
		if (clearLine) bingoLine++;
	}

	clearLine = true;
	for (int i = 0; i < 5; i++)
		if (!bingo[i][i]) clearLine = false;
	if (clearLine) bingoLine++;

	clearLine = true;
	for (int i = 4; i >= 0; i--)
		if (!bingo[4 - i][i]) clearLine = false;
	if (clearLine) bingoLine++;


	if (bingoLine >= 3) return true;
	return false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			cin >> board[i][j];
			position[board[i][j]] = { i, j };
		}

	for (int i = 0; i < 25; i++) cin >> callNumber[i];
	
	for (int i = 0; i < 25; i++) {
		int num = callNumber[i];
		bingo[position[num].first][position[num].second] = true;
		if (isEnd()) {
			result = i + 1;
			break;
		}
	}

	cout << result << "\n";

	return 0;
}
