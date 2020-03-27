#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100
#define INF 987654321

using namespace std;

int cnt[26], t;
string s;

int main(void) {

	while (cin >> s) {
		for (int i = 0; i < s.length(); i++)
			if (s[i] >= 'a' && s[i] <= 'z')
				cnt[s[i] - 'a']++;
		s.clear();
	}
	for (int i = 0; i < 26;i++)
		t = max(t, cnt[i]);

	for (int i = 0; i < 26; i++) {
		if (t == cnt[i]) cout << (char)(i + 'a');
	}
	cout << "\n";

	return 0;
}
