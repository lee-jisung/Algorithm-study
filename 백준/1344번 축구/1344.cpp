#include <iostream>
#include <cmath>

using namespace std;

/*
   90분 => 5분 간격 => 18 간격
   dp[현재][a골수][b골수]
   1. a 골 o, b골 o => dp[n][a][b] = a * b * dp[n-1][a-1][b-1]  // a-1골수, b-1골수에서 둘 다 넣었으니 a, b확률 곱한것
   2. a 골 x, b골 o => dp[n][a][b] = (1-a) * b * dp[n-1][a][b-1]
   3. a 골 o, b골 x => dp[n][a][b] = a * (1 - b) * dp[n-1][a-1][b]
   4. a 골 x, b골 x => dp[n][a][b] = (1-a) * (1-b) * dp[n-1][a-1][b-1]
 */

double A, B, result;
double dp[19][19][19];

bool isPrime(int x) {
	if (x == 0 || x == 1) return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) return false;
	}
	return true;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;
	A /= 100; B /= 100;

	dp[1][1][1] = A * B ;
	dp[1][1][0] = A * (1 - B);
	dp[1][0][1] = (1 - A) * B;
	dp[1][0][0] = (1 - A) * (1 - B);

	for (int i = 2; i < 19; i++) {
		for (int a = 0; a <= i; a++) {
			for (int b = 0; b <= i; b++) {
				dp[i][a][b] += (1 - A) * (1 - B) * dp[i - 1][a][b];
				if (a > 0) // a가 넣었을 때
					dp[i][a][b] += A * (1-B) * dp[i - 1][a - 1][b];
				if (b > 0) // b가 넣었을 때
					dp[i][a][b] += (1-A) * B * dp[i - 1][a][b - 1];
				if (a > 0 && b > 0) // a, b 둘다 넣었을 때
					dp[i][a][b] += A * B * dp[i - 1][a - 1][b - 1];
			}
		}
	}

	for (int a = 0; a < 19; a++) {
		for (int b = 0; b < 19; b++) {
			if (isPrime(a) || isPrime(b))
				result += dp[18][a][b];
		}
	}

	cout << result << "\n";
	return 0;
}
