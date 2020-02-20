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
	int cnt;
	int block;
};

int n, m, t, result;
int map[SIZE][SIZE];
bool cache[SIZE][SIZE][2];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1 ,1 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

// 벽부수기와 거의 비슷
// block을 0으로 두고 시작해서 
// 그람(map[i][j]==2) 를 찾으면 block을 1로 증가시키고
// 벽을 뚫는 거리수를 표시해가며 찾으면 됨

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	queue<node> q;
	q.push({ 0, 0, 0, 0 });
	cache[0][0][1] = true;
	result = -1;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		int block = q.front().block;

		q.pop();

		if (r == n - 1 && c == m - 1) {
			result = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (isRange(nr, nc)) {

				if (map[nr][nc] == 0 && !cache[nr][nc][block]) {
					q.push({ nr, nc, cnt + 1, block });
					cache[nr][nc][block] = true;
				}
				if (map[nr][nc] == 2) {
					q.push({ nr, nc, cnt + 1, block + 1 });
					cache[nr][nc][block] = true;
				}
				if (map[nr][nc] == 1 && block && !cache[nr][nc][block]) {
					q.push({ nr, nc, cnt + 1, block });
					cache[nr][nc][block] = true;
				}
			}
		}
	}

	if (result > t || result == -1) cout << "Fail\n";
	else cout << result << "\n";

	return 0;
}
