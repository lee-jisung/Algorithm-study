#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 41
#define INF 987654321

using namespace std;

int n, m, k, r, c, result;
int map[SIZE][SIZE], sticker[SIZE][SIZE];
bool flag;

// 90도씩 돌리기
void rotate() {

	int temp[SIZE][SIZE], s;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			temp[j][(r-1) - i] = sticker[i][j];
		}
	}
	s = r; r = c; c = s;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			sticker[i][j] = temp[i][j];
}

// 각 지점에서 sticker 범위가 map의 범위를 벗어나거나 
// sticker의 1과 map의 1이 겹치면 false를 return
bool check(int x, int y) {
	if (x + r > n || y + c > m) return false;
	for (int i = x; i < r + x; i++) {
		for (int j = y; j < c + y; j++) {
			if ((map[i][j] & sticker[i - x][j - y]) == 1) {
				return false;
			}
		}
	}
	return true;
}

// sticker를 붙일 수 있는 경우 붙임
void copy(int x, int y) {
	for (int i = x; i < r + x; i++) {
		for (int j = y; j < c + y; j++) {
			if (map[i][j] == 1 && sticker[i - x][j - y] == 0) map[i][j] = 1;
			else map[i][j] = sticker[i - x][j - y];
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;


	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
			}
		}

		flag = false;

		for (int rot = 0; rot < 4; rot++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0;j < m; j++) {
					if (flag) break;
					if (check(i, j) && !flag) {
						copy(i, j);
						flag = true;
					}
				}
			}
			rotate();
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j]) result++;

	cout << result << "\n";

	return 0;
}
