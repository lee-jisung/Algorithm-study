#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 1501
#define INF 987654321

using namespace std;

struct node {
	int r, c;
};

int n, m, result; 

char map[SIZE][SIZE];
bool isVisit[SIZE][SIZE], isMet;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<node> swan;
queue<node> water, q;

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'L') {
				swan.push_back({ i, j });
				map[i][j] = '.';
			}
			if (map[i][j] == '.') {
				water.push({ i, j });
			}
		}
	}

	q.push(swan[0]);
	isVisit[swan[0].r][swan[0].c] = true;

	while (1) {

		// 물에 인접한 공간들을 저장할 큐
		// 즉, 하루 뒤 녹을 공간들만 미리 저장하여 백조가 탐색할 공간 수를 줄임 --> 시간 초과 줄이는 법
		queue<node> nextQ; 

		while (!q.empty()) {

			int r = q.front().r;
			int c = q.front().c;
			q.pop();
			
			if (r == swan[1].r && c == swan[1].c) {
				isMet = true;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i];
				int nc = c + dy[i];
				
				if (isRange(nr, nc) && !isVisit[nr][nc]) {
					isVisit[nr][nc] = true;
					if (map[nr][nc] == '.') { // 현재 백조가 갈 수 있는 공간은 모두 탐색
						q.push({ nr, nc });
					}
					else if (map[nr][nc] == 'X') { // 물에 인접한 빙판이면 nextQ에 저장
						nextQ.push({ nr, nc });
					}
				}
			}
		}

		if (isMet) break;
		q = nextQ;

		// 물을 녹이는 과정
		// water에 이미 들어있던 만큼만 큐를 돌면 
		// 물에 인접한 공간들만 water에 들어가고 물로 바꿀 수 있음
		int waterSize = water.size();
		while (waterSize--) {
			int r = water.front().r;
			int c = water.front().c;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int nr = r + dx[i];
				int nc = c + dy[i];

				if (isRange(nr, nc)) {
					if (map[nr][nc] == 'X') {
						map[nr][nc] = '.';
						water.push({ nr, nc });
					}
				}
			}
		}

		result++;
	}

	cout << result << "\n";

	return 0;

}
