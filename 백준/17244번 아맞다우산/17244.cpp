#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 50
#define INF 987654321

using namespace std;

struct node {
	int r;
	int c;
};

struct stuff {
	int r;
	int c;
	int no;
};

int n, m, sr, sc, er, ec, result, thing;
int dis[SIZE][SIZE][7];
bool cache[SIZE][SIZE];
char map[SIZE][SIZE];

vector< pair <pair<int, int>, int > > stf;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// bfs로 시작에서 각 물건 지점 최단경로 및 각 물건에서 각 물건으로 가는 경로를 저장 --> dis[SIZE][SIZE][7]
// 시작 ~ 물건 ~ 끝 지점에 대한 순열을 돌리면서 최단경로 출력 (물건에 번호를 붙여 sort, next_permutation 이용)
// 물건 아예 없는 경우 고려

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

void bfs(int r, int c, int no) {

	queue<node> q;
	q.push({ r, c });
	dis[r][c][no] = 0;
	cache[r][c] = true;

	while (!q.empty()) {

		int rr = q.front().r;
		int cc = q.front().c;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dx[i];
			int nc = cc + dy[i];
			
			if (isRange(nr, nc) && map[nr][nc] != '#' && !cache[nr][nc]) {
				q.push({ nr, nc });
				dis[nr][nc][no] = dis[rr][cc][no] + 1;
				cache[nr][nc] = true;
			}
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'S') sr = i, sc = j;
			if (map[i][j] == 'E') er = i, ec = j;
			if (map[i][j] == 'X') {
				stf.push_back({ { i, j}, ++thing });
			}
		}
	}

	bfs(sr, sc, 0);
	memset(cache, 0, sizeof(bool) * SIZE * SIZE);
	bfs(er, ec, thing + 1);

	if (thing > 0) {
		sort(stf.begin(), stf.end());

		for (int i = 0; i < stf.size(); i++) {
			memset(cache, 0, sizeof(bool) * SIZE * SIZE);
			bfs(stf[i].first.first, stf[i].first.second, stf[i].second);
		}

		result = INF;

		do {
			int dist = dis[stf[0].first.first][stf[0].first.second][0];
			for (int i = 1; i < stf.size(); i++) {
				dist += dis[stf[i].first.first][stf[i].first.second][stf[i - 1].second];
			}
			dist += dis[er][ec][stf[stf.size() - 1].second];
			result = min(result, dist);
		} while (next_permutation(stf.begin(), stf.end()));
	}
	else {
		result = dis[er][ec][0];
	}
	
	cout << result << "\n";

	return 0;
}
