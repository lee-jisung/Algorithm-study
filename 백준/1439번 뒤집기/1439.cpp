#include <iostream>
#include <string>

// 맨 앞 & 뒤 숫자가 같으면 다른것들만 바꿔주기
// 다르면 뒤 숫자와 다른 수를 앞에서부터 뒤집기

using namespace std;

int main(void) {

	string str;
	cin >> str;

	int cnt = 0;

	if (str[0] == str[str.length() - 1]) {
		for (int i = 1; i < str.length(); i++) {
			if (str[i] != str[i - 1] && str[i] != str[0]) cnt++;
		}
	}
	else {
		int ck = str[str.length() - 1];
		for (int i = 0; i < str.length()-1; i++) {
			if (ck != str[i] && str[i] != str[i + 1]) cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}
