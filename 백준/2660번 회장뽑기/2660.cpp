#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, res;
int scores[51];
bool isVisit[51];
vector<int> graph[51], candidate;

void bfs(int start) {
	memset(isVisit, false, sizeof(isVisit));
	queue<pair<int, int>> q;
	int score = 0;
	q.push({ start, 0 });
	isVisit[start] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();

		score = max(score, depth);

		for (int i = 0; i < graph[cur].size(); i++) {
			int nxt = graph[cur][i];
			if (isVisit[nxt]) continue;
			isVisit[nxt] = true;
			q.push({ nxt, depth + 1 });
		}
	}
	scores[start] = score;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (1) {
		int a, b; cin >> a >> b;
		if (a == -1 && b == -1) break;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1;i <= n; i++) {
		bfs(i);
	}

	res = INF;
	for (int i = 1; i <= n; i++) 
		res = min(res, scores[i]);

	for (int i = 1; i <= n; i++)
		if (res == scores[i]) candidate.push_back(i);

	cout << res << " " << candidate.size() << "\n";
	for (int i = 0; i < candidate.size(); i++) {
		cout << candidate[i] << " ";
	}
	cout << "\n";

	return 0;
}
