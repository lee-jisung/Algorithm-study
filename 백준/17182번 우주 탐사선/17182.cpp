#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <cmath>

#define INF 1e9

/*
   floydWarshall + DFS

   행성 간 최단 거리 -> floydwarsahll로 구하기
   dfs를 통해서 행성을 방문처리하며 모든 행성 방문 시 거리 구하기
    - 간선에 음수가 없으므로 왓던 곳을 다시 방문가능하나 방문하지 않아도 정답은 나옴
	how? -> 순서를 바꿔서 방문

*/

using namespace std;

int n, k, result;
int dist[11][11];
bool isVisit[11];

void floydWarshall() {

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}

void dfs(int planet, int no, int d) {
	if (d > result) return;
	if (no == n) {
		if (result > d) result = d;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isVisit[i]) continue;
		isVisit[i] = true;
		dfs(i, no + 1, d + dist[planet][i]);
		isVisit[i] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
		}
	result = INF;
	floydWarshall();

	isVisit[k] = true;
	dfs(k, 1, 0);

	cout << result << "\n";

	return 0;
}
