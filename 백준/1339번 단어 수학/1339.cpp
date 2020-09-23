#include <iostream>
#include <vector>
#include <set>

using namespace std;
 
/*
   각 알파벳마다 숫자 부여 => 모든 경우의 수를 탐색하여 합 구하기
   ==> 시간초과 이유 => pow를 쓰면 시간초과가 났음
*/

int n, alpha[26];
int result;
set<char> c;
vector<string> word;
vector<char> ap;

void dfs(int num, int cnt) {

	if (cnt == ap.size()) {
		int res = 0;
		for (int i = 0; i < word.size(); i++) {
			int sum = 0;
			string w = word[i];
			for (int j = 0; j < w.length(); j++) {
				sum = sum * 10 + alpha[w[j] - 'A']; // 여기서 pow쓰면 시간초과
			}
			res += sum;
		}
		if (result < res) result = res;
		return;
	}

	for (int i = 0; i < ap.size(); i++) {
		if (alpha[ap[i] - 'A'] != 0) continue;
		alpha[ap[i] - 'A'] = num;
		dfs(num - 1, cnt + 1);
		alpha[ap[i] - 'A'] = 0;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s; word.push_back(s);
		for (int j = 0; j < s.length(); j++) c.insert(s[j]);
	}

	for (auto a : c) ap.push_back(a);

	dfs(9, 0);

	cout << result << "\n";

	return 0;
}
