#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
  1. '('을 만나면 Stack에 push
  2. 피연산자 (문자, 숫자 등)을 만나면 출력(or string에 추가)
  3. 연산자 ('+', '-', '*', '/')를 만났을 경우 stack에 현재 연산자 보다 우선순위가 높거나 같은 것을 모두 출력 (or string에 추가)하고 자신을 stack에 push한다.
	- '*', '/'가 '+', '-'보다 우선순위가 높음
	- '*', '/'가 등장할 경우 stack이 비거나 stack의 top이 우선순위가 같은 기호들만 출력(or string 추가) (우선순위가 낮은 것이 나오면 pop 중지)
	- '+', '-'보다 우선순위가 낮은 기호는 없으므로 stack이 비거나 stack의 top이 '('이 나올 때 까지 pop, 출력(추가)
  4. ')'을 만났을 경우 Stack에서 '('가 나올 때까지 pop
  5. stack에 남은 것이 있다면 stack의 전부를 pop해서 출력(추가)

*/

int cnt;
string str, res;
stack<char> st;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') res += str[i];
		else if (str[i] == '(') 
			st.push(str[i]);
		else if (str[i] == ')') {
			while (!st.empty() && st.top() != '(') {
				 res += st.top(); 
				 st.pop();
			}
			st.pop();
		}
		else {
			if (str[i] == '*' || str[i] == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					res += st.top();
					st.pop();
				}
				st.push(str[i]);
			}
			else if (str[i] == '+' || str[i] == '-') {
				while (!st.empty() && st.top() != '(') {
					res += st.top();
					st.pop();
				}
				st.push(str[i]);
			}
		}
	}

	while (!st.empty()) {
		if (st.top() == '(') {
			st.pop();
		}
		else { res += st.top(); st.pop(); }
	}
	cout << res << "\n";

	return 0;
}
