#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 10
#define INF 987654321

using namespace std;

struct BIZ {
	int r;
	int c;
};

struct node {
	BIZ red;
	BIZ blue;
	int cnt;
};

int n, m, result;
bool cache[SIZE][SIZE][SIZE][SIZE]; // 각 red:r,c/ blue:r,c로 방문표시
char map[SIZE][SIZE];
BIZ red, blue;

// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// Q -> red, blue를 넣고 상하좌우 갈 수 있는지 확인
// while(1)로 끝까지 보내고 #이나 O 일 경우 break;
// red, blue가 겹치는 경우 check

int main(void) {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'R') {
				red = { i, j };
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				blue = { i, j };
				map[i][j] = '.';
			}
		}
	}

	queue<node> q;
	q.push({ red, blue, 0});
	cache[red.r][red.c][blue.r][blue.c] = true;
	result = -1;

	while (!q.empty()) {

		BIZ r = q.front().red;
		BIZ b = q.front().blue;
		int cnt = q.front().cnt;

		q.pop();

		if (cnt > 10) {
			result = -1;
			break;
		}

		if (map[r.r][r.c] == 'O') {
			result = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {

			int rr = r.r, rc = r.c;
			int br = b.r, bc = b.c;

			// red, blue를 '#' 이거나 'O'가 나올 때 까지 이동
			while (1) {
				if (map[rr + dx[i]][rc + dy[i]] == '#' || map[rr][rc] == 'O') break;
				rr += dx[i];
				rc += dy[i];
			}

			while (1) {
				if (map[br + dx[i]][bc + dy[i]] == '#' || map[br][bc] == 'O') break;
				br += dx[i];
				bc += dy[i];
			}

			// br bc가 O에 들어간 경우는 q에 넣어 고려할 필요없으므로 continue로 skip
			if (map[br][bc] == 'O') continue;

			// red, blue의 위치가 같을 경우 기존 위치에 따라 더 많이 움직인 쪽을 한칸씩 이동시켜줌
			if (rr == br && rc == bc) {
				switch (i) {
				case 0:
					r.r > b.r ? rr++ : br++; break;
				case 1:
					r.r > b.r ? rr-- : br--; break;
				case 2:
					r.c > b.c ? rc++ : bc++; break;
				case 3:
					r.c > b.c ? rc-- : bc--; break;
				}
			}
			
			// 한번 굴렸던 방향이 아니면 q에 넣고 시도
			if (!cache[rr][rc][br][bc]) {
				q.push({ { rr, rc }, { br, bc }, cnt + 1 });
				cache[rr][rc][br][bc] = true;
			}
		}
	}

	cout << result << "\n";

	return 0;
}
