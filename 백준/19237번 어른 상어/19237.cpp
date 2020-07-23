#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

/*
	1. 모든 상어가 자신의 위치에 냄새를 표시 (자신의 번호), 냄새 유지 기간 = k
	2. 1초마다 모든 상어가 동시에 상하좌우 중 인접한 칸 중 하나로 이동, 냄새 남김 (k)
	 2-1. 이동결정 - 인접한 칸 중 냄새가 없는 칸으로 이동
	 2-2. 냄새가 없는 칸이 없을 경우 자신의 냄새가 있는 칸으로 이동
	 2-3. 냄새가 없는 칸이 여러개일 때 - 우선순위를 따름 (바라보고 있는 방향마다 우선순위가 주어짐)
	3. 이동 후 같은 칸에 여러마리의 상어가 있을 경우 제일 낮은 번호의 상어만 남김
	4. 상어마다 우선순위가 다르며, 방향마다도 우선순위가 다름

*/
using namespace std;

struct Shark {
	int no;
	int r, c;
	int curDir;
	int dir[4][4];
};

int n, m, k;
int result, time;
Shark shark[401];
int sharkPosition[20][20];
pair<int, int> smells[20][20];
queue<Shark> q;

// 1: 상, 2: 하, 3: 좌, 4: 우
int dr[5] = { 0, -1, 1, 0, 0 }, dc[5] = { 0, 0, 0, -1, 1 };

bool isLeftOne() {
	if (q.size() == 1 && q.front().no == 1) return true;
	return false;
}

// 현재 상어의 위치를 기준으로 smells에 상어 번호, 시간 추가
void addSmell() {
	int size = q.size();
	while (size--) {
		Shark sk = q.front();
		q.pop();
		smells[sk.r][sk.c] = { sk.no, k };
		q.push(sk);
	}
}

/*
  1. 상어를 기준으로 우선순위에 따라 냄새가 없는 빈칸을 우선 탐색
   1-1. 번호가 적은것 부터 이동하므로 빈칸이지만 현재 상어보다 적은 번호가 자리를 잡고 있으면 q에 넣지 않음 -> 상어 제거
  2. 빈칸을 찾지 못한 경우 자신의 냄새가 있던 칸을 탐색하여 좌표, 방향 update
   2-1. 새롭게 다시 칸을 들어갔기 때문에 smells의 시간을 k로 다시 초기화
*/
void moveShark() {

	int size = q.size();
	while (size--) {

		Shark sk = q.front();
		q.pop();
		bool foundEmpty = false, isPositioned = false;
		sharkPosition[sk.r][sk.c] = 0;

		for (int i = 0; i < 4; i++) {
			int nr = sk.r + dr[sk.dir[sk.curDir-1][i]];
			int nc = sk.c + dc[sk.dir[sk.curDir-1][i]];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
			if (smells[nr][nc].first == 0 && smells[nr][nc].second == 0) {
				foundEmpty = true; 
				if (sharkPosition[nr][nc] < sk.no && sharkPosition[nr][nc] != 0) {
					isPositioned = true;
					break;
				}
				sk.r = nr; sk.c = nc;
				sharkPosition[nr][nc] = sk.no;
				sk.curDir = sk.dir[sk.curDir-1][i];
				break;
			}
		}
		if (isPositioned) continue;

		if (!foundEmpty) {
			for (int i = 0; i < 4; i++) {
				int nr = sk.r + dr[sk.dir[sk.curDir-1][i]];
				int nc = sk.c + dc[sk.dir[sk.curDir-1][i]];
				if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
				if (smells[nr][nc].first == sk.no) {
					sk.r = nr; sk.c = nc;
					sharkPosition[nr][nc] = sk.no;
					smells[nr][nc].second = k;
					sk.curDir = sk.dir[sk.curDir-1][i];
					break;
				}
			}
		}
		q.push(sk);
	}
}

// 냄새 지우기 
// k시간이 지나 0이되면 번호도 지움
void decreaseSmell() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (smells[i][j].second > 0) {
				if (--smells[i][j].second == 0) smells[i][j].first = 0;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			sharkPosition[i][j] = tmp;
			if (tmp > 0) shark[tmp] = { tmp, i, j };
		}
	}
	for (int i = 1; i <= m; i++)
		cin >> shark[i].curDir;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				cin >> shark[i].dir[j][k];
			}
		}
	}

	for (int i = 1; i <=m; i++) q.push(shark[i]);
	result = -1;
	while (1) {
		if (time > 1000 || q.empty()) break;
		if (isLeftOne()) {
			result = time;
			break;
		}
		addSmell();
		moveShark();
		decreaseSmell();
		time++;
	}

	cout << result << "\n";

	return 0;
}
