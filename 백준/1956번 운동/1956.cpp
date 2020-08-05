#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>

#define INF 1e9

using namespace std;

/* 
   floydwarshall로 모든 점에서 점으로 가는 최단거리 구하고
   본인 점에서 본인점으로 돌아오는 가중치의 최단 거리를 구함

   즉, i == j 인 거리들을 비교해서 가장 최단거리를 출력 (cycle을 구하는 것이기 때문)
   (전부다 INF일 경우 -1 출력) => cycle이 존재하지 않음
*/

int v, e, result;
int village[401][401];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			village[i][j] = INF;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		village[a][b] = c;
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (village[i][j] > village[i][k] + village[k][j]) {
					village[i][j] = village[i][k] + village[k][j];
				}
			}
		}
	}

	result = INF;

	for (int i = 1; i <= v;i++) {
		for (int j = 1; j <= v;j++) {
			if (i == j) {
				result = min(result, village[i][j]);
			}
		}
	}

	if (result == INF) result = -1;
	cout << result << "\n";

	return 0;
}
