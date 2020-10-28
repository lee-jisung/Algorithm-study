#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

// abcde 
// abcdea, abcdeba, abcdecba 의 식으로 끝에 앞에서부터 i번째부터 0번째까지 다시 뒤에 이어붙이면서 확인

string input;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> input;

	for (int i = 0; i < input.length(); i++) {
		string str = input, rev;
		for (int j = 0; j < i; j++) {
			str += input[i - j - 1];
		}
		rev = str;
		reverse(rev.begin(), rev.end());
		if (rev == str) {
			cout << rev.length();
			break;
		}
	}

	return 0;
}
