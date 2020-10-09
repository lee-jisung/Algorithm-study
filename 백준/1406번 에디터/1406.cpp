#include <iostream>
#include <stack>
#include <string>

using namespace std;

int m;
string initString, result;
stack<char> input, backup;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> initString >> m;
	for (int i = 0; i < initString.length(); i++)
		input.push(initString[i]);

	for (int i = 0; i < m; i++) {
		char order; cin >> order;
		switch(order) {
			case 'P':
				char c; cin >> c;
				input.push(c);
				break;
			case 'L':
				if (input.empty()) break;
				backup.push(input.top());
				input.pop();
				break;
			case 'D':
				if (backup.empty()) break;
				input.push(backup.top());
				backup.pop();
				break;
			case 'B':
				if (input.empty()) break;
				input.pop();
				break;
		}
	}
	// 출력시 input을 반대로 backup에 다 넣어서
	// backup을 출력하면 변환된 string 출력
	while (!input.empty()) {
		backup.push(input.top());
		input.pop();
	}
	
	while (!backup.empty()) {
		cout << backup.top();
		backup.pop();
	}

	return 0;
 }
