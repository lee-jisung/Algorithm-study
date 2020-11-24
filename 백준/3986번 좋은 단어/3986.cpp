#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
   아치가 교차하지 않을 때 => 결국 알파벳끼리 쌍을 이루는 문자열일 경우
*/

int n, result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		string input; cin >> input;
		if (input.length() % 2 != 0) continue;
		
		stack<char> st;

		for (int j = 0; j < input.length(); j++) {
			if (!st.empty() && st.top() == input[j]) {
				st.pop();
			}
			else
				st.push(input[j]);
		}

		if (st.empty()) result++;
	}

	cout << result << "\n";

	return 0;
}
