#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 102
#define INF 987654321

using namespace std;

// bfs를 하면서 열쇠(소문자)를 얻는 시점에서 map 전부를 탐색하며 제거할 수 있는 대문자 제거
// 그 후 방문 표시를 모두 초기화 한 후 열쇠를 얻은 지점에서 다시 bfs를 진행
// 문서, 열쇠, 대문자를 제거하거나 얻을 때 해당 지점을 '.'으로 표시하여 중복 방지

struct node {
	int r;
	int c;
};

int tc, n, m, result;
string keys;
bool isVisit[SIZE][SIZE];
char map[SIZE][SIZE];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

vector<char> key;

void print() {
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < m + 2; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

bool isKey(char c) {
	for (int i = 0; i < key.size(); i++)
		if (key[i] == c)
			return true;
	return false;
}

void bfs() {

	queue<node> q;
	q.push({ 0, 0 });
	isVisit[0][0] = true;

	while (!q.empty()) {

		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		for (int i = 0; i < 4; i++) {

			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr < 0 || nc < 0 || nr > n + 1 || nc > m + 1) continue;
			if (isVisit[nr][nc] || map[nr][nc] == '*') continue;
			if (map[nr][nc] >= 'A' && map[nr][nc] <= 'Z') continue;

			if (!isVisit[nr][nc]) {

				if (map[nr][nc] == '.') {
					q.push({ nr, nc });
					isVisit[nr][nc] = true;
				}

				if (map[nr][nc] == '$') {
					q.push({ nr, nc });
					map[nr][nc] = '.';
					result++;
					isVisit[nr][nc] = true;
				}

				if (map[nr][nc] >= 'a' && map[nr][nc] <= 'z') {
					char alph = map[nr][nc];
					map[nr][nc] = '.';
					if (!isKey(alph)) {
						key.push_back(alph);
						for (int h = 0; h < n + 2; h++)
							for (int w = 0; w < m + 2; w++)
								if (map[h][w] == toupper(alph))
									map[h][w] = '.';
					}
					memset(isVisit, false, sizeof(isVisit));
					while (!q.empty()) q.pop();
					q.push({ nr, nc });
					isVisit[nr][nc] = true;
				}
			}
		}
	}
}

int main(void) {

	cin >> tc;

	while (tc--) {
		memset(isVisit, false, sizeof(isVisit));
		key.clear();
		result = 0;

		cin >> n >> m;
		for (int i = 0; i < n + 2; i++) {
			for (int j = 0;j < m + 2; j++) {
				if (i == 0 || i == n + 1 || j == 0 || j == m + 1)
					map[i][j] = '.';
				else scanf(" %1c", &map[i][j]);
			}
		}

		cin >> keys;
		if (keys != "0") {

			for (int i = 0; i < keys.length(); i++)
				key.push_back(keys[i]);

			for (int i = 0; i < n + 2; i++) {
				for (int j = 0; j < m + 2; j++) {
					if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
						for (int k = 0; k < key.size(); k++) {
							if (tolower(map[i][j]) == key[k])
								map[i][j] = '.';
						}
					}
				}
			}
		}

		bfs();

		cout << result << "\n";
	}
	return 0;
}
