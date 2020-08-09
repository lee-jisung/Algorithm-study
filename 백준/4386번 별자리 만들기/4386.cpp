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
  별들 좌표를 각 별 번호 순으로 저장 -> (dist, i, j) 형태로 graph에 저장 => i와 j사이의 거리 dist

  graph를 이용하여 MST
*/

typedef pair<double, double> PAIR;
typedef tuple<double, int, int> TUPLE;

int n;
int parent[101];
double result;
PAIR star[101];
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

	cin >> n;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		double a, b;
		cin >> a >> b;
		star[i] = { a, b };
	}

	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double dist = sqrt(pow((star[i].first - star[j].first), 2) + pow((star[i].second - star[j].second), 2));
			dist = floor(dist * 100) / 100;
			graph.push_back({ dist, i, j });
		}
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); i++) {
		auto cur = graph[i];
		double dist = get<0>(cur);
		int n1 = get<1>(cur);
		int n2 = get<2>(cur);
		if (!findParent(n1, n2)) {
			unionParent(n1, n2);
			result += dist;
		}
	}

	cout << result << "\n";

	return 0;
}
