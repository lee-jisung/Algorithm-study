#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;

int main(void) {

	while (getline(cin, str)) {
		if (str.length() == 1 && str[0] == '.') break;
		stack<char> st;
		bool ck = true;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') st.push(str[i]);
			else if ((str[i] == ')' || str[i] == ']') && !st.empty()) {

				if (str[i] == ')' && st.top() == '(') {
					st.pop();
				}
				else if (str[i] == ']' && st.top() == '[') {
					st.pop();
				}
				else {
					ck = false;
					break;
				}
			}
			else if ((str[i] == ')' || str[i] == ']') && st.empty()) {
				ck = false;
				break;
			}
		}
		if (!st.empty()) ck = false;

		if (ck) cout << "yes\n";
		else cout << "no\n";
	}

	return 0;
}
