#include <iostream>
#include <queue>

#define SIZE 21

using namespace std;

// 1 상, 2 하, 3 좌, 4 우

int n, result;
int board[SIZE][SIZE], cube[SIZE][SIZE], moved[5];

int moving() {

	int val = 0;

	for (int i = 0; i < 5; i++) {
		switch (moved[i]) {
		case 1:
			for (int i = 0;i < n;i++) {
				queue<int> q;
				for (int j = 0; j < n; j++) {
					if (cube[j][i]) q.push(cube[j][i]);
					cube[j][i] = 0;
				}
				int idx = 0;
				while (!q.empty()) {

					int num = q.front();
					q.pop();
					if (cube[idx][i] == 0) {
						cube[idx][i] = num;
					}
					else if (cube[idx][i] == num) {
						cube[idx][i] *= 2;
						idx++;
					}
					else {
						idx++;
						cube[idx][i] = num;
					}
				}
			}
			break;
		case 2:
			for (int i = 0;i < n;i++) {
				queue<int> q;
				for (int j = n-1; j >=0; j--) {
					if (cube[j][i]) q.push(cube[j][i]);
					cube[j][i] = 0;
				}
				int idx = n - 1;
				while (!q.empty()) {
					int num = q.front();
					q.pop();
					if (cube[idx][i] == 0) {
						cube[idx][i] = num;
					}
					else if (cube[idx][i] == num) {
						cube[idx][i] *= 2;
						idx--;
					}
					else {
						idx--;
						cube[idx][i] = num;
					}
				}
			}
			break;
		case 3:
			for (int i = 0;i < n;i++) {
				queue<int> q;
				for (int j = 0; j < n; j++) {
					if (cube[i][j]) q.push(cube[i][j]);
					cube[i][j] = 0;
				}
				int idx = 0;
				while (!q.empty()) {
					int num = q.front();
					q.pop();
					if (cube[i][idx] == 0) {
						cube[i][idx] = num;
					}
					else if (cube[i][idx] == num) {
						cube[i][idx] *= 2;
						idx++;
					}
					else {
						idx++;
						cube[i][idx] = num;
					}
				}
			}
			break;
		case 4:
			for (int i = 0;i < n;i++) {
				queue<int> q;
				for (int j = n-1; j>=0; j--) {
					if (cube[i][j]) q.push(cube[i][j]);
					cube[i][j] = 0;
				}
				int idx = n-1;
				while (!q.empty()) {
					int num = q.front();
					q.pop();
					if (cube[i][idx] == 0) {
						cube[i][idx] = num;
					}
					else if (cube[i][idx] == num) {
						cube[i][idx] *= 2;
						idx--;
					}
					else {
						idx--;
						cube[i][idx] = num;
					}
				}
			}
			break;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			val = max(val, cube[i][j]);

	return val;
}

void copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cube[i][j] = board[i][j];
}

void dfs(int no) {

	if (no == 5) {
		copy();
		result = max(result, moving());
		return;
	}

	for (int i = 1; i <= 4; i++) {
		moved[no] = i;
		dfs(no + 1);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0;j < n; j++)
			cin >> board[i][j];
	dfs(0);

	cout << result << "\n";

	return 0;
}
