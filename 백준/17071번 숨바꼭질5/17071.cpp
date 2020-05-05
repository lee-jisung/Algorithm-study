#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 500001
#define INF 1e9

using namespace std;

/* 
   k+1, k+1+2, ... 씩 증가하기 때문에 500000을 넘어가는경우는 1000까지 이므로 가중치가 1000일때까지 방문처리를 했을 때 시간초과

   +1, -1의 위치로 이동할 때 짝수 or 홀수 초 일때 방문했던 곳을 재방문 할수잇음 즉, 2턴을 지나면 제자리로 돌아올 수 있음
   따라서 (짝수 or 홀수 초 후에) 이전에 방문했던 곳에 --> 현재의 동생의 위치가 해당되면 --> 해당 시간에 만날 수 있음
*/

struct node {
	int pos;
	int weight;
	int time;
	int brother;
};

int n, k, result; 
bool isVisit[SIZE][2];
//bool isVisit[SIZE][1000] // << 시간 초과 발생

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	queue<node> q;
	q.push({ n, 0, 0, k});
	isVisit[n][0] = true;

	while (!q.empty()) {

		int pos = q.front().pos;
		int time = q.front().time;
		int bro = q.front().brother;
		int weight = q.front().weight;
		bro += weight;
		q.pop();

		if (bro > SIZE) {
			result = -1;
			break;
		}

		if (pos == bro || isVisit[bro][(time % 2)]) { // 현재 위치와 동생 위치가 같거나 동생이 현재 방문중인 곳을 왔다면
			result = time;
			break;
		}
		
		if (pos + 1 < SIZE && !isVisit[pos + 1][(time+1)%2]) {
			q.push({ pos + 1, weight + 1, time + 1, bro });
			isVisit[pos + 1][(time + 1) % 2] = true;
		}
		if (pos - 1 >= 0 && !isVisit[pos - 1][(time + 1) % 2]) {
			q.push({ pos - 1, weight + 1, time + 1, bro });
			isVisit[pos - 1][(time + 1) % 2] = true;
		}
		if (pos * 2 < SIZE && !isVisit[pos * 2][(time + 1) % 2]) {
			q.push({ pos * 2, weight + 1, time + 1, bro });
			isVisit[pos * 2][(time + 1) % 2] = true;
		}
	}

	cout << result << "\n";

	return 0;
}
