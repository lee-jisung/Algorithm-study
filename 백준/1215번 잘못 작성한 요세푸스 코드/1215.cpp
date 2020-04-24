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

long long n, k, m, r; 

/*
    임의의 자연수 j --> k /j >= i > k/(j+1) 인 정수 i에 대해서 k/i의 몫이 j
*/

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	if (n > k) {
		r += k * (n - k);
		n = k;
	}
	m = (long long)sqrt(k);

	for (long long i = 1;i < m;i++) {
		long long left = min(k / i, n), right = k / (i+1) + 1;
		if (left < right) continue;
		r += k * (left - right + 1) - (left + right) * (left - right + 1) * i / 2;
	}
	for (long long i = 1; i <= min(k / m, n); i++)
		r += k % i;

	cout << r << "\n";

	return 0;
}
