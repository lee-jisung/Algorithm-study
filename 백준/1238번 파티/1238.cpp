#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1001
#define INF 987654321

// https://www.acmicpc.net/problem/1238

using namespace std;

int n, m, x, result; 
int dist[SIZE][SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		result = max(result, dist[i][x] + dist[x][i]);
	}
	cout << result << "\n";

	return 0;
}
