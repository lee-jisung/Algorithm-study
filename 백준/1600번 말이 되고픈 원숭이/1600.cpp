#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 201
#define INF 987654321

using namespace std;

/*
   isVisit --> 3차원으로 처리하여 k번 움직였을때 방문 처리를 해줌
   
   k번 horse처럼 움직이며 가는 경우 
   인접한 1칸만 이동해서 가는경우를 각각 따로 두어 큐에 저장

   (벽부수기 문제와 비슷)

*/

struct node {
	int r, c;
	int depth;
	int move;
};

int w, h, k, result; 
int map[SIZE][SIZE];

bool isVisit[SIZE][SIZE][31];
int dx[12] = { -1, 1, 0, 0, -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[12] = { 0, 0, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < h && c < w;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> k >> w >> h;
	for (int i = 0; i < h;i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}

	queue<node> q;
	q.push({ 0, 0, 0, 0 });
	isVisit[0][0][0] = true;
	result = -1;
	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int depth = q.front().depth;
		int move = q.front().move;

		q.pop();

		if (r == h - 1 && c == w - 1) {
			result = depth;
			break;
		}

		for (int i = 0; i < 12; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (!isRange(nr, nc)) continue;

			// k번까지 가능한 경우
			if (!map[nr][nc] && move < k && !isVisit[nr][nc][move+1]) {
				q.push({ nr, nc, depth + 1, move + 1 });
				isVisit[nr][nc][move+1] = true;
			}
			// i<4인 경우 --> 상하좌우 인접칸
			if (!map[nr][nc] && i < 4 && !isVisit[nr][nc][move]) {
				q.push({ nr, nc, depth + 1, move });
				isVisit[nr][nc][move] = true;
			}
		}
	}

	cout << result << "\n";
	return 0;
}
