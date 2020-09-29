#include <iostream>
#include <string>

using namespace std;

int cnt;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0; i < s.length(); i++) {

		if (s[i] == 'c' && s[i + 1] == '=') {
			cnt++; i++;
		}
		else if (s[i] == 'c' && s[i + 1] == '-') {
			cnt++; i++;
		}
		else if (s[i] == 'd' && s[i + 1] == 'z' && s[i+2] == '=') {
			cnt++; i += 2;
		}
		else if (s[i] == 'd' && s[i + 1] == '-') {
			cnt++; i++;
		}
		else if (s[i] == 'l' && s[i + 1] == 'j') {
			cnt++;i++;
		}
		else if (s[i] == 'n' && s[i + 1] == 'j') {
			cnt++; i++;
		}
		else if (s[i] == 's' && s[i + 1] == '=') {
			cnt++; i++;
		}
		else if (s[i] == 'z' && s[i + 1] == '=') {
			cnt++; i++;
		}
		else cnt++;
	}

	cout << cnt << "\n";

	return 0;
}
