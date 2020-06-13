#include <iostream>
#include <queue>
#include <map>

#define INF 1e9

using namespace std;

int a, b;
long long result;
map<long long, bool> isVisit;

void bfs() {
	queue<pair<long long, long long>> q;
	q.push({ a, 1 });
	isVisit[a] = true;

	while (!q.empty()) {

		long long num = q.front().first;
		long long depth = q.front().second;
		q.pop();

		if (num == b) {
			result = depth;
			return;
		}

		if (num > INF) {
			result = -1; continue;
		}

		if (!isVisit[num * 2]) {
			q.push({ num * 2, depth + 1 });
			isVisit[num * 2] = true;
		}

		if (!isVisit[num * 10 + 1]) {
			q.push({ num * 10 + 1, depth + 1 });
			isVisit[num * 10 + 1] = true;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;

	result = -1;
	bfs();

	cout << result << "\n";

	return 0;
}
