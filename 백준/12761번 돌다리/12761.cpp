#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100001
#define INF 987654321

using namespace std;

int a, b, n, m;

bool isVisit[SIZE];

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> a >> b >> n >> m;

	queue<pair<int, int > > q;
	q.push({ n, 0 });
	isVisit[n] = true;

	while (!q.empty()) {

		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (cur == m) {
			cout << depth << "\n";
			break;
		}

		if (cur - 1 >= 0 && !isVisit[cur - 1]) {
			q.push({ cur - 1, depth + 1 });
			isVisit[cur - 1] = true;
		}
		if (cur + 1 < SIZE && !isVisit[cur + 1]) {
			q.push({ cur + 1, depth + 1 });
			isVisit[cur + 1] = true;
		}

		if (cur - a >= 0 && !isVisit[cur - a]) {
			q.push({ cur - a, depth + 1 });
			isVisit[cur - a] = true;
		}
		if (cur + a < SIZE && !isVisit[cur + a]) {
			q.push({ cur + a, depth + 1 });
			isVisit[cur + a] = true;
		}

		if (cur - b >= 0 && !isVisit[cur - b]) {
			q.push({ cur - b, depth + 1 });
			isVisit[cur - b] = true;
		}
		if (cur + b < SIZE && !isVisit[cur + b]) {
			q.push({ cur + b, depth + 1 });
			isVisit[cur + b] = true;
		}

		if (cur * a < SIZE && !isVisit[cur * a]) {
			q.push({ cur * a, depth + 1 });
			isVisit[cur * a] = true;
		}

		if (cur * b < SIZE && !isVisit[cur * b]) {
			q.push({ cur * b, depth + 1 });
			isVisit[cur * b] = true;
		}
	}

	return 0;
}
