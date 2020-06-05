#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

#define SIZE 102
#define INF 1e9

using namespace std;

int tc;
int h, w, result;
int dist[SIZE][SIZE][3];
char board[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs(pair<int, int> a, int no) {
	deque<pair<int, int>> dq;
	dq.push_back(a);
	dist[a.first][a.second][no] = 0;

	while (!dq.empty()) {

		auto pos = dq.front();
		dq.pop_front();
		
		for (int i = 0; i < 4; i++) {
			int nr = pos.first + dr[i];
			int nc = pos.second + dc[i];
			if (nr < 0 || nc < 0 || nr >=SIZE || nc>=SIZE || dist[nr][nc][no] >= 0 || board[nr][nc] == '*') continue;
			
			if (board[nr][nc] == '#') {
				dist[nr][nc][no] = dist[pos.first][pos.second][no] + 1;
				dq.push_back({ nr, nc });
			}
			else if (board[nr][nc] == '.') {
				dist[nr][nc][no] = dist[pos.first][pos.second][no];
				dq.push_front({ nr, nc });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	
	while (tc--) {

		deque<pair<int, int>> prison;
		memset(board, '.', sizeof(board));
		memset(dist, -1, sizeof(dist));

		cin >> h >> w;
		prison.push_back({ 0, 0 });

		for (int i = 1; i <= h; i++) {
			string tmp; cin >> tmp;
			for (int j = 1; j <= w; j++) {
				board[i][j] = tmp[j-1];
				if (board[i][j] == '$') {
					board[i][j] = '.';
					prison.push_back({ i, j });
				}
			}
		}
		int idx = 0;
		while (!prison.empty()) {
			auto pos = prison.front();
			prison.pop_front();
			bfs(pos, idx);
			idx++;
		}
		result = INF;
		for (int i = 0; i < h + 2; i++) {
			for (int j = 0; j < w + 2; j++) {
				if (board[i][j] != '*') {
					int sum = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];
					if (board[i][j] == '#') sum -= 2;
					result = min(result, sum);
				}

			}
		}
		cout << result << "\n";
	}
	return 0;
}
