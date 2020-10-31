#include <iostream>
#include <string>

using namespace std;

string board, result;
string a = "AAAA", b = "BB";
int cnt;
bool isAvail = true;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> board;

	for (int i = 0; i < board.length(); i++) {
		// . 일 때
		if (board[i] == '.') { 
			if (cnt == 2) { // 2면 b 추가
				result += b;
				cnt = 0;
			}
			else if (cnt % 2 != 0) { // 홀수일 경우 불가능하므로 -1
				isAvail = false;
				break;
			}
			result += board[i]; // . 추가
			continue;
		}
		cnt++;
		if (cnt == 4) { // 4면 바로 AAAA추가
			result += a;
			cnt = 0;
		}
	}

	if (!isAvail || cnt % 2 != 0) cout << -1 << "\n";
	else {
		if (cnt == 4) result += a;
		else if (cnt == 2) result += b;
		cout << result << "\n";
	}

	return 0;
}
