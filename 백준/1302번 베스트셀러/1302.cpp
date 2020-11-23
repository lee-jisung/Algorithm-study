#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, maxVal;
string input;
map<string, int> book;
vector<string> result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		cin >> input;
		book[input]++;
		maxVal = max(maxVal, book[input]);
	}

	for (auto iter = book.begin(); iter != book.end(); iter++) {
		if (maxVal == iter->second) {
			result.push_back(iter->first);
		}
	}

	sort(result.begin(), result.end());

	cout << result[0] << "\n";

	return 0;
}
