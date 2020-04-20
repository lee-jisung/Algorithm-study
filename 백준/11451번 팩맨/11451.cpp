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

/*
   1. P 2개를 움직여야 하기 때문에 4차원 배열로 방문 처리
   2. 4개의 좌표를 이용해서 움직이는 동선을 추적
    2-1. 4개의 좌표값을 aabbccdd의 8자리 숫자로 만들어서 움직인 좌표에 이전 좌표값을 저장하는 배열 (prevNum)과
	     움직인 좌표에 이동 방향을 저장하는 배열(prevMove)를 만듦
	2-2. P 2개의 좌표가 만난 시점에서 prevNum과 prevMove 2개의 배열을 이용하여 역추적해서 동선 추출
*/

using namespace std;

struct node {
	int r1,c1,r2,c2;
	int depth;
};

int n, m, tc, result;
string answer;

bool isVisit[SIZE][SIZE][SIZE][SIZE];
char board[SIZE][SIZE];

int prevNum[SIZE][SIZE][SIZE][SIZE];
char prevMove[SIZE][SIZE][SIZE][SIZE];

int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0}; // E W S N
char Move[4] = { 'E', 'W', 'S', 'N' };

vector<pair<int, int>> p;

int hashing(int r1, int c1, int r2, int c2) {
	return r1 * 1000000 + c1 * 10000 + r2 * 100 + c2;
}

void print(int r1, int c1, int r2, int c2) {
	if (prevNum[r1][c1][r2][c2] == -1) return;
	int temp = prevNum[r1][c1][r2][c2];
	print(temp / 1000000, temp % 1000000 / 10000, temp % 10000 / 100, temp % 100);
	answer += prevMove[r1][c1][r2][c2];
}

void bfs() {

	queue<node> q;
	q.push({ p[0].first, p[0].second, p[1].first, p[1].second, 0 });
	isVisit[p[0].first][p[0].second][p[1].first][p[1].second] = true;

	while (!q.empty()) {

		int r1 = q.front().r1, c1 = q.front().c1;
		int r2 = q.front().r2, c2 = q.front().c2;
		int depth = q.front().depth;
		int cur = hashing(r1, c1, r2, c2);
		q.pop();

		if (r1 == r2 && c1 == c2) {
			result = depth;
			print(r1, c1, r2, c2);
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr1 = r1 + dr[i], nc1 = c1 + dc[i];
			int nr2 = r2 + dr[i], nc2 = c2 + dc[i];

			if (nr1 < 0) nr1 = m - 1; if (nc1 < 0) nc1 = n - 1; if (nr1 >= m) nr1 = 0; if (nc1 >= n) nc1 = 0;
			if (nr2 < 0) nr2 = m - 1; if (nc2 < 0) nc2 = n - 1; if (nr2 >= m) nr2 = 0; if (nc2 >= n) nc2 = 0;

			if (board[nr1][nc1] == 'G' || board[nr2][nc2] == 'G') continue;

			if (board[nr1][nc1] == 'X') nr1 = r1, nc1 = c1;
			if (board[nr2][nc2] == 'X') nr2 = r2, nc2 = c2;

			if (isVisit[nr1][nc1][nr2][nc2]) continue;

			q.push({ nr1, nc1, nr2, nc2, depth + 1 });
			isVisit[nr1][nc1][nr2][nc2] = true;
			prevNum[nr1][nc1][nr2][nc2] = cur;
			prevMove[nr1][nc1][nr2][nc2] = Move[i];
		}
	}
}

int main(void) {
	
	cin >> tc;
	while (tc--) {

		memset(isVisit, false, sizeof(isVisit));
		p.clear();
		result = 0; answer = "";
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %c", &board[i][j]);
				if (board[i][j] == 'P') p.push_back({ i, j }), board[i][j] = '.';
			}
		}

		prevNum[p[0].first][p[0].second][p[1].first][p[1].second] = -1;

		bfs();

		if (!result) cout << "IMPOSSIBLE\n";
		else cout << result << " " << answer << "\n";

	}

	return 0;
}
