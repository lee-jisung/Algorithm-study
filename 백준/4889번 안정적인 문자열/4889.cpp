#include <iostream>
#include <stack>

using namespace std;

/*
   1. { 를 만났을 땐 stack에 push
   2. stack이 비어있지 않고 }를 만나면 stack pop
   3. stack이 비어있을 때 }를 만나면 { 로 stack에 넣어주고 바꿔주는 연산 수 + 1해줌

   4. string 체크 후 stack에 {{{..들이 쌓여있다면 {를 }로 바꿔주는 연산을 stack size의 1/2만큼 하면 됨
   따라서 cnt += s.size()/2를 추가해주고 출력해주면 끝
*/

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int idx = 1;
	while (1) {
		string str;
		stack<char> s;

		cin >> str;

		if (str[0] == '-') break;
		int cnt = 0;
		for (int i = 0; i < str.length(); i++) {

			if (str[i] == '{') s.push(str[i]);
			else if (str[i] == '}' && !s.empty()) s.pop();
			else if (str[i] == '}' && s.empty()) {
				s.push('{');
				cnt++;
			}
		}

		cnt += s.size() / 2;

		cout << idx << ". " << cnt << "\n";
		idx++;
	}

	return 0;
}
