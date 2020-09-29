#include <iostream>
#include <string>
#include <set>

using namespace std;

string word;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {

		cin >> word;
		bool ck = true;
		if (word.length() <= 2) {
			if (word[0] == '*') break;
			else cout << word << " is surprising.\n";
		}
		else {
			int n = word.length() - 2;
			for (int i = 0; i <= n; i++) {
				set<string> dPair;
				for (int j = 0; j < word.length() - (i + 1); j++) {
					string tmp = "";
					tmp += word[j];
					tmp += word[j + (i + 1)];
					if (dPair.count(tmp)) {
						ck = false;
						break;
					}
					else dPair.insert(tmp);
				}
				if (!ck) break;
			}

			if (ck) cout << word << " is surprising.\n";
			else cout << word << " is NOT surprising.\n";
		}
	}

	return 0;
}
