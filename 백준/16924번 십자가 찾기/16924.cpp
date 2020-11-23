#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
   모든 '*'의 좌표 상에서 십자가를 그릴 수 있는지 여부 확인
   그릴 수 있다면 각 크기마다 result 벡터에 추가

   result벡터가 비어있다면 -1 출력
   비어있지 않다면, temp에 result 정보로 *를 그린 후, 원래의 값인 board와 비교
   그림이 다르다면 -1 출력
   같다면 result 값 출력
 */

int n, m;
vector<pair<pair<int, int>, int>> result;
vector<pair<int, int>> star;
char board[101][101], temp[101][101];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, -1, 0, 1 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str; cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j];
			temp[i][j] = '.';
			if (board[i][j] == '*') star.push_back({ i, j });
		}
	}
	// 모든 좌표마다 십자가 그릴 수 있는지 확인
	for (int i = 0; i < star.size(); i++) {
		int r = star[i].first;
		int c = star[i].second;
		bool isCross = true;
		int size = 0;
		while (1) {
			int nr, nc;
			for (int i = 0; i < 4; i++) {
				nr = r + dr[i] * (size + 1);
				nc = c + dc[i] * (size + 1);
				if (nr < 0 || nc < 0 || nr >= n || nc >= m || board[nr][nc] != '*') {
					isCross = false;
				}

			}
			if (!isCross) break;
			// 사이즈 마다 값 저장
			size++;
			result.push_back({ {r + 1, c + 1}, size });
		}
	}

	// 비어있으면 -1
	if (result.empty()) {
		cout << -1 << "\n";
		return 0;
	}

	// result값으로 다시 temp에 * 그리기
	for (int i = 0; i < result.size(); i++) {
		int r = result[i].first.first - 1;
		int c = result[i].first.second - 1;
		int size = result[i].second;
		temp[r][c] = '*';
		int nr, nc;
		for (int j = 1; j <= size; j++) {
			for (int k = 0; k < 4; k++) {
				nr = r + dr[k] * j;
				nc = c + dc[k] * j;
				temp[nr][nc] = '*';
			}
		}
	}
	
	// 원본과 같은지 확인
	bool isMatch = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '*' && temp[i][j] == '.') {
				isMatch = false;
				break;
			}
		}
		if (!isMatch) break;
	}

	if (!isMatch) cout << -1 << "\n";
	else {
		cout << result.size() << "\n";
		for (int i = 0; i < result.size(); i++) {
			cout << result[i].first.first << " " << result[i].first.second << " " << result[i].second << "\n";
		}
	}
	return 0;
}
