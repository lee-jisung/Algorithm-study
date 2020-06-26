#include <iostream>
#include <string>

using namespace std;

/*  mod 연산 속성 

1. (a + b) mod n = {(a mod n) + (b mod n)} mod n

2. (a - b) mod n = {(a mod n) - (b mod n)} mod n

3. (a * b) mod n = {(a mod n) * (b mod n)} mod n
*/

string s;
int L, r, M;
long long sum, R;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	r = 31; M = 1234567891;
	R = 1;
	cin >> L >> s;

	for (int i = 0; i < L; i++) {
		sum = (sum + (s[i] - 'a' + 1) * R) % M;
		R = (R * r) % M;
	}

	cout << sum << "\n";

	return 0;
}
