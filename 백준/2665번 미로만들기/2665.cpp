#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 51
#define INF 1e9

using namespace std;

/*
  검은방을 부수고 가는 경우를 매번 갱신 -> 적게 가는 순으로

  도착지점에 와도 continue를 하는 이유 -> 큐가 빌 때 까지 모두 진행해야 함 -> 어차피 적게 가는 순으로 갱신이 되기 때문에
  모든 큐를 빌때까지 하면 제일 적은 값이 result에 들어가게 될 것이므로
*/

struct node {
	int r, c;
};

int n, result;
int board[SIZE][SIZE], dist[SIZE][SIZE];
int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int main(void) {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &board[i][j]);
		}
	};

	for (int i = 0; i < n;i++)
		for (int j = 0;j < n; j++)
			dist[i][j] = INF;

	queue<node>q;
	q.push({0, 0});
	dist[0][0] = 0;
	
	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		q.pop();


		if (r == n - 1 && c == n - 1) {
			result = dist[r][c];
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];


			if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;

			if (board[nr][nc] && dist[r][c] < dist[nr][nc]) {
				q.push({ nr, nc });
				dist[nr][nc] = dist[r][c];
			}
			else if (!board[nr][nc] && dist[r][c] + 1< dist[nr][nc]) {
				q.push({ nr, nc, });
				dist[nr][nc] = dist[r][c] + 1;
			}
		}
	}

	cout << result << "\n";

	return 0;
}
