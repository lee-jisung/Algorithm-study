#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100
#define INF 987654321

using namespace std;

struct node {
	int r;
	int c;
	int cnt;
	int key;
};

int n, m, st_r, st_c, result; 
char map[SIZE][SIZE];
bool isVisit[SIZE][SIZE][1 << 6], escape;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

// 열쇠 및 자물쇠가 -> a ~ f / A ~ F 까지임 
// 따라서 1 << 6 인 비트마스크를 통해서 key의 유무를 확인하면서 bfs를 진행

// 탐색 중 소문자일 경우 기존 key와 소문자의 숫자만큼 shift한 값인 (1 << '?' - 'a') 를 OR '|' 연산을 통해 key를 합쳐줌
// 대문자일 경우 갖고 있는 key와 대문자 숫자만큼 shift한 값인 ( 1 << '?' - 'A')를 AND '&' 연산 통해 값이 1이 나오면 
// 문을 열 수 있다고 가정하여 queue에 push해줌

// 벽부수고 이동하기와 비슷한 유형이지만 열쇠의 유무를 비트마스크로 표현

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0;j < m; j++) {
			scanf(" %1c", &map[i][j]);
			if (map[i][j] == '0') {
				st_r = i, st_c = j;
				map[i][j] = '.';
			}
		}
	}

	queue<node> q;
	q.push({ st_r, st_c, 0, 0 });
	isVisit[st_r][st_c][0] = true;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		int cnt = q.front().cnt;
		int key = q.front().key;
		q.pop();

		if (map[r][c] == '1') {
			result = cnt;
			escape = true;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (isRange(nr, nc) && !isVisit[nr][nc][key] && map[nr][nc] != '#') {

				if (map[nr][nc] == '.' || map[nr][nc] == '1') {
					q.push({ nr, nc, cnt + 1, key });
					isVisit[nr][nc][key] = true;
				}
				else if (map[nr][nc] >= 'a' && map[nr][nc] <= 'z') {
					int nkey = key | (1 << map[nr][nc] - 'a');
					q.push({ nr, nc, cnt + 1, nkey });
					isVisit[nr][nc][nkey] = true;
				}
				else if (map[nr][nc] >= 'A' && map[nr][nc] <= 'Z') {
					if (key & (1 << map[nr][nc] - 'A')) {
						q.push({ nr, nc, cnt + 1, key });
						isVisit[nr][nc][key] = true;
					}
				}
			}
		}
	}

	if (escape) cout << result << "\n";
	else cout << "-1\n";

	return 0;
}
