#include <iostream>
#include <vector>
#include <string>
#include <stack>

/*
   recursive 
   1. 문자열을 더이상 나누어지지 않는 올바른 괄호열로 나눈다 (ex, (()[[]])([]) => (()[[]]) , ([]) 2개로 나뉨 )
    1.1 예외) ([()(())](())([[]]()))  ()[()] =>  (())([[]]()) 가 나눠질 때  () )([[]]() 이런식으로 나눠지기 때문에
	   단순히 u, v 2개로 문자열을 분리해서 각각 수행하지말고 u, v를 나눈다음에 
	   u는 올바른 괄호열이기 때문에 먼저 처리해주고 다시 v에 대해서 재귀함수를 호출 (v 역시 올바른 함수열로 나눠서 생각해야함)
   2. 올바른 괄호열의 양 끝을 제거, '('면 2를 '['면 3을 곱한다
    2.1 양끝을 제거한 문자열이 올바른 괄호열이고 길이가 2면 해당 괄호열 값만 return
	2.2 길이가 그 이상이고 올바른 괄호열이면 다시 1로
	2.3 만약 올바른 괄호열이 성립이 안된다면 0을 출력, exit();
*/

using namespace std;

int solution(string s) {

	if (s.empty()) return 0;

	stack<char> st;
	string u, v;
	int idx;
	for (idx = 0; idx < s.length(); idx++) {
		if (idx != 0 && st.empty()) break;
		if (s[idx] == '(' || s[idx] == '[') st.push(s[idx]);
		else if (!st.empty() && s[idx] == ')' && st.top() == '(') st.pop();
		else if (!st.empty() && s[idx] == ']' && st.top() == '[') st.pop();
		else {
			cout << "0\n";
			exit(0);
		}
	}

	 //(()() 와 같은 예외 처리
	if (!st.empty()) {
		cout << "0\n";
		exit(0);
	};

	u = s.substr(0, idx);
	v = s.substr(idx);

	int sum = 0;
	if (u.length() > 2 && u[0] == '(') {
		u = u.substr(1, u.length() - 2);
		sum += 2 * solution(u);
	}
	else if (u.length() > 2 && u[0] == '[') {
		u = u.substr(1, u.length() - 2);
		sum += 3 * solution(u);
	}
	else if (u.length() == 2) { 
		if (u[0] == '(') sum += 2;
		else if (u[0] == '[') sum += 3;
		else {cout << 0; exit(0);}
	}
	
	sum += solution(v);

	return sum;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	cout << solution(s);

	return 0;
}
