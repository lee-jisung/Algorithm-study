#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, cnt;
string s, pat;

vector<int> makeTable() {
	vector<int> table(pat.length(), 0);
	int j = 0;
	for (int i = 1; i < pat.length(); i++) {
		while (j > 0 && pat[i] != pat[j])
			j = table[j - 1];
		if (pat[i] == pat[j])
			table[i] = ++j;
	}
	return table;
}

void KMP() {

	vector<int> table = makeTable();
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		while (j > 0 && s[i] != pat[j]) {
			j = table[j - 1];
		}
		if (s[i] == pat[j]) {
			if (j == pat.length() - 1) {
				j = table[j];
				cnt++;
			}
			else j++;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s;
	pat = "I";
	for (int i = 0; i < n; i++) pat += "OI";

	KMP();
	cout << cnt << "\n";

	return 0;
}
