#include <iostream>
#include <vector>

using namespace std;

/*
   root ~ leaf node까지 거리를 모두 더해서
   홀수면 yes
   짝수면 no
*/

int n, dist;
vector<int> graph[500001];
bool isVisit[500001];

void dfs(int parent, int depth) {
	// leaf node => 방문 전이면서 부모노드 하나가지고 있는 노드가 자식노드
	if (parent!= 1 && !isVisit[parent] && graph[parent].size() == 1) {
		dist += depth;
		return;
	}
	isVisit[parent] = true;
	for (int i = 0; i < graph[parent].size(); i++) {
		int next = graph[parent][i];
		if (isVisit[next]) continue;
		dfs(next, depth + 1);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, 0);

	if (dist % 2 == 0) cout << "No\n";
	else cout << "Yes\n";

	return 0;
}
