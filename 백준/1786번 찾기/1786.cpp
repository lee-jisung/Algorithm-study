#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cnt;
vector<int> pos;
string parent, pattern;

vector<int> makeTable() {
	vector<int> table(pattern.length(), 0);
	int j = 0;
	for (int i = 1; i < pattern.length(); i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = table[j - 1];
		if (pattern[i] == pattern[j])
			table[i] = ++j;
	}
	return table;
}

void KMP() {
	vector<int> table = makeTable();
	int j = 0;
	for (int i = 0; i < parent.length(); i++) {
		while (j > 0 && parent[i] != pattern[j])
			j = table[j - 1];
		if (parent[i] == pattern[j]) {
			if (j == pattern.length() - 1) {
				pos.push_back(i - (j-1));
				cnt++;
				j = table[j];
			}
			else j++;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, parent);
	getline(cin, pattern);
	KMP();
	cout << cnt << "\n";
	for (int i = 0; i < pos.size(); i++)
		cout << pos[i] << " ";

	return 0;
}
