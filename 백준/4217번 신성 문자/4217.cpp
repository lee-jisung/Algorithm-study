#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

/*
   상형 문자 마다 구멍 개수가 다름 => 각 문자별로 구멍 개수를 파악
   1. 16진수 => decoding => 상형문자 표시
   2. 상형문자 제외한 빈칸을 flood fill(key값) => 배경인 key값은 따로 표시
   3. 상형문자를 flood fill하면서 배경이 아닌 key값이 인접해 있다면 구멍개수를 count해주고 방문처리 해줌
*/

int h, w, tc;
int hexa[16][4];
int letter[200][200], afterFloodFill[200][200];
bool isBackground[200], isNotWhole[200];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, -1, 0, 1 };

void init() {
	memset(letter, 0, sizeof(letter));
	memset(afterFloodFill, 0, sizeof(afterFloodFill));
	memset(isBackground, false, sizeof(isBackground));
	memset(isNotWhole, false, sizeof(isNotWhole));
}

void bfs(int y, int x, int cnt) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	afterFloodFill[y][x] = cnt;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= h || nc >= 4 * w) {
				isBackground[cnt] = true;
				continue;
			}
			if (afterFloodFill[nr][nc] != 0 || letter[y][x] != letter[nr][nc]) continue;
			q.push({ nr, nc });
			afterFloodFill[nr][nc] = cnt;
		}
	}
}

int getWholeCount(int y, int x, int cnt) {
	queue<pair<int, int>> q;
	q.push({ y, x });
	afterFloodFill[y][x] = cnt;
	isNotWhole[cnt] = true;
	int wCnt = 0;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= h || nc >= 4 * w) continue;
			if (letter[nr][nc] != letter[y][x]) { // 상형문자가 아닌 경우
				if (isBackground[afterFloodFill[nr][nc]] == false && isNotWhole[afterFloodFill[nr][nc]] == false) {
					isNotWhole[afterFloodFill[nr][nc]] = true;
					wCnt++;
					continue;
				}
			}
			if (afterFloodFill[nr][nc] != 0) continue;
			q.push({ nr, nc });
			afterFloodFill[nr][nc] = cnt;
		}
	}
	return wCnt;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 16; i++) {
		int num = i, f = 3;
		while (num != 0) {
			hexa[i][f--] = num % 2;
			num /= 2;
		}
	}

	while (1) {
		init();
		cin >> h >> w;
		if (!h && !w) break;
		// decoding
		for (int i = 0; i < h; i++) {
			string s; cin >> s;
			for (int j = 0; j < w; j++) {
				int idx = s[j] >= 'a' ? s[j] - 'a' + 10 : s[j] - '0';
				for (int k = 0; k < 4; k++)
					letter[i][j * 4 + k] = hexa[idx][k];
			}
		}

		// 상형문자 제외 0으로 된 빈칸을 값을 달리해서 채우기
		// 배경인 경우는 해당 값을 체크 (isBackground)
		int cnt = 1;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < 4 * w; j++) {
				if (afterFloodFill[i][j] == 0 && letter[i][j] == 0) {
					bfs(i, j, cnt++);
				}
			}
		}

		vector<char> result;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w * 4; j++) {
				// 상형문자 테두리이면 bfs해서 상형문자를 수로 채우면서 
				// 배경이 아닌 구멍을 만났을 때 count해줌
				if (afterFloodFill[i][j] == 0 && letter[i][j] == 1) {
					int wholeCount = getWholeCount(i, j, cnt++);
					switch (wholeCount) {
					case 0:
						result.push_back('W');
						break;
					case 1:
						result.push_back('A');
						break;
					case 2:
						result.push_back('K');
						break;
					case 3:
						result.push_back('J');
						break;
					case 4:
						result.push_back('S');
						break;
					case 5:
						result.push_back('D');
						break;
					}
				}
			}
		}

		sort(result.begin(), result.end());
		cout << "Case " << ++tc << ": ";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i];
		}
		cout << "\n";
	}
	return 0;
}
