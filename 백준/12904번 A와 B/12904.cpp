#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/* 
  연산을 반대로 생각 
  기존 연산 => 문자열 마지막에 => A 추가 or 뒤집기 후 B 추가

  ==> 마지막 문자열이 B라면 B 제거 후 문자열 뒤집기 or A라면 A 그냥 제거
  ==> t와 s가 같으면 true, t가 다 없어질때까지 s와 같지않으면 만들기 불가
*/

string s, t;
bool ck;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;

	while (!t.empty()) {
		if (t == s) {
			ck = true;
			break;
		}

		if ('B' == t[t.length() - 1]) {
			t.erase(t.length() - 1, 1);
			reverse(t.begin(), t.end());
		}
		else t.erase(t.length() - 1, 1);
	}

	cout << ck << "\n";

	return 0;
}
