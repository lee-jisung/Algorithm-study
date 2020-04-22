#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1001
#define INF 987654321

using namespace std;

/*
   . 인 것을 queue에 넣고 상하좌우대각의 값을 -1씩 해주고
   0이 되는 것을 queue에 새로 넣어주면서 while을 돌다가 queue가 비는 순간 종료
*/

int h, w, time;
int board[SIZE][SIZE];
queue<pair<int, int>> q;

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < w; j++) {
			if (temp[j] == '.') board[i][j] = 0, q.push({ i, j });
			else board[i][j] = temp[j] - '0';
		}
	}

	while (1) {

		queue<pair<int, int>> nextQ;
		int size = q.size();
		while (size--) {
			int r = q.front().first;
			int c = q.front().second;

			q.pop();

			for (int i = 0; i < 8; i++) {
				int nr = r + dr[i], nc = c + dc[i];
				if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;

				if (board[nr][nc] > 0) {
					board[nr][nc]--;
					if (board[nr][nc] == 0) 
						q.push({ nr, nc });
				}
			}
		}
		if (q.empty()) break;
		time++;
	}

	cout << time << "\n";
	return 0;
}
