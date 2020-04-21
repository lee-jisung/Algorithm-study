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

int n, m, sum, prevSize, time; 
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;j++) {
			cin >> board[i][j];
			if (board[i][j]) sum++;
		}
	}

	queue<pair<int, int>>q;
	q.push({ 0, 0 });
	isVisit[0][0] = true;

	while (1) {

		queue<pair<int, int> > nextQ;

		while (!q.empty()) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

				if (board[nr][nc] == 0 && !isVisit[nr][nc]) {
					q.push({ nr, nc });
					isVisit[nr][nc] = true;
				}
				else if (board[nr][nc] == 1) {
					nextQ.push({ nr,nc });
					isVisit[nr][nc] = true;
					board[nr][nc] = 0;
				}
			}
		}
		
		if (sum - nextQ.size() == 0) prevSize = nextQ.size();
		else sum -= nextQ.size();

		q = nextQ;
		if (q.empty()) break;
		time++;
	}
	cout << time << "\n" << prevSize << "\n";

	return 0;
}
