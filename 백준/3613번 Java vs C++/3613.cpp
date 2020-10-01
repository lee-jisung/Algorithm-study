#include <iostream>
#include <string>

using namespace std;

/*
   cpp 예외
     => 맨앞, 맨 뒤가 '_' 일 때
	 => 대문자 포함
	 => __ 연속으로 있을 때

   java 예외
     => _ 포함할 때
	 => 맨앞 글자 대문자일 때
*/

string str, res;
bool cpp, java, error;

bool judgeCpp() {
	if (str[0] == '_' || str[str.length() - 1] == '_') return false;
	if (str.find("__") != string::npos) return false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') return false;
	}
	return true;
}

bool judgeJava() {
	if (str.find('_') != string::npos) return false;
	if (str[0] >= 'A' && str[0] <= 'Z') return false;
	return true;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;

	cpp = judgeCpp();
	java = judgeJava();
	if (cpp) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '_') {
				res += toupper(str[i + 1]); i++;
			}
			else res += str[i];
		}
		cout << res << "\n";
	}
	else if (java) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				res += '_';
				res += tolower(str[i]);
			}
			else res += str[i];
		}
		cout << res << "\n";
	}
	else {
		cout << "Error!\n";
	}
	return 0;
}
