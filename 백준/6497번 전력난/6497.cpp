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

/*
   절약할 수 있는 최대 비용 = 전체 연결 비용 - 최단 비용
*/

using namespace std;

typedef pair<int, int> PAIR;
typedef tuple<int, int, int> TUPLE;

int n, m, sum, result;
int parent[200001];
vector<TUPLE> load;

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

int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {

		cin >> m >> n;
		if (!m && !n) break;
		for (int i = 1; i <= m; i++) parent[i] = i;

		load.clear();
		sum = result = 0;
		for (int i = 0; i < n; i++) {
			int x, y, z; cin >> x >> y >> z;
			load.push_back({ z, x, y });
			sum += z;
		}

		sort(load.begin(), load.end());

		for (int i = 0; i < load.size(); i++) {

			auto cur = load[i];
			int cost = get<0>(cur);
			int n1 = get<1>(cur);
			int n2 = get<2>(cur);
			if (!findParent(n1, n2)) {
				unionParent(n1, n2);
				result += cost;
			}
		}

		cout << sum - result << "\n";

	}

	return 0;
}
