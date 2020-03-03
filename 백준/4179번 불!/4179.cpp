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

struct node {
	int r;
	int c;
};

int n, m, result; 
char map[SIZE][SIZE];
bool isVisit[SIZE][SIZE], isEscape;

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

queue<node> fire;
queue<pair<node, int> > q;
node jihoon;

bool isRange(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= m;
}

// 불을 먼저 번지고 그다음 이동 가능한 곳으로 이동하여 가장자리에 도착하면 
// 탈출할 수 있는 것

int main(void) {
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'J') {
				jihoon = { i, j };
				map[i][j] = '.';
			}
			if (map[i][j] == 'F') {
				fire.push({ i, j });
			}
		}
	}

	q.push(make_pair(jihoon, 1));

	while (1) {

		int fireSize = fire.size();
		while (fireSize--) {
			int r = fire.front().r;
			int c = fire.front().c;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i];
				int nc = c + dy[i];
				if (isRange(nr, nc) && map[nr][nc] == '.') {
					map[nr][nc] = 'F';
					fire.push({ nr, nc });
				}
			}
		}

		queue<pair<node, int> > nextQ;
		while (!q.empty()) {
			int r = q.front().first.r;
			int c = q.front().first.c;
			int depth = q.front().second;
			q.pop();

			if (r == 1 || c == 1 || r == n || c == m) {
				result = depth;
				isEscape = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i];
				int nc = c + dy[i];

				if (isRange(nr, nc) && !isVisit[nr][nc] && map[nr][nc] == '.') {
					nextQ.push({ {nr, nc}, depth + 1 });
					isVisit[nr][nc] = true;
				}
			}
		}
		if (isEscape) break;
		if (nextQ.empty()) break;
		q = nextQ;
	}

	if (isEscape)
		cout << result << "\n";
	else
		cout << "IMPOSSIBLE\n";


	return 0;
}
