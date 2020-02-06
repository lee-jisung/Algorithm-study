#include <iostream>
#include <deque>
#include <algorithm>

#define SIZE 11

using namespace std;

// tree vector를 삶, 죽음 기준으로 sorting해서 죽은것들을 뒤로 몰아 pop_back시켜
// 나이 어린순으로 sorting

int n, m, k, result;
int nutrient[SIZE][SIZE], map[SIZE][SIZE];
int dx[8] = { -1, -1, -1, 0, 0, 1 ,1 ,1 };
int dy[8] = { -1, 0, 1, -1, 1 ,-1, 0, 1 };

deque<int> tree[SIZE][SIZE][2];

bool isRange(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

void spring() {

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = tree[i][j][0].size();
			for (int t = 0; t < size; t++) {

				int age = tree[i][j][0].front();
				tree[i][j][0].pop_front();
				if (map[i][j] >= age) {
					map[i][j] -= age;
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

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = tree[i][j][1].size();
			for (int t = 0; t < size; t++) {
				int age = tree[i][j][1].front();
				tree[i][j][1].pop_front();
				map[i][j] += age / 2;
			}
		}
	}
}

void fall() {
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			
			for (auto iter = tree[i][j][0].begin(); iter != tree[i][j][0].end(); iter++) {
				if (*iter % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (isRange(nx, ny)) {
							tree[nx][ny][0].push_front(1);
						}
					}
				}
			}

		}
	}
}

void winter() {

	for (int i = 1;i <=n; i++)
		for (int j = 1; j <=n; j++)
			map[i][j] += nutrient[i][j];

}

int main(void) {

	cin >> n >> m >> k;

	for (int i = 1; i <=n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> nutrient[i][j];
			map[i][j] = 5;
		}

	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		tree[x][y][0].push_back(age);
	}

	// 주어지는 나무의 위치가 모두 서로 다르다 --> 겹치는 나무가 없으니 처음에 받을때 sorting할 필요 없고
	// 새로 번식되는 나무를 앞에서부터 추가시키면 나이순으로 정렬될것
	// 따라서 sorting할 필요가 없음 

	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			result += tree[i][j][0].size();
	
	cout << result << "\n";
	return 0;
}
