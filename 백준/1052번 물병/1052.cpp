#include <iostream>

using namespace std;

int n, k;
int res;

// 병을 합치면서 합쳐지지 못하는 물병들을 count해서 return
int cal(int x) {
	int cnt = 0;
	while (x > 0) {
		if (x % 2 == 1) cnt++;
		x /= 2;
	}
	return cnt;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	while (1) {
		
		int bottle = cal(n); //합쳐지지못한 물병이 목표하는 k개수보다 적다면 중지
		if (bottle <= k) break;
		res++;
		n++; // 물병을 1개씩 늘려가보면서 확인 => 상점에서 1개씩 사보는것임

	}
	
	cout << res << "\n";

	return 0;
}
