#include <iostream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

/*
   후위표기식
    숫자를 스택에 넣고, 연산자가 나올 경우 2개 pop, 계산 후 결과 값 push
*/

int n;
double val[26];
string input;
stack<double> st;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> input;
	for (int i = 0; i < n; i++) cin >> val[i];

	for (int i = 0; i < input.length(); i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') st.push(val[input[i]-'A']);
		else {
			double num1 = st.top(); st.pop();
			double num2 = st.top(); st.pop();
			switch (input[i]) {
			case '*':
				st.push(num2 * num1);
				break;
			case '+':
				st.push(num2 + num1);
				break;
			case '-':
				st.push(num2 - num1);
				break;
			case '/':
				st.push(num2 / num1);
				break;
			}
		}
	}

	printf("%.2f", st.top());

	return 0;
}
