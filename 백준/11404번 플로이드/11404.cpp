#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 101
#define INF 987654321

using namespace std;

int n, m; 
int dist[SIZE][SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
	
	// 노선이 여러가지라면 그 중 최단 노선을 먼저 선택해놓으면 됨
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1;j <= n;j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// 방법이 없는 경우 0으로
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (dist[i][j] == INF) dist[i][j] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
