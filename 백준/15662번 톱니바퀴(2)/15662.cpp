#include <iostream>
#include <cstring>

using namespace std;

int t, k, cnt;
int wheel[1001][8], rot[1001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 1; i <= t; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < temp.length(); j++)
			wheel[i][j] = temp[j] - '0';
	}

	cin >> k;
	while (k--) {

		memset(rot, 0, sizeof(rot));

		int no, dir;
		cin >> no >> dir;
		rot[no] = dir;
		
		for (int i = no; i > 0; i--) {
			if (wheel[i][6] == wheel[i - 1][2]) break;
			if (wheel[i][6] != wheel[i - 1][2]) {
				if (rot[i] == -1) rot[i - 1] = 1;
				else rot[i - 1] = -1;
			}
		}

		for (int i = no; i < t; i++) {
			if (wheel[i][2] == wheel[i + 1][6]) break;
			if (wheel[i][2] != wheel[i + 1][6]) {
				if (rot[i] == 1) rot[i + 1] = -1;
				else rot[i + 1] = 1;
			}
		}

		for (int i = 1; i <= t; i++) {
			int tmp;
			if (rot[i] == 1) {
				tmp = wheel[i][7];
				for (int j = 7; j > 0; j--)
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

	for (int i = 1; i <= t; i++)
		if (wheel[i][0]) cnt++;

	cout << cnt << "\n";

	return 0;
}
