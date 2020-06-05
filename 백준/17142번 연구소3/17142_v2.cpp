#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

#define SIZE 51
#define INF 1e9

using namespace std;

int n, m;
int virus_cnt, result;
int board[SIZE][SIZE], temp[SIZE][SIZE];
bool isVisit[SIZE][SIZE], virus[11];

vector<pair<int, int>> virus_pos;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

// 비활성에 활성이 도착했을때 활성이 된단의미는
// 그냥 0 처럼 바이러스가 퍼뜨려지는 지점이랑 동일하다는 얘기로 
// 비활성에 도착했을 때 걸리는 시간을 그냥 넣어주면 돼 
// 비활성이라고 0으로 다시 초를 초기화시켜서 하는건 아님

void copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = board[i][j];
}

int spread() {
	int time = 0;
	queue <pair<int, pair<int, int>>> q;
	for (int i = 0; i < virus_cnt; i++) {
		if (virus[i]) {
			q.push({ 0, {virus_pos[i].first, virus_pos[i].second} });
			isVisit[virus_pos[i].first][virus_pos[i].second] = true;
		}
	}

	while (!q.empty()) {

		int t = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (board[r][c] != 2)
			time = max(time, t);

		for (int i = 0; i < 4; i++) {

			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n || isVisit[nr][nc]) continue;

			if (board[nr][nc] == 0 || board[nr][nc] == 2) {
				temp[nr][nc] = t + 1;
				q.push({ t + 1, {nr, nc} });
				isVisit[nr][nc] = true;
			}
		}
	}
	return time;
}

bool ck() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (board[i][j] == 0 && temp[i][j] == 0) return false;
	return true;
}

void dfs(int idx, int no) {

	if (no == m) {
		copy();
		memset(isVisit, false, sizeof(isVisit));
		int time = spread();
		if (ck()) {
			result = min(result, time);
		}
		return;
	}
	for (int i = idx; i < virus_cnt; i++) {
		if (!virus[i]) {
			virus[i] = true;
			dfs(i+1, no + 1);
			virus[i] = false;
		}
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) virus_pos.push_back({ i, j });
		}
	}

	virus_cnt = virus_pos.size();
	result = INF;
	dfs(0, 0);
	if (result == INF) cout << -1 << "\n";
	else cout << result << "\n";

	return 0;
}
