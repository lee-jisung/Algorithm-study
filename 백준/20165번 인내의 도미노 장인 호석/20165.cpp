#include <iostream>
#include <queue>

using namespace std;

/*
   쓰러뜨릴 도미노 길이와 좌표를 큐에 담고
   도미노 길이 만큼 쓰러뜨릴 방향으로 'S' 상태의 도미노 좌표와 길이를 큐에 넣고, 상태를 F로 바꿈
*/

int n, m, r, fallCount;
int dominoLen[101][101];
char dominoState[101][101];

int dr[4] = { 0, 0, 1, -1 }, dc[4] = { 1, -1, 0, 0 };

int convertDir(char d) {
	switch (d) {
	case 'E': return 0;
	case 'W': return 1;
	case 'S': return 2;
	case 'N': return 3;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> dominoLen[i][j];
			dominoState[i][j] = 'S';
		}
	}

	for (int rd = 0; rd < r; rd++) {
		int x, y; char d;

		// 공격
		cin >> y >> x >> d;
		int idx = convertDir(d); // 방향 인덱스 구하기
		
		if (dominoState[y][x] != 'F') { // 쓰러지지 않은 도미노에 대해서만 
			queue<pair<pair<int, int>, int>> q;
			q.push({ {y, x}, dominoLen[y][x] });
			dominoState[y][x] = 'F';
			fallCount++;

			while (!q.empty()) {

				int r = q.front().first.first;
				int c = q.front().first.second;
				int len = q.front().second;
				q.pop();

				// 길이만큼 쓰러뜨릴 방향으로 서있는 도미노를 쓰러뜨림
				for (int i = 0; i < len; i++) {
					int nr = r + i * dr[idx];
					int nc = c + i * dc[idx];
					if (nr > n || nc > m || nr < 1 || nc < 1) break; // 범위 벗어난 경우 break
					if (dominoState[nr][nc] == 'S') {
						dominoState[nr][nc] = 'F';
						fallCount++;
						q.push({ {nr, nc}, dominoLen[nr][nc] });
					}
				}
			}
		}

		// 수비 
		cin >> y >> x;
		if (dominoState[y][x] == 'F')
			dominoState[y][x] = 'S';
	}

	cout << fallCount << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << dominoState[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
