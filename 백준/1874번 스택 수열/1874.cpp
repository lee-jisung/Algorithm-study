#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 스택 최상단 값 > 수열 값 => return no

int n, seq[100001];
string str;
stack<int> st1, st2;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> seq[i];

	for (int i = n; i >= 1; i--) st1.push(i);
	for (int i = 0; i < n; i++) {
		int num = seq[i];
		if (st2.empty() || st2.top() < num) {
			while (!st1.empty()) {
				int tmp = st1.top();
				st2.push(tmp); st1.pop();
				str += '+';
				if (tmp == num) break;
			}
			st2.pop(); str += '-';
		}
		else if (st2.top() == num) {
			st2.pop(); str += '-';
		}
		else if (st2.top() > num) {
			cout << "NO\n";
			exit(0);
		}
	}

	for (int i = 0; i < str.length(); i++)
		cout << str[i] << "\n";

	return 0;
}
