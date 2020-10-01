#include <iostream>
#include <string>
#include <regex>

using namespace std;

// 정규표현식
//https://docs.microsoft.com/ko-kr/cpp/standard-library/regular-expressions-cpp?view=vs-2019

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	regex re("(100+1+|01)+");
	cmatch m;
	string seq;
	int t;
	cin >> t;
	while (t--) {
		cin >> seq;
		bool ans = regex_match(seq.c_str(), m, re);
		cout << (ans ? "YES\n" : "NO\n");
	}

	return 0;
}
