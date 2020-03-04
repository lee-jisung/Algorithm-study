#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 1001
#define INF 987654321

using namespace std;

struct com {
	int com1;
	int com2;
	int weight;
};

int n, m, c1, c2, w; 
int computer[SIZE], result;
vector<com> graph;

bool cmp(com com1, com com2) {
	return com1.weight < com2.weight;
}

int getParent(int x) {
	if (computer[x] == x) return x;
	return computer[x] = getParent(computer[x]);
}

void unionComputer(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) computer[b] = a;
	else computer[a] = b;
}

//같은 부모인지 확인
bool findCom(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		computer[i] = i;

	while (m--) {
		cin >> c1 >> c2 >> w;
		graph.push_back({ c1, c2, w });
	}
	sort(graph.begin(), graph.end(), cmp);

	for (int i = 0; i < graph.size(); i++) {

		if (!findCom(graph[i].com1, graph[i].com2)) {
			unionComputer(graph[i].com1, graph[i].com2);
			result += graph[i].weight;
		}
	}

	cout << result << "\n";

	return 0;
}
