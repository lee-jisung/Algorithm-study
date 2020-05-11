#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

#define SIZE 101
#define INF 1e9

/*
   2842번 집배원 한상덕과 비슷

   배열에 속한 숫자들을 'v' vector에 넣고(정렬 및 중복제거)
   front, rear의 two pointer를 두어 'v' 'vector'에서 맨앞에서부터 뒤로 하나씩 옮겨가면서

   min = v[front], max = v[rear] 일 때 bfs가 되는지 확인하고
   bfs를 통해서 (n,n)으로 갈 수 있다면 result = min(result, v[rear]-v[front])로 갱신
   bfs가 false를 return한다면 rear값을 늘려줌

   rear가 v 범위를 벗어나거나 front가 벗어나면 종료

*/

using namespace std;

int n, front, rear, result;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

vector<int> v;


bool bfs(int min_val, int max_val) {
	memset(isVisit, false, sizeof(isVisit));
	queue<pair<int, int>>q;
	
	if (min_val <= board[1][1] && board[1][1] <= max_val) {
		q.push({ 1, 1 });
		isVisit[1][1] = true;
	}

	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		if (r == n && c == n) {
			return true;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 1 || nc < 1 || nr > n || nc > n) continue;
			if (isVisit[nr][nc]) continue;

			if (min_val <= board[nr][nc] && board[nr][nc] <= max_val) {
				q.push({ nr, nc });
				isVisit[nr][nc] = true;
			}
		}
	}
	return false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			v.push_back(board[i][j]);
		}
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	result = INF;

	while (front < v.size()) {

		bool ck = bfs(v[front], v[rear]);

		if (ck) {
			result = min(result, v[rear] - v[front]);
			front++;
		}
		else if (rear < v.size() - 1) {
			rear++;
		}
		else
			break;
	}

	cout << result << "\n";

	return 0;
}
