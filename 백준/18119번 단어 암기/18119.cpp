#include <iostream>

using namespace std;

/*
   단어 별로 1 << alphabet 을 사용해서 수로 저장
   1111111...111 (26개) 인 alpha를 이용해서 
   1이 들어오면 ~( 1 << x )과 &를 이용해서 alpha에서 1을 지움
   2가 들어오면 (1 << x), | 를 이용해서

*/

int n, m, cnt;
int alpha = 0xffffffff, word[10001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < tmp.length(); j++) {
			word[i] |= 1 << (tmp[j] - 'a');
		}
	}

	while (m--) {
		int o; char x;
		cnt = 0;

		cin >> o >> x;
		if (o == 1) {
			alpha &= ~(1 << (x - 'a'));
		}
		else {
			alpha |= (1 << (x - 'a'));
		}
		
		for (int i = 0; i < n; i++) {
			if ((word[i] & alpha) == word[i]) cnt++;
		}
		cout << cnt << "\n";
	}
	return 0;
}
