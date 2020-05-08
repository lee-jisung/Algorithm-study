#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 21
#define INF 1e9

using namespace std;

/*  
   신호등 vector를 따로 관리 -> 트럭이 초당 움직일 때 마다 시간을 1초 씩 늘리고
   a or b시간이 되면 방향을 바꿔주고 다시 시간을 1초씩 늘려주고 신호등의 방향을 반대로 바꿔줌

   bfs를 size만큼 돌리면서 초당 움직임으로 계산 
   신호등을 만났을 때, 현재 진행 방향과 신호등의 방향이 동일하면 신호등으로 진입, 아니면 그전 자리에서 시간을 1씩 
   추가해가면서 기다림

*/

struct Light {
	int a, b;
	int dir;
	int height;
	int width;
};

struct node {
	int r, c;
	int depth;
};

int tc;
int n, m; 
char board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

node st;

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, -1, 0, 1 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {

		int cross = 0, result = -1;
		vector<Light> lights;
		memset(isVisit, false, sizeof(isVisit));

		cin >> m >> n;
		if (!m && !n) break;

		for (int i = 1;i <= m; i++) {
			string temp; cin >> temp;
			for (int j = 0; j < temp.length(); j++) {
				board[i][j + 1] = temp[j];
				if (temp[j] >= '0' && temp[j] <= '9') cross++;
				else if (temp[j] == 'A') st.r = i, st.c = j + 1;
			} 
		}

		for (int i = 0; i < cross; i++) {
			int no, a, b; char dir;
			cin >> no >> dir >> a >> b;
			if (dir == '-')
				lights.push_back({ a, b, 0, 0, 0 });
			else
				lights.push_back({ a, b, 1, 0, 0 });
		}
		
		queue<node> q;
		q.push(st);
		isVisit[st.r][st.c] = true;
		bool ck = false;

		while (!q.empty()) {

			int p = q.size();
			while (p--) {

				int r = q.front().r;
				int c = q.front().c;
				int depth = q.front().depth;
				q.pop();

				if (board[r][c] == 'B') {
					result = depth;
					ck = true;
					break;
				}

				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i];
					int nc = c + dc[i];

					if (nr <= 0 || nc <= 0 || nr > m || nc > n || board[nr][nc] == '.') continue;
					if (isVisit[nr][nc]) continue;

					if (board[nr][nc] >= '0' && board[nr][nc] <= '9') {
						if (lights[board[nr][nc] - '0'].dir == 0 && (i % 2) == 1) {
							q.push({ nr, nc, depth + 1 });
							isVisit[nr][nc] = true;
						}
						else if (lights[board[nr][nc] - '0'].dir == 1 && (i % 2) == 0) {
							q.push({ nr, nc, depth + 1 });
							isVisit[nr][nc] = true;
						}
						else {
							q.push({ r, c, depth + 1 });
						}
					}
					else {
						q.push({ nr, nc, depth + 1 });
						isVisit[nr][nc] = true;
					}
				}
			}
			if (ck) break;
			for (int i = 0; i < lights.size(); i++) {
				if (lights[i].dir == 0) {
					lights[i].width++;
					if (lights[i].width == lights[i].a) {
						lights[i].dir = 1; lights[i].width = 0;
					}
				}
				else {
					lights[i].height++;
					if (lights[i].height == lights[i].b) {
						lights[i].dir = 0; lights[i].height = 0;
					}
				}

			}
		}

		if (ck) cout << result << "\n";
		else cout << "impossible\n";

	}

	return 0;
}
