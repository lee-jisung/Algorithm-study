#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 10001
#define INF 987654321

using namespace std;

int tc, n, m; 
pair<int, char> dslr[SIZE];
bool isVisit[SIZE];

int D(int num) {
	return (num * 2) % 10000;
}

int S(int num) {
	int temp = num - 1;
	if (temp < 0) return 9999;
	return temp;
}

// 1234 -> 2341
int L(int num) {
	return (num % 1000) * 10 + (num / 1000);
}

// 1234 -> 4123
int R(int num) {
	return (num % 10) * 1000 + (num / 10);
}

// DSLR 함수를 이용하여 새로운 num을 만들때마다 새롭게 만들어진 num값에
// 이전 num값과 이용한 연산을 넣은 배열을 역추적
void print(int num) {
	if (dslr[num].first == -1) return;
	print(dslr[num].first);
	cout << dslr[num].second;
}

void bfs() {

	queue<int> q;
	q.push(n);
	dslr[n] = { -1, '\n' };
	isVisit[n] = true;

	while (!q.empty()) {

		int num = q.front();
		q.pop();
		if (num == m) {
			print(num);
			cout << "\n";
			break;
		}

		if (!isVisit[D(num)]) {
			q.push(D(num));
			isVisit[D(num)] = true;
			dslr[D(num)] = { num, 'D' };
		}
		if (!isVisit[S(num)]) {
			q.push(S(num));
			isVisit[S(num)] = true;
			dslr[S(num)] = { num, 'S' };
		}
		if (!isVisit[L(num)]) {
			q.push(L(num));
			isVisit[L(num)] = true;
			dslr[L(num)] = { num, 'L' };
		}
		if (!isVisit[R(num)]) {
			q.push(R(num));
			isVisit[R(num)] = true;
			dslr[R(num)] = { num, 'R' };
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		
		memset(isVisit, false, sizeof(isVisit));
		cin >> n >> m;
		bfs();
	}
	return 0;
}
