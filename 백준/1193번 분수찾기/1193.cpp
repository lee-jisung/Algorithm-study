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

/*
   대각선 줄 마다 분모+분자 = 2, 3, 4, 5, 6...
   cnt는 각 대가선 줄의 마지막 번호 값을 나타내고 x보다 cnt가 커지는 순간 x는 해당 대각선에 포함
   분모+분자 % 2 == 1이면 위에서 아래로 0이면 아래에서 위로 올라가는 순서
   --> 1일때는 child = sum-1 parent = 1 --> child--, parent++
       0일 때 parent = sum-1, child=1 --> parent--, child ++
	   cnt-- --> x와 같아지는 순간 break
*/

using namespace std;

int x, sum, n, child, parent;
long long cnt;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x;
	sum = n = child = parent = 1;

	if (x == 1) {
		cout << "1/1\n";
		return 0;
	}

	while (1) {
		sum++;
		cnt += n;
		if (cnt >= x) break;
		n++;
	}

	if (sum % 2)
		child = sum - 1;
	else
		parent = sum - 1;
	
	while (1) {

		if (cnt == x) break;
		if (sum % 2) {
			child--;
			parent++;
		}
		else {
			child++;
			parent--;
		}
		cnt--;
	}
	
	cout << child << "/" << parent << "\n";
	return 0;
}
