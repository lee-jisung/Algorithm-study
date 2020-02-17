#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100
#define INF 987654321

using namespace std;

struct node {
	int r;
	int c;
	int dist;
	bool path;
};

int n, result, mark, dis;
int map[SIZE][SIZE], island[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < n;
}

void init() {
	memset(isVisit, false, sizeof(bool) * SIZE * SIZE);
}

// 섬을 1, 2, 3.... 순서로 마킹
void make_island(int r, int c, int mk) {
	
	queue<pair<int, int> > q;
	q.push({ r,c });
	isVisit[r][c] = true;
	island[r][c] = mk;

	while (!q.empty()) {

		int nr = q.front().first;
		int nc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nrr = nr + dx[i];
			int ncc = nc + dy[i];
			if (isRange(nrr,ncc) && map[nrr][ncc] == 1 && !isVisit[nrr][ncc]) {
				q.push({ nrr, ncc });
				isVisit[nrr][ncc] = true;
				island[nrr][ncc] = mk;
			}
		}
	}
}

// 각 칸마다 다른 섬으로 가는 길을 + 1 해가면서 다른 섬을 만나면 
// path를 true로 해주고 그이후의 search는 안하고 continue로 다른 길을 찾음

int find_path(int r, int c) {

	int dist = INF;
	int mk = island[r][c];
	queue<node > q;
	q.push({r, c, 0 , false});
	isVisit[r][c] = true;

	while (!q.empty()) {

		int nr = q.front().r;
		int nc = q.front().c;
		int d = q.front().dist;
		bool path = q.front().path;
		q.pop();

		if (path) {
			dist = min(dist, d);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nrr = nr + dx[i];
			int ncc = nc + dy[i];
			if (isRange(nrr, ncc)) {

				if (island[nrr][ncc] == 0 && !isVisit[nrr][ncc]) {
					q.push({ nrr, ncc, d + 1, false });
					isVisit[nrr][ncc] = true;
				}
				else if (island[nrr][ncc] != mk && island[nrr][ncc] != 0 && !isVisit[nrr][ncc]) {
					q.push({ nrr, ncc, d, true });
					isVisit[nrr][ncc] = true;
				}

			}
		}
	}
	return dist;
}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	mark = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && !isVisit[i][j]) {
				make_island(i, j, mark);
				mark++;
			}
		}
	}

	result = dis = INF;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (map[i][j] != 0) {
				init();
				dis = find_path(i, j);
			}
			result = min(dis, result);
		}
	}

	cout << result << "\n";

	return 0;
}
