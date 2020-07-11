#include <iostream>
#include <string>
#include <deque>

#define SIZE 1001

/*
   상하로 최대한 갈 수 있는 만큼 가야 안틀림
   deque을 사용해서 상하의 경우를 먼저 처리할 수 있도록 push_front
   좌,우 일 경우 push_back으로 처리
*/

using namespace std;

int n, m, L, R, result;
int st_r, st_c;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

struct node {
	int r, c, left, right;
};

void bfs() {

	deque<node> dq;
	dq.push_back({ st_r, st_c, L, R });
	isVisit[st_r][st_c] = true;
	while (!dq.empty()) {

		auto pos = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nr = pos.r + dr[i];
			int nc = pos.c + dc[i];
			int l = pos.left;
			int r = pos.right;
			if (l == 0 && i == 2) continue;
			if (r == 0 && i == 3) continue;

			if (isVisit[nr][nc] || board[nr][nc] == 1 || nr < 0 || nc < 0 || nr >= n || nc >= m)continue;

			if (i == 2) l--;
			else if (i == 3) r--;
			isVisit[nr][nc] = true;
			result++;
			if (i == 2 || i == 3) dq.push_back({ nr, nc, l, r });
			else dq.push_front({ nr, nc, l, r });
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> L >> R;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j] - '0';
			if (board[i][j] == 2) {
				st_r = i; st_c = j;
			}
		}
	}
	result = 1;
	bfs();
	cout << result << "\n";

	return 0;
}
