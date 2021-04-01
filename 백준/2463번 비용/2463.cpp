/*
   1. 간선을 내림차순으로 정렬
   2. 가중치가 큰 간선부터 연결하면서
		간선으로 연결된 노드 = 같은 집합
		연결되지 않은   노드 = 다른 집합
	  2가지 경우로 간주하여 답 구하기
   3. 서로다른 집합이었던 노드들이 같은 집합이 될 때 Cost(u, v)를 구함 (u < v)

	  - cost(u, v) = u, v를 연결하는 간선이 없어질때 까지 간선 가중치 최솟값부터 없앨때의 가중치 총 합

	  - ex) 3-6 (15) / 1-2(10)이 연결되어 있을때,
			2-6(6)이 연결되는 순간이라고 하면, cost(2,3), cost(2,6), cost(1,3), cost(1,6)의 경우를 모두 구할 수 있음
	  - 위의 결과는 (u의 집합 크기 * v의 집합 크기) * (전체 가중치 합 - 이어진 가중치 합) 으로 구할 수 있음

   4. 내림차순으로 정렬한 간선을 연결할 때, 연결할 두 노드가 서로 다른 집합일때
	  위의 공식을 적용하여 가중치를 누적하여 답을 구함.
*/
#include <iostream>
#include <queue>

#define MOD 1000000000

using namespace std;

struct edge {
	int node1;
	int node2;
	int weight;
};

bool operator<(edge a, edge b) {
	return a.weight < b.weight;
}

int n, m, parent[100001];
long long totalWeight, result, setSize[100001]; // long long 처리 잘할것.
priority_queue<edge> Edge;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// u < v
void unionParent(int u, int v) {
	parent[v] = u;
	setSize[u] += setSize[v];
	setSize[v] = 1;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		setSize[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		Edge.push({ x, y, w });
		totalWeight += w;
	}

	while (!Edge.empty()) {

		edge e = Edge.top();
		Edge.pop();

		int n1 = getParent(e.node1);
		int n2 = getParent(e.node2);

		if (n1 != n2) {
			result += (((setSize[n1] * setSize[n2]) % MOD) * totalWeight) % MOD;
			result %= MOD;
			unionParent(n1, n2);
		}
		totalWeight -= e.weight;
	}

	cout << result << "\n";

	return 0;
}
