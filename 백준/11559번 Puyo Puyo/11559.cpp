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

/*
   1. bfs에서 4개 이상의 터질 수 있는 그룹이 있는지 여부를 확인 
     1-1. 4개 이상의 터질 수 있는 그룹이 있으면 crash(vector)에 좌표를 저장
	 1-2. 좌표 저장한 것을 오름차순으로 정렬 (cmp 이용)
	 1-3. board[j][i] = board[j-1][i]를 이용하여 오름차순으로 정렬된 좌표에 모두 적용 후 board[0][i]를 '.'으로 바꿔줌
	 1-4. 모든 좌표에 대해서 작업 후 result 값 1 증가 (연쇄 1 증가)

   2. 4개 이상의 그룹이 없다면 crash가 비어있을 것이므로 bfs 종료
 
*/

using namespace std;

int n, m, result; 
char board[12][6];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < 12 && c < 6;
}

bool cmp(pair<int, int> a, pair<int, int > b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void bfs() {

	queue<pair<int, int > > q;
	while (1) {

		vector<pair<int, int>> crash;
		bool isVisit[12][6] = { false };

		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {

				if (board[i][j] != '.') {

					char color = board[i][j];
					queue<pair<int, int> > popped;
					isVisit[i][j] = true;
					q.push({ i, j });

					while (!q.empty()) {

						int r = q.front().first;
						int c = q.front().second;
						popped.push({ r, c });
						q.pop();

						for (int k = 0; k < 4; k++) {

							int nr = r + dx[k];
							int nc = c + dy[k];
							if (!isRange(nr, nc)) continue;
							if (board[nr][nc] == color && !isVisit[nr][nc]) {
								q.push({ nr,nc });
								isVisit[nr][nc] = true;
							}
						}
					}
					if (popped.size() >= 4) {
						while (!popped.empty()) {
							crash.push_back({ popped.front().first, popped.front().second });
							popped.pop();
						}
					}
				}
			}
		}

		if (!crash.empty()) {
			sort(crash.begin(), crash.end(), cmp);
			for (int i = 0; i < crash.size(); i++) {
				for (int j = crash[i].first; j > 0; j--) 
					board[j][crash[i].second] = board[j - 1][crash[i].second];
				board[0][crash[i].second] = '.';
			}
			result++;
		}
		else
			break;
	}
}

int main(void) {


	for (int i = 0; i < 12;i++) {
		for (int j = 0; j < 6; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	bfs();

	cout << result << "\n";

	return 0;
}
