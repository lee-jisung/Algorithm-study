#include <iostream>
#include <string>

using namespace std;

/*
   res에 문자를 하나씩 추가,
   추가한 문자와 폭파 문자의 끝이 같다면 => 끝에서부터 거꾸로 탐색하여 폭파와 같은 문자열이 추가됐는지 확인
   -> 현재 추가하는 idx가 폭파열 길이보다 작다면 pass 
   - 추가되었다면 idx를 폭파열 길이만큼 줄여주고 다시 해당 idx부터 문자 추가
   - 아니라면 pass
*/
int idx;
string str, boom;
char res[1000001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str >> boom;
	for (int i = 0; i < str.length(); i++) {
		res[idx++] = str[i];
		if (res[idx - 1] == boom[boom.length() - 1]) {
			if (idx < boom.length()) continue;

			bool correct = true;
			for (int j = 0; j < boom.length(); j++) {
				if (res[idx - j - 1] != boom[boom.length() - j - 1]) {
					correct = false;
					break;
				}
			}
			if (correct)
				idx -= boom.length();
		}
	}

	if (!idx) cout << "FRULA\n";
	else {
		for (int i = 0;i < idx; i++) cout << res[i];
		cout << "\n";
	}

	return 0;
}
