#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
int parent[100001];
bool isVisit[100001];
vector<int> graph[100001];

void bfs() {
	queue<int> q;
	q.push({ 1 });
	isVisit[1] = true;

	while (!q.empty()) {

		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++) {

			int next = graph[cur][i];
			if (!isVisit[next]) {
				isVisit[next] = true;
				q.push({ next });
				parent[next] = cur;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";

	return 0;
}
