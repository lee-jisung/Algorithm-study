#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>

#define SIZE 50
#define INF 987654321

using namespace std;

int n, m, time, result = INF, cnt;
int map[SIZE][SIZE], virus_map[SIZE][SIZE];
bool isVisit[SIZE][SIZE];
vector<pair<int, int> > virus;
vector<int> v;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 주어진 m개만큼 바이러스를 선택하여 m개를 q에 넣고 bfs
// 각각 case마다 bfs를 돌려서 바이러스를 퍼뜨리고 시간을 virus_map에 갱신

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < n;
}


bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0 && virus_map[i][j] == 0)
				return false;
		}
	}
	return true;
}

// 빈칸인 경우에 한에서 virus_map에서의 최대 시간을 return
int get_time() {
	int time = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				time = max(time, virus_map[i][j]);
			}
		}
	}
	return time;
}

void init() {
	memset(isVisit, false, sizeof(bool) * SIZE * SIZE);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			virus_map[i][j] = map[i][j];
		}
}


void bfs(vector<pair<int, int> > select_virus) {

	int res = -1;
	queue<pair<pair<int, int>,int> > q;
	for (int i = 0; i < select_virus.size(); i++) {
		q.push(make_pair(make_pair(select_virus[i].first, select_virus[i].second), 0));
		isVisit[select_virus[i].first][select_virus[i].second] = true;
	}

	while (!q.empty()) {
		int r = q.front().first.first;
		int c = q.front().first.second;
		int delay = q.front().second;

		res = max(res, delay);

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];
			if (isRange(nr, nc) && !isVisit[nr][nc]) {
				if (map[nr][nc] == 0 || map[nr][nc] == 2) {
					q.push(make_pair(make_pair(nr, nc), delay + 1));
					virus_map[nr][nc] = delay + 1;
					isVisit[nr][nc] = true;
				}
			}
		}
	}
}

int main(void) {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back({ i, j });
			if (!map[i][j]) cnt++;
		}
	}

	for (int i = 0; i < m; i++)
		v.push_back(1);
	for (int i = 0; i < virus.size() - m; i++)
		v.push_back(0);
	sort(v.begin(), v.end());

	if (!cnt) result = 0;
	else {
		do {
			vector<pair<int, int> > select_virus;
			init();

			for (int i = 0; i < v.size(); i++)
				if (v[i]) {
					select_virus.push_back({ virus[i].first, virus[i].second });
				}

			bfs(select_virus);
			if (!check()) time = INF;
			else time = get_time();

			result = min(time, result);

		} while (next_permutation(v.begin(), v.end()));
	}
	if (result == INF)
		cout << -1 << "\n";
	else
		cout << result << "\n";
	return 0;
}
