#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T;
string input;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> input;
		if (next_permutation(input.begin(), input.end())) {
			cout << input << "\n";
		}
		else {
			prev_permutation(input.begin(), input.end());
			cout << input << "\n";
		}
	}

	return 0;
}
