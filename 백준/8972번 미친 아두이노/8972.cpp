#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

int R, C, moves;
char board[SIZE][SIZE], temp[SIZE][SIZE];
string order;
bool success = true;

pair<int, int> jong;
int dr[9] = { 1, 1, 1, 0, 0, 0, -1, -1 ,-1 }, dc[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C;j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}
}

void copy() {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (temp[i][j] == 'R') board[i][j] = 'R';
			else if (temp[i][j] == 'I') board[i][j] = 'I';
			else board[i][j] = '.';
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < C; j++) {
			board[i][j] = temp[j];
			if (board[i][j] == 'I') jong = { i,j };
		}
	}
	cin >> order;

	for (int o = 0; o < order.length(); o++) {
		memset(temp, '.', sizeof(temp));
		int idx = order[o] - '0' - 1;
		moves++;
		jong.first += dr[idx], jong.second += dc[idx];
		temp[jong.first][jong.second] = 'I';
		if (board[jong.first][jong.second] == 'R') {
			success = false;
			break;
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {

				if (board[i][j] == 'R') {
					int dist = INF, id;
					for (int k = 0; k < 9; k++) {
						int nr = i + dr[k], nc = j + dc[k];
						if (nr < 0 || nc < 0 || nr >= R || nc >= C) continue;
						if (dist > abs(nr - jong.first) + abs(nc - jong.second)) {
							dist = abs(nr - jong.first) + abs(nc - jong.second);
							id = k;
						}
					}
					int nr = i + dr[id], nc = j + dc[id];
					if (nr == jong.first && nc == jong.second) success = false;
					if (temp[nr][nc] == 'R' || temp[nr][nc] == 'X') temp[nr][nc] = 'X';
					else temp[nr][nc] = 'R';
				}
			}
		}
		copy();
		if (!success) break;
	}

	if (success) print();
	else cout << "kraj " << moves << "\n";
	return 0;
}
