#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define SIZE 21

/*
   상어의 현재 위치에서 갈 수 있는 위치를 탐색하면서 (자신의 크기보다 작거나 같은 쪽으로 갈 수 있음)
   자신보다 크기가 작은 물고기는 fish vector에 저장

   fish vector를 크기순 (상단, 왼쪽) 순으로 정렬하여 제일 앞 fish를 먹음 (먹은 수 +1)
    - 만약 먹은 갯수가 현재 크기와 동일하면 크기를 +1하고 개수를 0으로 초기화
    - 상어 위치를 물고기를 잡아 먹은 위치로 다시 재조정
    - 다시 상어 위치에서 bfs를 통해서 먹을 수 있는 fish를 재탐색하면서 위의 과정 반복

*/

using namespace std;

struct fish {
	int r, c;
	int dist;
};

int n, m;
int time, shark_size, eat;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

vector<fish> f;
pair<int, int> baby;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs() {

	queue < pair<int, pair<int, int>>> q;
	q.push({ 0, {baby.first, baby.second} });
	isVisit[baby.first][baby.second] = true;

	while (!q.empty()) {

		int r = q.front().second.first;
		int c = q.front().second.second;
		int depth = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;

			if (!isVisit[nr][nc] && shark_size >= board[nr][nc]) {
				q.push({ depth + 1, {nr, nc} });
				isVisit[nr][nc] = true;
				if (board[nr][nc] != 0 && board[nr][nc] < shark_size) {
					f.push_back({ nr, nc, depth + 1 });
				}
			}
		}
	}
}

bool cmp(fish a, fish b) {
	if (a.dist == b.dist) {
		if (a.r == b.r) 
			return a.c < b.c;
		return a.r < b.r;
	}
	return a.dist < b.dist;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				baby = { i, j };
				board[i][j] = 0;
			}
		}
	}

	shark_size = 2;

	while (1) {
		
		memset(isVisit, false, sizeof(isVisit));
		f.clear();
		bfs();
		if (f.empty()) break;
		
		sort(f.begin(), f.end(), cmp);
		
		time += f[0].dist;
		board[f[0].r][f[0].c] = 0;
		baby = { f[0].r, f[0].c };
		eat++;

		if (eat == shark_size) {
			shark_size++;
			eat = 0;
		}
	}
	
	cout << time << "\n";

	return 0;
}
