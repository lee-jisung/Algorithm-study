#include <iostream>
#include <algorithm>
#include <cstring>

#define SIZE 51

/*
   dfs - 탐색하는 방향 dir과 길이 len을 주고 방향이 바뀔 때 마다 len을 +1일 해주면서 선분이
         4개 이상일 때를 확인
       - 시작 점과 탐색 점이 같아질 때 조건에 맞으면 true
*/

using namespace std;

int n, m;
bool isCycle, isVisit[SIZE][SIZE];
char board[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void dfs(int r, int c, int str, int stc, int dir, int len) {

	if (isCycle) return;
	
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;

		if (!isVisit[nr][nc]) {
			if (board[nr][nc] == board[r][c]) {
				isVisit[nr][nc] = true;
				if (i == dir) dfs(nr, nc, str, stc, i, len);
				else dfs(nr, nc, str, stc, i, len + 1);
			}
		}
		else {
			if (nr == str && nc == stc && len >= 4) {
				isCycle = true;
				return;
			}
		}
	}
}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < m; j++)
			board[i][j] = temp[j];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			for (int k = 0; k < 4; k++) {
				memset(isVisit, false, sizeof(isVisit));
				isVisit[i][j] = true;
				dfs(i, j, i, j, k, 1);
				if (isCycle) {
					cout << "Yes\n";
					return 0;
				}
			}
		}
	}
	cout << "No\n";

	return 0;
}
