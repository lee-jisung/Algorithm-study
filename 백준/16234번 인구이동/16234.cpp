#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define SIZE 50

using namespace std;

// 국경선 공유하는 두 나라 인구 차이 --> L명 이상 && R명 이하면 공유하는 국경선 open
// 열어야 하는 국경선이 모두 open된 상태에서 인구 이동 시작
// 국경선이 서로 open되어 있는 칸은 연합으로 부름
// 연합을 이루는 각 칸 인구수 --> (연합의 인구수)/(연합을 이루고 있는 칸의 개수) ** 소수점 제거
// 연합을 해체 후 모든 국경선을 닫음
// 더이상 인구 이동 불가할 때 그만둚 --> 한번했을 때 이전 인구 맵이랑 똑같으면 그만

// bfs로 처음칸부터 시작하면서 국경선을 서로 open하는 구역이면 같은 숫자로 map에 표시
// 그래서 각 연합을 1, 2, 3, 4 이런식으로 표시한 다음 
// 각 칸에 맞는 연합끼리 인구수 더하고 나눠서 갱신하고 다시 다 0으로 만듦

int n, L, R, result;
int map[SIZE][SIZE], united[SIZE][SIZE];
int move_pop[SIZE][SIZE];
int total[SIZE*SIZE][2];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool isVisit[SIZE][SIZE], flag;

bool isRange(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < n;
}

bool check() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] != move_pop[i][j])
				return false;
	return true;
}

// 아마 여기서 SIZE 크기만큼 memset을 제대로 해줘야 런타임에러가 안나는듯
void init() {
	memset(isVisit, 0, sizeof(bool) * SIZE * SIZE);
	memset(united, 0, sizeof(int) * SIZE * SIZE);
	memset(move_pop, 0, sizeof(int) * SIZE * SIZE);
	memset(total, 0, sizeof(int) * SIZE * SIZE * 2);
}

void bfs(int x, int y, int united_ck) {

	queue<pair<int, int> > q;
	q.push({ x, y });
	isVisit[x][y] = true;
	united[x][y] = united_ck;
	total[united_ck-1][0] = map[x][y];
	total[united_ck-1][1] = 1;
	while (!q.empty()) {

		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = r + dx[i];
			int ny = c + dy[i];
			if (isRange(nx, ny) && !isVisit[nx][ny]) {
				if (abs(map[r][c] - map[nx][ny]) >= L && abs(map[r][c] - map[nx][ny]) <= R) {
					q.push({ nx, ny });
					isVisit[nx][ny] = true;
					united[nx][ny] = united_ck;
					total[united_ck-1][0] += map[nx][ny];
					total[united_ck-1][1] ++;
				}
			}
		}
	}
}

int main(void) {

	cin >> n >> L >> R;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	while (1) {

		init();

		int united_ck = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!isVisit[i][j]) {
					united_ck++;
					bfs(i, j, united_ck);
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				move_pop[i][j] = total[united[i][j] - 1][0] / total[united[i][j] - 1][1];
			}
		}

		// 이게 시간 초과 났던 원인
		/*for (int k = 1; k <= united_ck; k++) {
			int sum = 0, cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (united[i][j] == k) {
						sum += map[i][j];
						cnt++;
					}
				}
			}

			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (united[i][j] == k)
						move_pop[i][j] = sum / cnt;
		}*/

		// map[i][j]      --> 인구 이동 전 인구수
		// move_pop[i][j] --> 인구 이동 후 인구수

		if (!check()) {
			result++;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					map[i][j] = move_pop[i][j];
				}
			}
		}
		else
			break;
	}
	cout << result << "\n";
	return 0;
}
