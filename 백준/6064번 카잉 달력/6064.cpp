#include <iostream>

using namespace std;

int t;
int n, m, x, y;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> m >> n >> x >> y;
		int limit = lcm(n, m);
		// x에 m년씩 더해 가면서
		// 해당 년도 % n년을 했을 때 y 값과 동일할 경우 <x;y>가 구해진 것
		// 단, x+m년이 n, m의 최소공배수를 넘어가면 멸망년도를 넘어간 것이므로 -1 출력
		while (1) {
			// x-1 -> % 연산 결과는 0 ~ n-1 임
			// x = 1 부터 시작하기 때문에 1을 빼준 값을 % 연산해주고 후에 +1을 해줌
			if (x > limit || (x - 1) % n + 1 == y) break;
			x += m;
		}

		if (x > limit) cout << -1 << "\n";
		else cout << x << "\n";
	}

	return 0;
}
