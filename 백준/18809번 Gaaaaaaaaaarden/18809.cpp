#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 51
#define INF 987654321

using namespace std;


/*
   1. 배양액 green, red 수 <= 배양액 가능 공간 이므로 next_permutation을 통해서 뿌릴 수 있는 모든 경우의 수 구하기
   2. bfs를 통해서 각 배양액을 뿌림
     2-1. board[][] 상태 배열을 통해서 새로운 좌표에 있는 값이 배양액이 퍼지는 순간보다 +1초이고 반대의 색을 가지면
	      꽃(3) 의 값을 넣어주고 count값 +1
	 2-2. board[][]의 값이 0일 경우 아직 배양액이 퍼지지 않은 경우 --> 현재 시간 +1, color를 넣어주고 큐에 새로운 좌표값을
	      넣어줌
   3. 모든 경우의 수를 돌면서 최대의 count값 출력

*/

struct POS {
	int r, c;
};

int n, m, R, G, f_cnt, res;
int ground[SIZE][SIZE];
pair<int, int> board[SIZE][SIZE];  // first = time, second = color or flower
// 1 = green, 2 = red, 3 = flower

int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

vector<POS> pos;
vector<int> ingredients; // 1 = green, 2 = red

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

void bfs() {

	queue<POS> q;
	for (int i = 0; i < ingredients.size(); i++) {
		if (ingredients[i]) {
			q.push({ pos[i].r, pos[i].c });
			board[pos[i].r][pos[i].c] = { 0, ingredients[i] };
		}
	}

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		int time = board[r][c].first;
		int col = board[r][c].second;

		if (board[r][c].second == 3) continue;

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (!isRange(nr, nc) || !ground[nr][nc]) continue;

			if (board[nr][nc].second == 0) {
				q.push({ nr, nc });
				board[nr][nc] = { time + 1, col };
			}
			else if (board[nr][nc].second == 1) {
				if (col == 2 && board[nr][nc].first == time + 1) {
					f_cnt++;
					board[nr][nc].second = 3;
				}
			}
			else if (board[nr][nc].second == 2) {
				if (col == 1 && board[nr][nc].first == time + 1) {
					f_cnt++;
					board[nr][nc].second = 3;
				}
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> G >> R;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ground[i][j];
			if (ground[i][j] == 2) pos.push_back({ i, j });
		}
	}

	for (int i = 0; i < pos.size() - (R + G); i++)
		ingredients.push_back(0);
	for (int i = 0; i < G; i++)
		ingredients.push_back(1);
	for (int i = 0; i < R; i++)
		ingredients.push_back(2);

	do {
		f_cnt = 0;
		memset(board, 0, sizeof(board));
		bfs();
		res = max(res, f_cnt);

	} while (next_permutation(ingredients.begin(), ingredients.end()));
	cout << res << "\n";
	return 0;
}
