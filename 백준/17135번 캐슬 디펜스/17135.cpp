#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>


#define SIZE 16

using namespace std;

/*
  - 궁수 위치는 dfs 조합으로 지정

  - 위치가 지정되면 궁수 마다 bfs를 돌려 사정거리 안의 적 좌표를 모두 가져옴
    - 현재 궁수의 위치에서 가장 가까운 적 (거리가 가장 가까운 적) 을 제거함
	- 만약 거리가 같은 것이 여러개 있다면 가장 왼쪽 적을 제거함

*/

int n, m, d, result;
int board[SIZE][SIZE], temp[SIZE][SIZE], archer[3];
bool position[SIZE], isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

bool isEnd() {
	for (int i = 0; i < n; i++)
		for (int j = 0;j < m; j++)
			if (temp[i][j]) return false;
	return true;
}

void copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = board[i][j];
}

// 궁수의 위치에서 제거 가능한 적 좌표 탐색
vector<pair<int, int>> bfs(int r, int c) {
	vector<pair<int, int>> v;
	memset(isVisit, false, sizeof(isVisit));
	queue<pair<int, int>> q;
	q.push({ r, c });
	
	while (!q.empty()) {

		auto pos = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = pos.first + dr[i];
			int nc = pos.second + dc[i];
			if (nr < 0 || nc < 0 || nr > n || nc > m) continue;
			if (!isVisit[nr][nc] && ((abs(r - nr) + abs(c - nc))) <= d) {
				isVisit[nr][nc] = true;
				q.push({ nr, nc });
				if (temp[nr][nc] == 1) {
					v.push_back({ nr, nc });
				}
			}
		}
	}
	return v;
}

int remove_enemy() {
	int cnt = 0;

	while (1) {

		if (isEnd()) break;
		vector<pair<int, int>> remove; // 제거할 적 좌표 저장

		for (int i = 0; i < 3; i++) {
			vector<pair<int, int>> v = bfs(n, archer[i]); 
			if (!v.empty()) {

				//  현재 궁수의 위치에서 가장 가까운 적 (거리가 가장 가까운 적) 을 제거함
				//  만약 거리가 같은 것이 여러개 있다면 가장 왼쪽 적을 제거함
				int dist = abs(n - v[0].first) + abs(archer[i] - v[0].second);
				pair<int, int> pos = v[0];
				for (int j = 0; j < v.size(); j++) {
					int dist2 = abs(n - v[j].first) + abs(archer[i] - v[j].second);
					if (dist2 < dist) pos = v[j];
					else if (dist2 == dist) {
						if (pos.second > v[j].second) pos = v[j];
					}
				}
				remove.push_back(pos);
			}
		}

		for (int i = 0; i < remove.size(); i++) {
			auto pos = remove[i];
			if (temp[pos.first][pos.second] == 1) {
				cnt++;
				temp[pos.first][pos.second] = 0;
			}
		}
	
		for (int i = n - 1; i > 0; i--)
			for (int j = 0;j < m; j++)
				temp[i][j] = temp[i - 1][j];
		for (int j = 0; j < m; j++) temp[0][j] = 0;

	}

	return cnt;
}

void dfs(int idx, int pos) {
	if (pos == 3) {
		copy();
		result = max(result, remove_enemy());
		return;
	}

	for (int i = idx; i < m; i++) {
		if (!position[i]) {
			position[i] = true;
			archer[pos] = i;
			dfs(i, pos + 1);
			position[i] = false;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	dfs(0, 0);

	cout << result << "\n";

	return 0;
}
