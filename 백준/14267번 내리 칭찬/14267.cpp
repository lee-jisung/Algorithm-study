#include <iostream>
#include <vector>

using namespace std;

/*
   칭찬받은 직원에 점수만 + 해서 누적하고
   1번부터 dfs로 탐색하면서 부모노드의 점수를 자신의 점수에 + 해서 누적해가면 됨
*/

int n, m;
vector<int> graph[100001];
int compliment[100001];

void getCompliment(int root) {
	if (graph[root].empty()) return;

	for (int i = 0; i < graph[root].size(); i++) {
		int next = graph[root][i];
		compliment[next] += compliment[root];
		getCompliment(next);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		if (num == -1) continue;
		graph[num].push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int idx, w; cin >> idx >> w;
		compliment[idx] += w;
	}

	getCompliment(1);

	for (int i = 1; i <= n; i++) {
		cout << compliment[i] << " ";
	}
	cout << "\n";

	return 0;
}
