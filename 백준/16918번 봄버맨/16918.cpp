#include <iostream>
#include <queue>

#define SIZE 201

using namespace std;

int R, C, N, time, boom_size;
char board[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> N;

	queue<pair<int, int>> boom;

	for (int i = 0; i < R; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < C; j++) {
			board[i][j] = temp[j];
			if (board[i][j] == 'O') boom.push({ i, j });
		}
	}

	while (1) {
		time++;
		if (time % 2 == 0) { // 짝수 초
			// 설치 전 폭탄 개수 저장 후 새로운 폭탄을 설치
			boom_size = boom.size();
			for(int i= 0; i<R; i++)
				for (int j = 0; j < C; j++) {
					if (board[i][j] == '.') {
						board[i][j] = 'O';
					}
				}
		}
		else { // 홀수 초
			// 새로운 폭발물을 제외한 기존의 폭탄들 전부 폭발
			while (boom_size--) {

				int r = boom.front().first;
				int c = boom.front().second;

				boom.pop();
				board[r][c] = '.';

				for (int i = 0; i < 4; i++) {
					int nr = r + dr[i], nc = c + dc[i];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
					board[nr][nc] = '.';
				}
			}
			// 폭발 후에 남아 있는 폭탄에 대해서 폭탄을 터트려야 하므로 boom에 저장
			// 짝수 초 때 폭탄을 설치하면서 터트려야하는 boom을 저장하면 기존 폭탄이 터지면서 새롭게 설치되었다가 
			// 터진 폭탄마저 터져야하는 리스트에 들어가기 때문에 여기서 저장해줌
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++) {
					if (board[i][j] == 'O') {
						boom.push({ i,j });
					}
				}

		}
		if (N == time) break;
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}


	return 0;
}
