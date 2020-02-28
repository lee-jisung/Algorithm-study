#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 2000
#define INF 987654321

using namespace std;

int n, m, result;
bool isVisit[SIZE], ck;
vector<int> v[SIZE];


// vertex당 dfs로 연결되어있는 요소를 방문하면서 depth가 5가되면 true
// 아니면 false

void dfs(int vertex, int depth) {

	cout << vertex << " " << depth << "\n";

	if (depth == 5) {
		ck = true;
		return ;
	}

	isVisit[vertex] = true;
	for (int i = 0; i < v[vertex].size(); i++) {
		int x = v[vertex][i];
		if (!isVisit[x])
			dfs(x, depth + 1);
		if (ck) return; // 시간초과 방지
	}
	isVisit[vertex] = false; 
	// 이걸 넣어줌으로써 한가지 길이 아닌 뒤로 돌아와 다른 방법으로 길을 탐색할 수 있음
	// 백트래킹과 비슷한 의도라 생각 
	// ex)
	// 5 5
	// 0 1
	// 1 3
	// 1 2
	// 2 3
	// 3 4
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}

	cout << "\n";
	
	for (int i = 0; i < n; i++) {
		memset(isVisit, false, sizeof(isVisit));
		dfs(i, 1); cout << "\n";
		if(ck) result = 1;
	}

	cout << result << "\n";

	return 0;
}
