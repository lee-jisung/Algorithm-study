#include <iostream>

#define INF 1e9

// 최소 높이 ~ 최대 높이의 모든 경우에 대해서 높낮이를 만드는 시간을 구함

using namespace std;

int n, m, b;
int board[501][501];
int maxh, minh, minTime, maxHeight;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	minh = minTime = INF;

	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < m;j++) {
			cin >> board[i][j];
			if (minh > board[i][j]) minh = board[i][j];
			if (maxh < board[i][j]) maxh = board[i][j];
		}
	}

	for (int h = minh; h <= maxh; h++) {
		int remove = 0, build = 0;
		for (int i = 0; i < n;i++) {
			for (int j = 0;j < m;j++) {
				int tmp = board[i][j] - h;
				if (tmp > 0) remove += tmp;
				else if (tmp < 0) build -= tmp;
			}
		}

		// 제거 높이 + 주어진 높이가 지어진 높이일 때 시간 구함
		if (remove + b >= build) {
			int time = remove * 2 + build;
			if (minTime >= time) {
				minTime = time;
				maxHeight = h;
			}
		}
	}

	cout << minTime << " " << maxHeight << "\n";
	return 0;
}
