#include <iostream>
#include <cmath>
#include <map>

using namespace std;

/*
   DP (top-down)
   map을 활용하여 n/p, n/q값이 정해져 있으면 return
   정해져 있지 않다면 재귀를 통해 구하기
*/

long long n, p, q;
map<long long, long long> val;

long long infiniteSeq(long long n) {
	if (val.find(n) != val.end()) return val[n];
	return val[n] = infiniteSeq(n / p) + infiniteSeq(n / q);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p >> q;
	val[0] = 1;
	cout << infiniteSeq(n);

	return 0;
}
