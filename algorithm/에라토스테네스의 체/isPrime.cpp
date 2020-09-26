
// n이 소수인지 아닌지 판별

bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
