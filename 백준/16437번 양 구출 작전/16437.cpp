#include <iostream>
#include <vector>

using namespace std;

/*
   leaf node에서부터 양의 수를 합하면서 올라오는식으로 탐색
*/

int n;
vector<int> graph[123457];
pair<char, int> island[123457];

long long dfs(int cur) {

	if (graph[cur].size() == 0) {
		if (island[cur].first == 'S')
			return island[cur].second;
		return 0;
	}

	long long sheep = 0;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		sheep += dfs(next);
	}

	if (island[cur].first == 'W') {
		sheep -= island[cur].second;
		if (sheep < 0) sheep = 0;
	}
	else sheep += island[cur].second;
	return sheep;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 2; i <=n; i++) {

		char t; int a, p;
		cin >> t >> a >> p;
		island[i] = { t, a };
		graph[p].push_back(i);
	}

	cout << dfs(1) << "\n";

	return 0;
}
