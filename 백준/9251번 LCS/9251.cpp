#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1001
#define INF 987654321

using namespace std;

int lcs[SIZE][SIZE];

string a, b;
string str1, str2;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	str1 = '0' + a;
	str2 = '0' + b;

	for (int i = 1; i < str1.length(); i++) {
		for (int j = 1; j < str2.length(); j++) {
			if (str1[i] == str2[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}

	cout << lcs[str1.length()-1][str2.length()-1];
	return 0;
}
