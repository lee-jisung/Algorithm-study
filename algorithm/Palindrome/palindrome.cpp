#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	string s = to_string(n);
	string resS = to_string(n);
	reverse(resS.begin(), resS.end());

	if (s == resS) {
		cout << "TRUE\n";
	}
	else {
		cout << "FALSE\n";
	}
	return 0;
}
