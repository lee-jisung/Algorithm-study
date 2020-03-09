#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 31
#define INF 987654321

using namespace std;

struct node {
	int r;
	int c;
	int l;
	int minute;
};

int L, R, C;
int str, stc, stl, exr, exc, exl, result;
char map[SIZE][SIZE][SIZE];
bool isVisit[SIZE][SIZE][SIZE];

int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0 ,0, 0, 0, -1, 1 };

bool isRange(int r, int c, int l) {
	return r >= 0 && c >= 0 && l >= 0 && r < R && c < C && l < L;
}

int main(void) {

	while (1) {

		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		for (int l = 0; l < L; l++) {
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					scanf(" %1c", &map[r][c][l]);
					if (map[r][c][l] == 'S') stl = l, str = r, stc = c;
				}
			}
		}

		memset(isVisit, false, sizeof(isVisit));
		queue<node> q;
		q.push({ str, stc, stl, 0 });
		isVisit[str][stc][stl] = true;
		result = INF;

		while (!q.empty()) {

			int r = q.front().r;
			int c = q.front().c;
			int l = q.front().l;
			int minute = q.front().minute;
			q.pop();

			if (map[r][c][l] == 'E') {
				result = min(result, minute);
				break;
			}

			for (int i = 0; i < 6; i++) {
				int nr = r + dx[i];
				int nc = c + dy[i];
				int nl = l + dz[i];

				if (isRange(nr, nc, nl) && !isVisit[nr][nc][nl] && map[nr][nc][nl] != '#') {
					q.push({ nr, nc, nl, minute + 1 });
					isVisit[nr][nc][nl] = true;
				}
			}

		}

		if (result != INF)
			cout << "Escaped in " << result << " minute(s).\n";
		else
			cout << "Trapped!\n";

	}
	return 0;
}
