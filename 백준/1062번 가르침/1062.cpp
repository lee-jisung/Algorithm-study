#include <iostream>
#include <string>

using namespace std;

int n, k, result;
string word[50];
bool isUsed[26];
char pre[5] = { 'a', 'c', 'i','n', 't' };

void findWord(int idx, int cnt) {
	if (cnt == k - 5) {

		int num = 0;
		for (int i = 0; i < n; i++) {
			bool ck = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (!isUsed[word[i][j] - 'a']) {
					ck = false;
					break;
				}
			}
			if (ck) num++;
		}
		if (result < num) result = num;
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (isUsed[i]) continue;
		isUsed[i] = true;
		findWord(i, cnt + 1);
		isUsed[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	if (k < 5) {
		cout << 0 << "\n";
		return 0;
	}
	else if (k == 26) {
		cout << n << "\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> word[i];
		word[i] = word[i].substr(4);
		word[i] = word[i].substr(0, word[i].length() - 4);
	}

	for (int i = 0; i < 5; i++) isUsed[pre[i] - 'a'] = true;
	findWord(0, 0);

	cout << result << "\n";

	return 0;
}
