#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <limits.h>

#define SIZE 100001
#define INF 987654321

using namespace std;

int n, m, src, dst, result; 
bool isVisit[SIZE];
vector<pair<int, int> > graph[SIZE];

/*
   최대 중량 -> binary_search로 탐색
   각 중량마다 bfs를 통해서 src에서 dst로 갈 수 있는지 여부 확인
*/

bool bfs(int x) {

	memset(isVisit, false, sizeof(isVisit));
	queue<int > q;
	q.push(src);
	isVisit[src] = true;

	while(!q.empty()) {

		int idx = q.front();
		q.pop();
		if (idx == dst) {
			return true;
		}

		for (int i = 0;i < graph[idx].size(); i++) {
			int island = graph[idx][i].first;
			int weight = graph[idx][i].second;
			if (!isVisit[island] && x <= weight) {
				q.push(island);
				isVisit[island] = true;
			}
		}
	}
	return false;

}

void binary_search(int st, int end) {
	if (st > end) return;
	int mid = (st + end) / 2;
	bool ck = bfs(mid);

	if (ck) {
		result = mid;
		binary_search(mid + 1, end);
	}
	else {
		binary_search(st, mid - 1);
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	cin >> src >> dst;

	binary_search(0, INT_MAX);

	cout << result << "\n";

	return 0;
}
