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

/*
  2차원 DP
*/

using namespace std;

int mod = 1e9 + 7;
int d;
long long dp[100001][9]; // [d분][건물]
vector<vector<int>> graph(10);


void pushGraph(int a, int b) {
	graph[a].push_back(b);
	graph[b].push_back(a);
}

void init() {
	pushGraph(1, 2); pushGraph(1, 3);
	pushGraph(2, 3); pushGraph(2, 4);
	pushGraph(3, 4); pushGraph(3, 6);
	pushGraph(4, 5); pushGraph(4, 6);
	pushGraph(5, 6); pushGraph(5, 7);
	pushGraph(6, 8); pushGraph(7, 8);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> d;

	init();

	dp[1][2] = 1;
	dp[1][3] = 1;
	for (int t = 2; t <= d; t++) {
		for (int i = 1; i < 9; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int nxt = graph[i][j];
				dp[t][i] = (dp[t][i] + dp[t - 1][nxt]) % mod;
			}
		}
	}

	cout << dp[d][1];
	
	return 0;
}
