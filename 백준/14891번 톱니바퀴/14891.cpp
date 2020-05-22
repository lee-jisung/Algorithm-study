#include <iostream>
#include <cstring>

using namespace std;

int wheel[5][8], k, n, d;
int rot[5], result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 4;i++) {
		string temp; cin >> temp;
		for (int j = 0; j < 8; j++)
			wheel[i][j] = temp[j] - '0';
	}

	cin >> k;
	while (k--) {

		cin >> n >> d;

		memset(rot, 0, sizeof(rot));
		rot[n] = d;
		// 앞, 뒤의 바퀴를 확인하면서 다르면 회전방향 저장 (현재 방향과 반대로 회전)
		for (int i = n; i > 0; i--) {
			if (wheel[i][6] == wheel[i - 1][2]) break;
			else if (wheel[i][6] != wheel[i - 1][2]) {
				if (rot[i] == -1) rot[i - 1] = 1;
				else rot[i - 1] = -1;
			}
		}
		
		for (int i = n; i < 4 ; i++) {
			if (wheel[i][2] == wheel[i + 1][6]) break;
			else if (wheel[i][2] != wheel[i + 1][6]) {
				if (rot[i] == -1) rot[i + 1] = 1;
				else rot[i + 1] = -1;
			}
		}

		// 1이면 시계, -1이면 반시계로 회전
		for (int i = 1; i <= 4; i++) {
			int tmp;
			if (rot[i] == 1) {
				tmp = wheel[i][7];
				for (int j = 7; j >= 0; j--)
					wheel[i][j] = wheel[i][j - 1];
				wheel[i][0] = tmp;
			}
			else if (rot[i] == -1) {
				tmp = wheel[i][0];
				for (int j = 0; j < 7; j++)
					wheel[i][j] = wheel[i][j + 1];
				wheel[i][7] = tmp;
			}
		}
	}

	if (wheel[1][0] == 1) result += 1;
	if (wheel[2][0] == 1) result += 2;
	if (wheel[3][0] == 1) result += 4;
	if (wheel[4][0] == 1) result += 8;

	cout << result << "\n";

	return 0;

}
