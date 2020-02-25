#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 20
#define INF 1e5

using namespace std;

struct node {
	int r;
	int c;
};

int n, m, result, trash;
int sr, sc;
int dis[SIZE][SIZE][11];
bool cache[SIZE][SIZE];
char map[SIZE][SIZE];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<pair<pair<int, int>, int> > dirty;

// 시작점 -> 오염공간 마다 최소 경로 bfs 탐색 / 저장
// 오염장소에 도달 못하는 곳이 있으면 -1 
// 각 오염장소마다 다른 오염장소로 가는 최단 경로 bfs 탐색 / 저장
// dfs로 시작에서 다른 더러운 장소 이동 -> 최단 경로 계산

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

bool isPossible() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;j++) {
			if (map[i][j] == '*' && dis[i][j][0] == 0)
				return false;
		}
	}
	return true;
}

void bfs(int r, int c, int no) {

	queue<node> q;
	q.push({ r, c });
	cache[r][c] = true;
	dis[r][c][no] = 0;

	while (!q.empty()) {

		int rr = q.front().r;
		int cc = q.front().c;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = rr + dx[i];
			int nc = cc + dy[i];
		
			if (isRange(nr, nc) && map[nr][nc] != 'x' && !cache[nr][nc]) {
				q.push({ nr, nc });
				cache[nr][nc] = true;
				dis[nr][nc][no] = dis[rr][cc][no] + 1;
			}
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	while (1) {

		cin >> m >> n;
		if (m == 0 && n == 0) break;

		dirty.clear();
		memset(map, 0, sizeof(map));
		memset(dis, 0, sizeof(dis));
		memset(cache, false, sizeof(cache));
		trash = 0;

		for (int i = 0;i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < str.length(); j++) {
				map[i][j] = str[j];
				if (map[i][j] == 'o') sr = i, sc = j;
				if (map[i][j] == '*') {
					dirty.push_back({ { i,j }, ++trash });
				}
			}
		}

		if (dirty.size() == 0) {
			cout << "0\n"; continue;
		}

		bfs(sr, sc, 0);
		if (isPossible()) {
			result = INF;
			sort(dirty.begin(), dirty.end());
			for (int i = 0; i < dirty.size(); i++) {
				memset(cache, false, sizeof(cache));
				bfs(dirty[i].first.first, dirty[i].first.second, dirty[i].second);
			}
			
			do {
				int dist = dis[dirty[0].first.first][dirty[0].first.second][0];
				for (int i = 1; i < dirty.size(); i++) {
					dist += dis[dirty[i].first.first][dirty[i].first.second][dirty[i-1].second];
				}
				result = min(result, dist);

			} while (next_permutation(dirty.begin(), dirty.end()));
			cout << result << "\n";
		}
		else
			cout << "-1\n";

	}
	return 0;
}
