#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct Cell {
	int vital;
	int time;
};

int TC;
int n, m, k, result;
Cell cell[700][700];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

void init() {
	for (int i = 0; i < 700;i++)
		for (int j = 0; j < 700; j++)
			cell[i][j].vital = cell[i][j].time = 0;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		init();
		queue<pair<int, int>> cell_q[11];
		result = 0;
		cin >> n >> m >> k;
		for (int i = 300; i < 300 + n; i++) {
			for (int j = 300; j < 300 + m; j++) {

				int vitality; 
				cin >> vitality;

				cell[i][j].vital = vitality;
				cell[i][j].time = 2 * vitality; // 시간을 2배로 => 비활성 + 활성

				if (vitality != 0) {
					cell_q[vitality].push({ i, j }); // 생명력 수치별 q 관리
				}
			}
		}

		for (int t = 1; t <= k; t++) {

			//생명력이 높은 수치부터
			for (int i = 10; i >= 1; i--) {
				int qsize = cell_q[i].size();
				for (int j = 0; j < qsize; j++) {

					int r = cell_q[i].front().first;
					int c = cell_q[i].front().second;
					cell_q[i].pop();
					cell[r][c].time--;

					// 세포 시간이 생명력보다 작아진다면 => 비활성에서 활성이 된것
					if (cell[r][c].vital > cell[r][c].time) {
						// 세포 번식
						for (int d = 0; d < 4; d++) {
							int nr = r + dr[d];
							int nc = c + dc[d];
							// 생명력 높은 수치부터 번식하기 때문에 동시 번식시 우선순위 고려할필요없음
							if (cell[nr][nc].vital == 0) {
								cell[nr][nc].vital = cell[r][c].vital;
								cell[nr][nc].time = cell[r][c].vital * 2;
								cell_q[i].push({ nr, nc });

							}
						}
					}
					// 비활성 or 활성이면 계속 큐에 push
					if (cell[r][c].time != 0) {
						cell_q[i].push({ r, c });
					}

				}
			}
		}

		for (int i = 1; i <= 10; i++)
			result += cell_q[i].size();
		cout << "#" << tc << " " << result << "\n";
	}
	

	return 0;
}
