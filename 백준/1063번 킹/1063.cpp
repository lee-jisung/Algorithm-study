#include <iostream>
#include <string>

using namespace std;

int n;
int board[8][8];

pair<int, int> king, dol;
int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string k, d; cin >> k >> d >> n;
	        //행, 열
	king = { k[1] - '0', k[0] - 'A' + 1 };
	dol = { d[1] - '0', d[0] - 'A' + 1};

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (s == "R") {
			if (king.second + 1 > 8) continue;
			if (king.first == dol.first && king.second + 1 == dol.second) {
				if (dol.second + 1 > 8) continue;
				king.second++; dol.second++;
			}
			else king.second++;
		}
		else if (s == "L") {
			if (king.second -1 < 1) continue;
			if (king.first == dol.first && king.second - 1 == dol.second ) {
				if (dol.second - 1 < 1) continue;
				king.second--; dol.second--;
			}
			else king.second--;
		}
		else if (s == "B") {
			if (king.first - 1 < 1) continue;
			if (king.first - 1 == dol.first && king.second == dol.second) {
				if (dol.first - 1 < 1) continue;
				king.first--; dol.first--;
			}
			else king.first--;
		}
		else if (s == "T") {
			if (king.first + 1 > 8) continue;
			if (king.first + 1 == dol.first && king.second == dol.second) {
				if (dol.first + 1 > 8 ) continue;
				king.first++; dol.first++;
			}
			else king.first++;
		}
		else if (s == "RT") {
			if (king.first + 1 > 8 || king.second + 1 > 8) continue;
			if (king.first + 1 == dol.first && king.second + 1 == dol.second) {
				if (dol.first + 1 > 8 || dol.second + 1 > 8) continue;
				king.first++; dol.first++;
				king.second++; dol.second++;
			}
			else { king.first++; king.second++; }
		}
		else if (s == "LT") {
			if (king.first + 1 > 8 || king.second - 1 < 1) continue;
			if (king.first + 1 == dol.first && king.second - 1 == dol.second) {
				if (dol.first + 1 > 8 || dol.second - 1 < 1) continue;
				king.first++; dol.first++;
				king.second--; dol.second--;
			}
			else { king.first++; king.second--; }
		}
		else if (s == "RB") {
			if (king.first - 1 < 1 || king.second + 1 > 8) continue;
			if (king.first - 1 == dol.first && king.second + 1 == dol.second) {
				if (dol.first - 1 < 1 || dol.second + 1 > 8) continue;
				king.first--; dol.first--;
				king.second++; dol.second++;
			}
			else { king.first--; king.second++; }
		}
		else if (s == "LB") {
			if (king.first - 1 < 1 || king.second - 1 < 1) continue;
			if (king.first - 1 == dol.first && king.second - 1 == dol.second) {
				if (dol.first - 1 < 1 || dol.second - 1 < 1) continue;
				king.first--; dol.first--;
				king.second--; dol.second--;
			}
			else { king.first--; king.second--; }
		}

	}
	k = "";
	k += (char)king.second + 'A' - 1;
	k += (char)king.first + '0';
	d = "";
	d += (char)dol.second + 'A' - 1;
	d += (char)dol.first + '0';

	cout << k << "\n" << d << "\n";
	return 0;
}
