#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k, result;
bool isUsed[26];
string words[50];
vector<char> pre = { 'a', 'c', 't', 'n', 'i' };

void findWords(int cur, int cnt) {
	if (cnt == k - 5) {
		int num = 0;
		for (int i = 0; i < n; i++) {
			bool ck = true;
			for (int j = 0; j < words[i].length(); j++) {
				if (!isUsed[words[i][j] - 'a']) {
					ck = false;
					break;
				}
			}
			if (ck) num++;
		}
		if (result < num) result = num;
		return;
	}

	for (int i = cur; i < 26; i++) {
		if (isUsed[i]) continue;
		isUsed[i] = true;
		findWords(i, cnt + 1);
		isUsed[i] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	if (k < 5) {
		cout << 0 << "\n";return 0;
	}
	if (k == 26) {
		cout << n << "\n";
		return 0;
	}

	for (int i = 0; i < 5; i++)
		isUsed[pre[i] - 'a'] = true;

	for (int i = 0; i < n; i++) {
		cin >> words[i];
		words[i] = words[i].substr(4);
		words[i] = words[i].substr(0, words[i].length() - 4);
	}

	findWords(0, 0);

	cout << result << "\n";

	return 0;
}
