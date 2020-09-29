#include <iostream>
#include <string>

using namespace std;

/*
   위, 아래에서 ? 전까지 각 문자별 사다리를 탈 것

   ? 전까지 진행한 두 문자열을 이용하여 
     i번째 문자끼리 같다면 * 추가
	 i, i+1끼리 같다면 - 추가
	 둘 다 아니라면 x 출력
   
   */

int k, n, idx;
char up[27], down[27];
char board[1001][27];
string res;
bool ck = true;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		up[i] = 'A' + i;
		cin >> down[i];
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k - 1; j++) {
			cin >> board[i][j];
			if (board[i][j] == '?') idx = i;
		}

	for (int i = 0; i < idx; i++) {
		for (int j = 0; j < k - 1; j++) {
			if (board[i][j] == '-') {
				char tmp = up[j];
				up[j] = up[j + 1];
				up[j + 1] = tmp;
			}
		}
	}

	for (int i = n - 1; i > idx; i--) {
		for (int j = 0; j < k - 1; j++) {
			if (board[i][j] == '-') {
				char tmp = down[j];
				down[j] = down[j + 1];
				down[j + 1] = tmp;
			}
		}
	}

	for (int i = 0; i < k-1; i++) {
		if (up[i] == down[i]) res += '*';
		else if (up[i] == down[i + 1] && up[i + 1] == down[i]) {
			res += '-';
			char tmp = up[i];
			up[i] = up[i + 1];
			up[i + 1] = tmp;
		}
		else {
			ck = false;
			break;
		}
	}

	if (ck) {
		cout << res << "\n";
	}
	else {
		for (int i = 0; i < k-1; i++)
			cout << 'x';
		cout << "\n";
	}
	
	return 0;
}
