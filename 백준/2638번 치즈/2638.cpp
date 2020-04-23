#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

/*
   0인 구역부터 탐색, 1을 만나면 +1을 증가해주고
   값이 2인 곳은 다른 한면이 공기와 접촉해있는 것이므로 0으로 바꿔주고 queue에 좌표를 넣어줌
   더이상 탐색할 좌표가 없어지면 종료
*/

int n, m, result; 
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	queue<pair<int, int>>q;
	q.push({ 0, 0 });
	isVisit[0][0] = true;

	while (1) {

		queue<pair<int, int>> nextQ;

		while (!q.empty()) {

			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (int i = 0; i < 4;i++) {
				int nr = r + dr[i], nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

				if (!isVisit[nr][nc]) {
					if (board[nr][nc] == 0) {
						q.push({ nr, nc });
						isVisit[nr][nc] = true;
					}
					else if (board[nr][nc] == 1) {
						board[nr][nc]++;
					}
					else if (board[nr][nc] == 2) {
						board[nr][nc] = 0;
						nextQ.push({ nr,nc });
						isVisit[nr][nc] = true;
					}
				}
			}
		}

		if (nextQ.empty()) break;
		q = nextQ;
		result++;
	}

	cout << result << "\n";

	return 0;
}
