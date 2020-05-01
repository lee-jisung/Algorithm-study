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

struct node {
	int r, c;
	int cnt;
};

int n, m, k, result;
int board[SIZE][SIZE], treasure[SIZE][SIZE];
int dist[SIZE][SIZE][1 << 8];

// N - 0, E -1, S -2, W - 3;
int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

// 현재 열린 문의 방향에서 가고싶은 방향까지 기다려야 하는 시간 return 
int getTime(int cur, int dir) {
	if (cur == dir) return 0; // 현재 문의 방향과 가고싶은 방향이 같으면 추가 시간 0
	if (dir > cur) return dir - cur; // 현재 문 방향보다 가고싶은 방향값이 더 큰 경우 
	return dir - (cur - 4); // 현재 문 방향값이 가고싶은 방향보다 같거나 큰경우
}

void bfs() {

	queue<node> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 0;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		q.pop();

		if (r == m - 1 && c == n - 1 && cnt == (1 << k) - 1) {
			result = dist[m-1][n-1][cnt];
			continue; // why break does not work?
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			int ncnt = cnt;

			if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
			if (treasure[nr][nc] > 0) ncnt |= 1 << (treasure[nr][nc] - 1);
			// 현재 위치의 원래 문의 방향 값 + 현재 위치까지 오는 시간을 더해서 % 4 하면
			// 소요된 시간 후의 현재 위치의 문이 가리키는 방향 값이 나옴 --> times
			int times = (board[r][c] + dist[r][c][cnt]) % 4;
			times = getTime(times, i); // i 방향으로 가기 위해서 기다려야 하는 시간구하기 
			if (dist[nr][nc][ncnt] > dist[r][c][cnt] + times + 1) {
				dist[nr][nc][ncnt] = dist[r][c][cnt] + times + 1;
				q.push({ nr, nc, ncnt });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		memset(dist, 0x1000000f, sizeof(dist));
		memset(treasure, 0, sizeof(treasure));
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		for (int i = 0; i < m; i++) {
			string temp; cin >> temp;
			for (int j = 0; j < temp.length(); j++) {
				if (temp[j] == 'N') board[i][j] = 0;
				else if (temp[j] == 'E') board[i][j] = 1;
				else if (temp[j] == 'S') board[i][j] = 2;
				else if (temp[j] == 'W') board[i][j] = 3;
			}
		}

		cin >> k;
		for (int i = 0; i < k; i++) {
			int r, c; cin >> r >> c;
			treasure[r - 1][c - 1] = i + 1;
		}

		bfs();

		cout << result << "\n";
	}

	return 0;
}
