#include <iostream>
#include <string>
#include <stack>

using namespace std;

int tc;
stack<char> input, backup;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {

		string testString;
		cin >> testString;

		for (int i = 0; i < testString.length(); i++) {
			char c = testString[i];
			if (c == '<') {
				if (input.empty()) continue;
				backup.push(input.top());
				input.pop();
			}
			else if (c == '>') {
				if (backup.empty()) continue;
				input.push(backup.top());
				backup.pop();
			}
			else if (c == '-') {
				if (input.empty()) continue;
				input.pop();
			}
			else {
				input.push(c);
			}
		}

		while (!input.empty()) {
			backup.push(input.top());
			input.pop();
		}
		while (!backup.empty()) {
			cout << backup.top();
			backup.pop();
		}
		cout << "\n";
	}


	return 0;
}
