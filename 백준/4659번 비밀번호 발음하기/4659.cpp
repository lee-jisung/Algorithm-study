#include <iostream>
#include <string>

using namespace std;

char alpha[5] = { 'a', 'e', 'i', 'o', 'u' };

bool isVowel(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {

		string str; cin >> str;
		if (str == "end") break;
		bool isAccept = true;
		for (int i = 0; i < str.length() - 1; i++) {
			if ((str[i] != 'e' && str[i] != 'o') && str[i + 1] == str[i]) {
				isAccept = false;
				break;
			}
		}
		int cnt = 0;
		for (int i = 0; i < 5; i++) 
			if (str.find(alpha[i]) != string::npos) cnt++;

		if (cnt == 0) isAccept = false;
		if (str.length() >= 3) {
			for (int i = 0; i <=str.length() - 3; i++) {
				if (isVowel(str[i]) && isVowel(str[i + 1]) && isVowel(str[i + 2])) {
					isAccept = false; break;
				}
				if (!isVowel(str[i]) && !isVowel(str[i + 1]) && !isVowel(str[i + 2])) {
					isAccept = false; break;
				}
			}
		}
		
		if (isAccept) {
			cout << "<" << str << ">" << " is acceptable.\n";
		}
		else {
			cout << "<" << str << ">" << " is not acceptable.\n";
		}
	}
	return 0;
}
