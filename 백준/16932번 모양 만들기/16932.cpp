#include <iostream>
#include <set>
#include <cstring>
#include <queue>
#include <algorithm>

#define SIZE 1001

using namespace std;

/*
   1로 이루어진 모양의 그룹을 찾아 번호(순서)를 매기고 그 크기를 shape에 저장
   
   0인 지점에서 동서남북 4방향을 방문하여 1인부분이 있으면 해당 1의 index를 set container에 저장

   set에 저장된 index들의 크기 합과 result를 비교
*/

int n, m, result, idx, cnt;
int board[SIZE][SIZE], label[SIZE][SIZE], shape[500001];
bool isVisit[SIZE][SIZE], used[500001];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	isVisit[y][x] = true;
	label[y][x] = idx;
	cnt = 1;
	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
			if (board[nr][nc] && !isVisit[nr][nc]) {
				isVisit[nr][nc] = true;
				q.push({ nr, nc });
				label[nr][nc] = idx;
				cnt++;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] && !isVisit[i][j]) {
				idx++;
				bfs(i, j);
				shape[idx] = cnt;
				result = max(result, cnt);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0;j < m; j++) {
			if (!board[i][j]) {
				set<int> visit;
				int sum = 1;

				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (nr < 0 || nc < 0 || nr >= n || nc >= m)continue;
					if (board[nr][nc]) {
						visit.insert(label[nr][nc]);
					}
				}
				for (auto k : visit)
					sum += shape[k];
				result = max(result, sum);
			}
		}
	}

	cout << result << "\n";

	return 0;
}
