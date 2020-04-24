#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

/*
	l개 --> 최소 1개 모음 (a,e,i,o,u) + 최소 2개의 자음, 사전식 정렬 ex) abc (0), bac (x)
*/

int l, c;
char word[16], res[16];

bool isAEIOU() {
	int vow = 0, con = 0;
	for (int i = 0; i < l; i++) {
		if (res[i] == 'a' || res[i] == 'e' || res[i] == 'i' || res[i] == 'o' || res[i] == 'u')
			vow++;
		else con++;
	}
	return vow >= 1 && con >= 2;
}

bool isPos() {
	for (int i = 0; i < l - 1; i++) {
		if (res[i] > res[i + 1])
			return false;
	}
	return true;
}

void backtracking(int a, int b) {
	if (b == l && isAEIOU() && isPos()) {
		for (int i = 0; i < l; i++)
			cout << res[i];
		cout << "\n";
		return;
	}

	for (int i = a; i < c; i++) {
		res[b] = word[i];
		backtracking(i + 1, b + 1);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> word[i];
	sort(word, word + c);
	backtracking(0, 0);

	return 0;
}
