#include <iostream>

using namespace std;

/*
   a^n * a^n = a^2n 의 원리를 이용
 */

long long mul(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	long long tmp = mul(a, b / 2, c);
	tmp = tmp * tmp % c;
	if (b % 2 == 0) return tmp; // b가 짝수면 tmp 제곱한걸 그대로 return
	return tmp * a % c; // b가 홀수 일 경우 a를 한번 더 곱해서 %c한 후 return
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long a, b, c;
	cin >> a >> b >> c;
	cout << mul(a, b, c);

	return 0;
}
