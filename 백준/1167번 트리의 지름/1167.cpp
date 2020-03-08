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

int v, vertex, result, idx;
int dist[SIZE];
bool isVisit[SIZE];

vector<pair<int, int> > graph[SIZE];

// 트리의 지름
// 임의의 점 n1에서 가장 먼 정점 v1을 찾고
// v1에서 가장 먼 정점 v2를 찾음
// v1 ~ v2 까지의 길이가 트리의 지름이 됨.

void bfs(int x) {

	queue<int> q;
	q.push(x);
	isVisit[x] = true;

	while (!q.empty()) {
		int ver = q.front();
		q.pop();

		for (int i = 0; i < graph[ver].size(); i++) {
			int nVer = graph[ver][i].first;
			if (!isVisit[nVer]) {
				dist[nVer] = dist[ver] + graph[ver][i].second;
				isVisit[nVer] = true;
				q.push(nVer);
			}
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> v;

	for (int i = 0; i < v; i++) {
		cin >> vertex;
		vector<int> temp;
		while (1) {
			int n;
			cin >> n;
			if (n == -1) break;
			temp.push_back(n);
		}

		for (int j = 0; j < temp.size(); j += 2)
			graph[vertex].push_back({ temp[j], temp[j + 1] });
	}

	bfs(1);
	for (int i = 1; i <= v; i++) {
		if (result < dist[i]) {
			result = dist[i];
			idx = i;
		}
	}

	memset(isVisit, false, sizeof(isVisit));
	memset(dist, 0, sizeof(dist));
	result = 0;
	bfs(idx);

	for (int i = 1; i <= v; i++)
		result = max(result, dist[i]);

	cout << result << "\n";

	return 0;
}
