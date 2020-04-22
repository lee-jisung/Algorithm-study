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
   C를 2개 놓고 하면 방문처리가 어려워 하나는 다른 문자로 바꿔 줌 (D)
   4방향 중 같은 방향으로 탐색 막기 -> if(dir==i) continue;
   isVisit을 5차원 배열 -> [5]는 방향 체크, [2][2]는 첫번째 C와 두번째 C의 방문 여부 확인
*/

struct node {
	int r, c;
	int depth;
	int dir;
	bool c1, c2;
};

int n, m, result; 
char board[SIZE][SIZE];
bool isVisit[SIZE][SIZE][5][2][2];

pair<int, int> st;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs() {

	queue<node> q;
	q.push({ st.first, st.second, 0, -1, 0, 0 });
	isVisit[st.first][st.second][4][0][0] = true;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int depth = q.front().depth;
		int dir = q.front().dir;
		bool c1 = q.front().c1;
		bool c2 = q.front().c2;
		q.pop();

		if (c1 && c2) {
			result = depth;
			return;
		}

		for (int i = 0; i < 4; i++) {
			if (dir == i) continue;
			int nr = r + dr[i], nc = c + dc[i];
			bool nc1 = c1, nc2 = c2;
			
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (!isVisit[nr][nc][i][c1][c2] && board[nr][nc] != '#') {

				if (board[nr][nc] == 'C') nc1 = true;
				if (board[nr][nc] == 'D') nc2 = true;

				q.push({ nr, nc, depth + 1, i, nc1, nc2 });
				isVisit[nr][nc][i][nc1][nc2] = true;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			board[i][j] = temp[j];
			if (board[i][j] == 'S') st = { i, j }, board[i][j] = '.';
			else if (board[i][j] == 'C') {
				board[i][j] = 'C';
				if (cnt) board[i][j] = 'D';
				cnt++;
			}
		}
	}

	result = -1;
	bfs();
	cout << result << "\n";

	return 0;
}
