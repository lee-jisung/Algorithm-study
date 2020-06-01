#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>

#define SIZE 11

using namespace std;

/*
   나무 -> tree[n][n][0]에는 산 나무 / tree[n][n][1] 에는 죽은 나무의 나이를 관리

   봄 -> 각 위치의 나무 개수만큼 양분을 먹고 자신의 나이 +1을 해준 후, 다시 push 
      - 양분이 자신의 나이보다 적으면 죽은나무 tree[n][n][1]에 push_back 해줌

   여름 -> 각 칸에 위치한 tree[i][j][1]의 나무를 전부 pop시켜서 1/2한 값을 board[i][j]에 더함

   가을 -> tree[i][j][0]에 위치한 나무들 중 (나이 % 5 ==0)인 나무들이 있으면 
        - 8방향 칸에 전부 나이 1인 나무를 push_front() (나이 % 5==0)인 나무도 다시 제자리로 push
   
   겨울 - 영양분 보충

   deque 사용 -> 나이가 적은 것을 push_front하고 나이를 먹는 것을 push_back 해줌으로써 
              -> 나이가 적은 것 순으로 정렬이 되도록 구현
*/

int n, m, k, result;
int board[SIZE][SIZE], nutri[SIZE][SIZE];
deque<int> tree[SIZE][SIZE][2];

int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dc[8] = { -1, 0, 1, -1, 1, -1 ,0, 1 };

void spring() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			int len = tree[i][j][0].size();
			while (len--) {
				int age = tree[i][j][0].front();
				tree[i][j][0].pop_front();
				if (board[i][j] >= age) {
					board[i][j] -= age;
					age++;
					tree[i][j][0].push_back(age);
				}
				else {
					tree[i][j][1].push_back(age);
				}
			}
		}
	}
}

void summer() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (!tree[i][j][1].empty()) {
				int age = tree[i][j][1].front();
				tree[i][j][1].pop_front();
				board[i][j] += age / 2;
			}
		}
	}
}

void fall() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int len = tree[i][j][0].size();
			while (len--) {
				int age = tree[i][j][0].front();
				tree[i][j][0].pop_front();
				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int nr = i + dr[k];
						int nc = j + dc[k];
						if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
						tree[nr][nc][0].push_front(1);
					}
				}
				tree[i][j][0].push_back(age);
			}
		}
	}

}

void winter() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] += nutri[i][j];
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> nutri[i][j];

	for (int i = 0; i < n; i++)
		fill(board[i], board[i] + n, 5);

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		tree[x-1][y-1][0].push_front(z);
	}
	
	while (k--) {
		spring();
		summer();
		fall();
		winter();
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result += tree[i][j][0].size();

	cout << result << "\n";

	return 0;
}
