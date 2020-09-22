#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

/*
  E와 W가 연속된 부분의 개수 찾기
*/

int n, cnt;
string load;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> load;

	for (int i = 0; i < n; i++) {
		if (load[i] == 'E' && load[i + 1] == 'W') {
			cnt++;
			i++;
		}
	}

	cout << cnt << "\n";

	return 0;
}
