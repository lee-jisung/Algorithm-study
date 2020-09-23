#include <iostream>

/*
   v일 => p일중 l일 누적, 남은 휴가일 => p일보다 적을때
   남은 휴가일 vs l일 중 더 적은 것을 day에 누적
*/

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int cnt = 0;
	while (1) {
		int l, p, v, day = 0;
		cin >> l >> p >> v;
		if (!l && !p && !v) break;

		while (v > p) {
			day += l;
			v -= p;
		}
		v >= l ? day += l : day += v;
		cout << "Case " << ++cnt << ": " << day << "\n";
	}
	return 0;
}
