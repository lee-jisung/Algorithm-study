#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 10001
#define INF 987654321

using namespace std;

struct node {
	int ver;
	int depth;
};

int n, sum, result;
int n1, n2, w;
int dist[SIZE];
bool isVisit[SIZE];

vector<node> v[SIZE];

void bfs(int x) {

	queue<int> q;
	q.push(x);
	isVisit[x] = true;

	while (!q.empty()) {

		int vertex = q.front();
		q.pop();

		for (int i = 0; i < v[vertex].size(); i++) {
			int nVer = v[vertex][i].ver;
			if (!isVisit[nVer]) {
				dist[nVer] = dist[vertex] + v[vertex][i].depth;
				isVisit[nVer] = true;
				q.push(nVer);
			}
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> n1 >> n2 >> w;
		v[n1].push_back({ n2, w });
		v[n2].push_back({ n1, w });
	}

	for (int i = 1; i <= n; i++) {
		memset(isVisit, false, sizeof(isVisit));
		memset(dist, 0, sizeof(dist));
		bfs(i);
		for (int i = 1; i <= n; i++)
			result = max(result, dist[i]);
	}
	cout << result << "\n";

	return 0;
}

