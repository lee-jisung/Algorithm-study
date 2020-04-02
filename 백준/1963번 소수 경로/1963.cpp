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

/*
   4자리 -> bfs에서 각 한자리를 바꿀 때 마다 큐에 push
   바꾼 수가 소수임을 유지
   각 자리수 마다 0 ~ 9 (천의 자리 - 1 ~9) 씩 돌면서
   소수인지 확인해서 큐에 넣기
*/

using namespace std;

struct node {
	int p;
	int depth;
};

int tc, n, m, prime[SIZE]; 
bool isVisit[SIZE];

int bfs() {

	queue<node> q;
	q.push({ n, 0 });
	isVisit[n] = true;

	while (!q.empty()) {

		int p = q.front().p;
		int depth = q.front().depth;
		q.pop();

		if (p == m) {
			return depth;
		}

		for (int i = 0; i < 4; i++) {
			string str = to_string(p);
			for (int j = 0; j <= 9; j++) {
				if (i == 0 && j == 0 || str[i] - '0' == j) continue;
				str[i] = j + '0';
				int temp = stoi(str);
				if (prime[temp] && !isVisit[temp]) {
					q.push({ temp, depth + 1 });
					isVisit[temp] = true;
				}
			}

		}
	}
	return -1;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	for (int i = 2; i < SIZE; i++)
		prime[i] = i;
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i]) {
			for (int j = i + i; j < SIZE; j += i)
				prime[j] = 0;
		}
	}

	while (tc--) {
		memset(isVisit, false, sizeof(isVisit));
		cin >> n >> m;
		int res = bfs();
		if (res < 0) cout << "Impossible\n";
		else cout << res << "\n";
	}


	return 0;
}
