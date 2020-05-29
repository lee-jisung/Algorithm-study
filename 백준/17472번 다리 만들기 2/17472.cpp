#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 11
#define INF 1e9

using namespace std;

/*
   1. dfs - 각 섬 번호 붙이기, 각 섬의 번호마다 좌표를 저장 (vector에)

   2. 출발섬, 도착섬을 지정해서 거리 측정
	 dfs를 사용 -> 출발했던 방향대로만 움직임
	 도착지점이 아닌 지점이면 return
	 섬을 도착했을 때 dist[st][goal]에 최소값으로 갱신

   3. 거리를 측정한 후 위에서 측정한 섬들의 번호 및 거리를 bridge vector에 저장

   4. bridge벡터를 거리 순으로 정렬

   5. MST (kruskal)을 통해 섬들을 연결, 최단거리 누적 합

   6. 모든 섬이 연결이 되어있는지 여부를 확인해서
	  연결되어있으면 최단거리 출력
	  연결되어있지 않은 섬이 하나라도 있으면 -1 출력
*/

int n, m;
int island_cnt, result;
int board[SIZE][SIZE], island[SIZE][SIZE];
int parent[7], dist[7][7];

bool isVisit[SIZE][SIZE];

vector<pair<int, int>> island_pos[7];
vector< pair<int, pair<int, int>>> bridge;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void make_island(int r, int c) {

	island[r][c] = island_cnt;
	isVisit[r][c] = true;
	island_pos[island_cnt].push_back({ r, c });

	for (int i = 0; i < 4;i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
		if (board[nr][nc] == 0 || isVisit[nr][nc]) continue;
		make_island(nr, nc);
	}
}

void dfs(int r, int c, int dir, int len, int cur, int next) {

	int nr = r + dr[dir];
	int nc = c + dc[dir];
	if (nr < 0 || nc < 0 || nr >= n || nc >= m) return;
	if (board[nr][nc] == 0) dfs(nr, nc, dir, len + 1, cur, next);
	else if (island[nr][nc] == next && len > 1) {
		if (dist[cur][next] > len) {
			dist[cur][next] = len;
			dist[next][cur] = len;
		}
		return;
	}
}

void find_dist(int cur, int next) {

	for (int i = 0; i < island_pos[cur].size(); i++) {

		int r = island_pos[cur][i].first;
		int c = island_pos[cur][i].second;

		for (int j = 0; j < 4; j++) {

			int nr = r + dr[j];
			int nc = c + dc[j];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (board[nr][nc] == 0) {
				dfs(r, c, j, 0, cur, next);
			}
		}
	}
}

int getParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> board[i][j];

	for (int i = 0; i < 7; i++) {
		parent[i] = i;
		for (int j = 0; j < 7; j++)
			dist[i][j] = INF;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] && !isVisit[i][j]) {
				island_cnt++;
				make_island(i, j);
			}
		}
	}

	for (int cur = 1; cur < island_cnt; cur++) {
		for (int next = cur + 1; next <= island_cnt; next++) {
			find_dist(cur, next);
			if (dist[cur][next] != INF)
				bridge.push_back({ dist[cur][next], {cur, next} });
		}
	}

	sort(bridge.begin(), bridge.end());

	for (int i = 0; i < bridge.size(); i++) {

		int land1 = bridge[i].second.first;
		int land2 = bridge[i].second.second;
		int len = bridge[i].first;

		if (!findParent(land1, land2)) {
			unionParent(land1, land2);
			result += len;
		}
	}

	bool isConnect = true;
	int no = getParent(1);

	for (int i = 2; i <= island_cnt; i++)
		if (!findParent(no, i)) isConnect = false;

	if (isConnect) cout << result << "\n";
	else cout << -1 << "\n";

	return 0;
}
