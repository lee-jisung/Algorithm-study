#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 101
#define INF 987654321

using namespace std;

struct node {
	int r;
	int c;
	int depth;
};

int n, m, result; 
int map[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void) {

	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	deque<node> dq;
	dq.push_back({ 1, 1, 0 });
	isVisit[1][1] = true;


	// deque 사용
	// depth가 낮은 순서대로 갈 수 있는 경로는 먼저 끝까지 탐색
	while (!dq.empty()) {

		int r = dq.front().r;
		int c = dq.front().c;
		int depth = dq.front().depth;

		dq.pop_front();

		if (r == n && c == m) {
			result = depth;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
			if (!isVisit[nr][nc]) {
				if (map[nr][nc]) {
					dq.push_back({ nr, nc, depth + 1 });
					isVisit[nr][nc] = true;
				}
				else {
					dq.push_front({ nr, nc, depth });
					isVisit[nr][nc] = true;
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}
