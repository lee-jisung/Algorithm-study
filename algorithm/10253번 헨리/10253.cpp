#include <iostream>

/*
   1/x <= a/b 인 경우 x >= b / a를 만족하는 가장 작은 자연수를 구함
   ex, 1/x <= 5/7 일 경우, x >= 7/5 이므로 x는 2임

   따라서 x는 b를 a로 나눈 몫 + 1임 (b % a가 0이면 +1을 안해줌)
   a => a * x - b로 갱신, b = b * x 로 갱신함

   단, 여기서 갱신했을 때, a/b가 4/12 처럼 약분될 수 있는 경우가 있음
   따라서 gcd로 양쪽을 나누어 줘야 함
*/

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;
	else return gcd(b, a % b);
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int a, b, x; cin >> a >> b;
		while (a != 1) {
			if (b % a == 0) x = b / a;
			else x = (b / a) + 1;
			a = a * x - b; b *= x;
			int g = gcd(a, b);
			a /= g; b /= g;
		}
		cout << b << "\n";
	}

	return 0;
}
