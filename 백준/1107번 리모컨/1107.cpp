#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100
#define INF 1e5

using namespace std;

int n, m, cur, pm, result; 
bool remote[10];

// 임의의 채널 ch가 들어오면 버튼으로 누를 수 있는지 확인
// 누를 수 없는 경우 0 return,
// 누를 수 있는 경우 자리수만큼 리턴

int possibleChannel(int ch) {
	if (ch == 0) {
		if (!remote[ch]) return 0;
		else return 1;
	}

	int press = 0;
	while (ch > 0) {
		if (!remote[ch % 10]) return 0;
		ch /= 10;
		press++;
	}
	return press;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(remote, 1, sizeof(remote));

	cur = 100;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int temp; cin >> temp;
		remote[temp] = false;
	}

	if (n == cur) result = 0;
	else {

		result = abs(n - cur);

		for (int i = 0; i <= 1000000;i++) {
			int press = possibleChannel(i);
			if (press > 0) {
				press += abs(i - n);
				result = min(result, press);
			}
		}
	}

	cout << result << "\n";

	return 0;
}
