#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 20001
#define INF 987654321

using namespace std;

int tc, n;
pair<int, char> arr[SIZE];
bool isVisit[SIZE];

/*
   queue 맨앞 숫자에 ( * 10) 을 한 숫자와 ( * 10 + 1)을 한 숫자를 넣어주면 1과0으로 이루어진 수가 계속 추가됨
   overflow 방지 위해 n으로 나눈 나머지를 큐에 넣음
*/

void bfs() {
	queue<int> q;
	q.push(1);
	isVisit[1] = true;
	arr[1].first = -1;
	arr[1].second = '1';

	while (!q.empty()) {

		int num = q.front();
		//cout << num << " ";
		q.pop();

		int p[2];
		p[0] = (num * 10) % n;
		p[1] = (p[0] + 1) % n;

		for (int i = 0; i < 2; i++) {
			if (!isVisit[p[i]]) { // 이미 큐에 넣었던 수는 pass
				arr[p[i]].first = num;
				arr[p[i]].second = i + '0';
				//n으로 나누어 떨어지면 bfs 중단
				//cout << p[i] << " " << num << " " << i << "\n";
				if (!p[i]) return;
				isVisit[p[i]] = true;
				q.push(p[i]);
			}
		}
	}
}

// 역순으로 추적해가며 출력
void print(int num) {
	if (num == -1) return;
	print(arr[num].first);
	cout << arr[num].second;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n == 1) {
			cout << 1 << "\n";
			continue;
		}
		memset(isVisit, false, sizeof(isVisit));

		bfs();
		print(0);
		cout << "\n";

	}

	return 0;
}
