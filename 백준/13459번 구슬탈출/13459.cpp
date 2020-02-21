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

struct Node {
	int red_r;
	int red_c;
	int blue_r;
	int blue_c;
	int cnt;
};

int n, m;
int rr, rc, br, bc, wr, wc;
char map[SIZE][SIZE];
bool cache[SIZE][SIZE][SIZE][SIZE], result;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'R') {
				rr = i; rc = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'B') {
				br = i; bc = j;
				map[i][j] = '.';
			}
			if (map[i][j] == 'O') {
				wr = i; wc = j;
			}
		}
	}

	queue<Node> q;
	q.push({ rr, rc, br, bc, 0 });
	cache[rr][rc][br][bc] = true;

	while (!q.empty()) {

		int r_r = q.front().red_r;
		int r_c = q.front().red_c;
		int b_r = q.front().blue_r;
		int b_c = q.front().blue_c;
		int cnt = q.front().cnt;

		q.pop();

		if (cnt > 10) 
			break;

		if (r_r == wr && r_c == wc) {
			result = true;
			break;
		}

		for (int i = 0; i < 4; i++) {

			int nr_r = r_r, nr_c = r_c;
			int nb_r = b_r, nb_c = b_c;

			// Red 이동
			while (1) {
				if (map[nr_r + dx[i]][nr_c + dy[i]] == '#' || map[nr_r][nr_c] == 'O') break;
				nr_r += dx[i];
				nr_c += dy[i];
			}
			// Blue 이동
			while (1) {
				if (map[nb_r + dx[i]][nb_c + dy[i]] == '#' || map[nb_r][nb_c] == 'O') break;
				nb_r += dx[i];
				nb_c += dy[i];
			}

			// blue가 O에 빠진 경우 queue에 넣어 확인할 필요 X
			if (map[nb_r][nb_c] == 'O') continue; 

			// Red와 Blue가 겹치는 경우 원래 위치에서
			// 많이 이동한 구슬을 한칸 앞 혹은 뒤로 이동시켜 줌
			if (nr_r == nb_r && nr_c == nb_c) {
				switch (i) {
				case 0: // 상
					r_r > b_r ? nr_r++ : nb_r++; break;
				case 1: // 하
					r_r > b_r ? nb_r-- : nr_r--; break;
				case 2: // 좌
					r_c > b_c ? nr_c++ : nb_c++; break;
				case 3: // 우
					r_c > b_c ? nb_c-- : nr_c--; break;
				}
			}

			if (!cache[nr_r][nr_c][nb_r][nb_c]) {
				q.push({ nr_r, nr_c ,nb_r, nb_c, cnt + 1 });
				cache[nr_r][nr_c][nb_r][nb_c] = true;
			}
		}
	}

	cout << result << "\n";

	return 0;
}
