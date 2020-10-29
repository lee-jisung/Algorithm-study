#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m, result;
int board[4][4], cutPaper[4][4];

// 0 => 세로 종이
// 1 => 가로 종이

void dfs(int y, int x) {
	// 마지막 좌표까지 확인한 후, 가로 세로 조각으로 자른 것 합 구하기
	if (y >= n) {
		int sum = 0;
		// 행마다 연속된 가로 종이 합 구하기
		for (int i = 0; i < n; i++) {
			int tempSum = 0;
			for (int j = 0; j < m; j++) {
				if (cutPaper[i][j] == 1) {
					tempSum *= 10;
					tempSum += board[i][j];
				}
				else {
					sum += tempSum;
					tempSum = 0;
				}
			}
			sum += tempSum;
		}

		// 열마다 연속된 세로 종이 합 구하기
		for (int i = 0; i < m; i++) {
			int tempSum = 0;
			for (int j = 0; j < n; j++) {
				if (cutPaper[j][i] == 0) {
					tempSum *= 10;
					tempSum += board[j][i];
				}
				else {
					sum += tempSum;
					tempSum = 0;
				}
			}
			sum += tempSum;
		}
		result = max(result, sum);
		return;
	}

	// 열의 끝까지 이동했으면 다음 행으로
	if (x >= m) {
		dfs(y + 1, 0);
		return;
	}

	// 가로, 세로 각각 선택한 경우를 dfs로 탐색
	cutPaper[y][x] = 1;
	dfs(y, x + 1);
	cutPaper[y][x] = 0;
	dfs(y, x + 1);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++)
			board[i][j] = s[j] - '0';
	}

	dfs(0, 0);

	cout << result << "\n";

	return 0;
}
