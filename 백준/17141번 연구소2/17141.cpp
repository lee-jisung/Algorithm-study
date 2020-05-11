#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define SIZE 51
#define INF 1e9 

using namespace std;

struct node {
	int r, c;
};

int n, m, result;
int board[SIZE][SIZE];
int virus_dist[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

vector<pair<int, int>> virus;

void bfs(vector<pair<int, int>> sel_virus) {

	memset(virus_dist, -1, sizeof(virus_dist));
	queue<node> q;
	for (int i = 0; i < sel_virus.size(); i++) {
		q.push({ sel_virus[i].first, sel_virus[i].second });
		virus_dist[sel_virus[i].first][sel_virus[i].second] = 0;
	}
	
	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;

			if (board[nr][nc] != 1 && virus_dist[nr][nc] == -1) {
				virus_dist[nr][nc] = virus_dist[r][c] + 1;
				q.push({ nr, nc });
			}
		}
	}
}

bool check_virus() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (virus_dist[i][j] == -1 && board[i][j] == 0) return false;
	return true;
}

int get_time() {
	int dist = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0;j < n; j++)
			dist = max(dist, virus_dist[i][j]);
	return dist;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j= 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < virus.size() - m; i++)
		v.push_back(0);
	for (int i = 0; i < m; i++)
		v.push_back(1);

	result = INF;

	do {
		vector<pair<int, int>> sel_virus;
		for (int i = 0; i < v.size(); i++) {
			if (v[i]) {
				sel_virus.push_back({ virus[i].first, virus[i].second });
			}
		}

		bfs(sel_virus);
		if (check_virus()) {
			result = min(result, get_time());
		}

	} while (next_permutation(v.begin(), v.end()));

	if (result == INF) cout << "-1\n";
	else cout << result << "\n";

	return 0;
}
