#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int n;
bool prime[2000001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	prime[1] = true;
	for (int i = 2; i <= sqrt(2000000); i++) {
		if (!prime[i]) {
			for (int j = i + i; j <= 2000000; j += i)
				prime[j] = true;
		}
	}
	for (int i = n; i <= 1004000; i++) {
		if (!prime[i]) {
			string s = to_string(i);
			string resS = to_string(i);
			reverse(resS.begin(), resS.end());

			if (s == resS) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}
