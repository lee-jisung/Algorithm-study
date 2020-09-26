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

double a, b, result;
double dp[19][19][19];

bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(void) {

	ios_base::sync_with_stdio(0);

	cin >> a >> b;
	a /= 100; b /= 100;

	dp[1][1][1] = a * b;
	dp[1][0][1] = (1 - a) * b;
	dp[1][1][0] = a * (1 - b);
	dp[1][0][0] = (1 - a) * (1 - b);

	for (int i = 2; i < 19; i++) {

		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= i; k++) {
				// a, b, 둘다 못넣은 경우
				dp[i][j][k] += dp[i - 1][j][k] * (1 - a) * (1 - b);
				if (j > 0) // a만 넣은 경우
					dp[i][j][k] += dp[i - 1][j - 1][k] * a * (1 - b);
				if (k > 0) // b만 넣은 경우
					dp[i][j][k] += dp[i - 1][j][k - 1] * (1 - a) * b;
				if (j > 0 && k > 0) // 둘다 넣은 경우
					dp[i][j][k] += dp[i - 1][j - 1][k - 1] * a * b;
			}
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (isPrime(i) || isPrime(j))
				result += dp[18][i][j];
		}
	}

	cout << result << "\n";

	return 0;
}
