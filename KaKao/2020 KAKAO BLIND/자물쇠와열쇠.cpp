#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n, m;
int board[61][61], temp[61][61], keys[21][21];

// 90도씩 회전
void rotate() {
	int rot[21][21];
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < m; j++) 
			rot[j][i] = keys[m - 1 - i][j];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			keys[i][j] = rot[i][j];
}

bool findKey(int r, int c) {
	for (int i = 0; i <= n + m; i++)
		for (int j = 0; j <= n + m; j++)
			temp[i][j] = board[i][j];

	// 자물쇠와 열쇠를 합침
	for (int i = r; i < r + m; i++)
		for (int j = c; j < c + m; j++)
			temp[i][j] += keys[i - r][j - c]; 

	// 합친 값이 1이 아니면 false
	// => 열쇠 1, 자물쇠 1이 겹치거나, 자물쇠가 0이라면 안됨
	for (int i = m - 1; i < n + m - 1; i++)
		for (int j = m - 1; j < n + m - 1; j++)
			if (temp[i][j] != 1) return false;
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;

	m = key[0].size(); n = lock[0].size();

	for (int i = m - 1; i < n + m - 1; i++) 
		for (int j = m - 1; j < n + m - 1; j++) 
			board[i][j] = lock[i - (m - 1)][j - (m - 1)];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			keys[i][j] = key[i][j];

	// 회전 4번 확인
	for (int k = 0; k < 4; k++) {

		// key 위치를 0,0부터 n+m-2 (lock의 끝부분) 인 위치까지 
		for (int i = 0;i <= n + m - 2; i++) {
			for (int j = 0; j <= n + m - 2; j++) {
				answer = findKey(i, j);
				if (answer) 
					return answer;
			}
		}
		rotate();
	}

	return answer;
}

int main(void) {

	vector<vector<int>> key = {
		{0, 0, 0, 1}, 
		{0, 1, 0, 1}, 
		{0, 0, 1, 1},
		{1, 0, 1, 1}
	};
	vector<vector<int>> lock = { 
		{1, 1, 1, 1, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 1},
		{1, 1, 1, 0, 1},
		{0, 1, 1, 1, 1}
	};

	cout << solution(key, lock);

	return 0;
}
