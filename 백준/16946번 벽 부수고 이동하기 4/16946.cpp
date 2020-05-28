#include <iostream>
#include <queue>
#include <set>

#define SIZE 1001

using namespace std;

/*
   1인 지점마다 0의 개수를 탐색하는 bfs -> 시간초과

   0을 그룹지어서 index를 붙인 후 각 0의 그룹의  개수를 zero 배열에 저장함

   1인 칸에서 상하좌우로 0과 인접하게 되었다면 해당 0이 속한 그룹의 idx를 가져와 zero[idx]를 1인 칸에 더해줌
   (중복을 제거하기 위해 set 사용)

   

*/

int n, m, result;
int idx, cnt;
int board[SIZE][SIZE], adj[SIZE][SIZE], zero[500001];
bool isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	isVisit[y][x] = true;
	adj[y][x] = idx;

	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4;i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 1 || nc < 1 || nr > n || nc > m) continue;
			if (board[nr][nc] == 0 && !isVisit[nr][nc]) {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
				adj[nr][nc] = idx;
				cnt++;
			}
		}
	}
}

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str; cin >> str;
		for (int j = 1; j <= m; j++) {
			board[i][j] = str[j - 1] - '0';
		}
	}

	for (int i = 1; i <= n;i++) {
		for (int j = 1;j <= m;j++) {
			if (board[i][j] == 0 && !isVisit[i][j]) {
				idx++;
				cnt = 1;
				bfs(i, j);
				zero[idx] = cnt;
			}
		}
	}

	for (int i = 1;i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j]) {
				set<int> s;
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (nr < 1 || nc < 1 || nr> n || nc > m) continue;
					if (board[nr][nc] == 0)
						s.insert(adj[nr][nc]);
				}
				for (auto k : s) {
					board[i][j] += zero[k] % 10;
				}
				board[i][j] %= 10;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << board[i][j];
		cout << "\n";
	}

	return 0;

}
