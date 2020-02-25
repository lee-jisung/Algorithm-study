#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 1000001
#define INF 1e5

using namespace std;

// 숨박꼭질 문제 시리즈와 똑같은 유형의 BFS

int f, s, g, u, d, result;
bool isVisit[SIZE];

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> f >> s >> g >> u >> d;

	queue<pair<int, int > > q;
	q.push({ s, 0 });
	isVisit[s] = true;
	result = -1;

	while (!q.empty()) {

		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (cur == g) {
			result = depth;
			break;
		}

		if (cur + u <= f && !isVisit[cur + u]) {
			q.push({ cur + u, depth + 1 });
			isVisit[cur + u] = true;
		}
		if (cur - d >= 1 && !isVisit[cur - d]) {
			q.push({ cur - d, depth + 1 });
			isVisit[cur - d] = true;
		}
	}

	if (result == -1)
		cout << "use the stairs\n";
	else
		cout << result << "\n";


	return 0;
}
