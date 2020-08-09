#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <tuple>

#define INF 1e9
using namespace std;

/*
   MST -> 연결할 때 마다 n 개수를 줄여서 2개가 되면 마을이 2개가 된 것이므로 연결 중지하고 
          cost 합 출력
*/

typedef pair<int, int> PAIR;
typedef tuple<int, int, int> TUPLE;

int n, m, result;
int parent[100001];
set<int> village;
vector<TUPLE> graph;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		graph.push_back({ c, a, b });
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); i++) {
		auto cur = graph[i];
		int cost = get<0>(cur);
		int node1 = get<1>(cur);
		int node2 = get<2>(cur);
		if (!findParent(node1, node2)) {
			unionParent(node1, node2);
			result += cost;
			if (--n == 2) break;
		}
	}

	cout << result << "\n";

	return 0;
}
