#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 51
#define INF 987654321

using namespace std;

/*
   BFS + inchworm
   고도시작지점, 끝지점을 한칸식 늘려주면서 배달이 가능한 경우 고도차의 최소값을 찾는다
*/

struct NODE {
	int r, c;
};

int n, str, stc, k_num, cnt, front, rear, res; 
char map[SIZE][SIZE];
int altitude[SIZE][SIZE];
bool isVisit[SIZE][SIZE], h[1000001];

int dx[9] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dy[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

vector<int> height;

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < n;
}

void bfs() {

	cnt = 0;
	memset(isVisit, false, sizeof(isVisit));
	queue<NODE> q;
	q.push({ str, stc});
	isVisit[str][stc]= true;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		for (int i = 0; i < 9; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			
			if (!isRange(nr, nc)) continue;
			// 현재 및 다음 좌표의 고도값이 설정된 범위인지 확인
			if (altitude[r][c] >= height[front] && altitude[r][c] <= height[rear] && 
				altitude[nr][nc] >= height[front] && altitude[nr][nc] <= height[rear]) {
				if (!isVisit[nr][nc]) {
					if (map[nr][nc] == 'K') cnt++;
					q.push({ nr,nc });
					isVisit[nr][nc] = true;
				}
			}
		}
	}
}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == 'P') str = i, stc = j;
			if (map[i][j] == 'K') k_num++;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> altitude[i][j];
			if (!h[altitude[i][j]]) {
				height.push_back(altitude[i][j]);
				h[altitude[i][j]] = true;
			}
		}

	sort(height.begin(), height.end());

	res = INF;
	// front - min, rear - max를 각각 가르키게 하고 배달 가능한 경우에 한하여
	// 고도차의 최솟값 찾기
	while (front <= rear && rear < height.size()) {
		bfs();
		// bfs를 돌려 k개의 집을 모두 방문하지 못한 경우 rear를 늘려줌
		if (cnt != k_num) {
			rear++;
		}
		//bfs를 돌려 k개의 집을 모두 방문한 경우 front를 하나 높임
		else {
			res = min(res, (height[rear] - height[front]));
			front++;
		}
	}
	cout << res << "\n";

	return 0;
}
