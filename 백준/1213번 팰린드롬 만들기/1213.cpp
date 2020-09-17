#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

/*
  사전순상의 펠린드롬 출력

  펠린드롬 => 짝수개의 문자로만 구성되어 있다면 문자별로 (개수/2)개씩 앞에서부터 문자열에 추가, 반대로 뒤집어서 뒤에 이어붙이면 됨
  홀수개인 문자가 1개라도 있다면 짝수개인 문자 (개수/2)씩 붙이고, 마지막에 홀수개인 문자를 붙여줌, 나머지를 반대로 붙여줌
  홀수개인 문자가 1개 이상 => 펠린드롬 불가
  
*/

using namespace std;

string s, res;
vector<pair<char, int>> v;
vector<char> odd;
bool ck;
int alpha[26];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = 0; i < s.length(); i++) alpha[s[i] - 'A']++;

	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 && ck) {
			cout << "I'm Sorry Hansoo\n";
			return 0;
		}
		else if (alpha[i] % 2 && !ck) {
			v.push_back({ i + 'A', alpha[i] });
			odd.push_back(i + 'A');
			ck = true;
		}
		else v.push_back({ i + 'A', alpha[i] });
	}

	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < (v[i].second / 2); j++)
			res += v[i].first;
	for (int i = 0; i < res.length(); i++) cout << res[i];
	if (!odd.empty()) cout << odd[0];
	for (int i = res.length() - 1; i >= 0; i--) cout << res[i];
	cout << "\n";

	return 0;
}
