#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>

#define INF 1e9

/* 
  mirror => 거울의 설치 개수를 저장
  
  C의 첫 좌표에서 4방향을 기준으로 탐색하고
  갈 수 있는 모든방향에 대해서 탐색 => 거울의 개수를 기준으로 현재 q에 더 적은 거울을 설치한 것만
  새로운 좌표로 탐색

  현재 진행 방향과 앞으로 갈 방향이 달라진다면 거울의 개수를 +1 해줌


*/

using namespace std;

struct LASER {
	int r, c;
	int cnt;
	int dir;
};

int w, h;
char board[101][101];
int mirror[101][101];
pair<int, int> C[2];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs() {
	queue<LASER> q;
	for (int i = 0;i < 4;i++) 
		q.push({ C[0].first, C[0].second, 0, i });	
	mirror[C[0].first][C[0].second] = 0;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		int dir = q.front().dir;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nr = r + dr[i];
			int nc = c + dc[i];
			int nCnt = cnt;
			if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
			if (board[nr][nc] == '*') continue;
			if (dir != i) nCnt++;
			if (mirror[nr][nc] < nCnt) continue;

			mirror[nr][nc] = nCnt;
			q.push({ nr, nc, nCnt, i });
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> w >> h;
	int cnt = 0;
	for (int i = 0; i < h;i++) {
		for (int j = 0; j < w;j++) {
			cin >> board[i][j];
			if (board[i][j] == 'C')
				C[cnt++] = { i, j };
		}
	}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
				mirror[i][j] = INF;
	bfs();

	cout << mirror[C[1].first][C[1].second] << "\n";


	return 0;
}
