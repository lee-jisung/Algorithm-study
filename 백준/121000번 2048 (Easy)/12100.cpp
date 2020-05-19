#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define SIZE 21

using namespace std;

int dir[4] = { 1, 2, 3, 4 }; // up, right, down, left
int moved[5], board[SIZE][SIZE], temp[SIZE][SIZE];
int n, result;

void copy() {
	for (int i = 0; i < n; i++)
		for (int j = 0;j < n; j++)
			temp[i][j] = board[i][j];
}

int get_result() {
	int max_val = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0;j < n; j++)
			max_val = max(temp[i][j], max_val);
	return max_val;
}

/*
   한줄씩 전부 queue에 넣고 가장 처음 index에 queue 요소 하나 넣고
   만약 현재 가리키는 idx의 요소가 다시 꺼낸 것과 같다면 더해준다음 다음 칸을 가리키도록 idx++
   만약 다르다면 idx를 ++해주고 거기에 요소를 넣어줌
*/
void move_board() {

	for (int i = 0; i < 5; i++) {

		queue<int> q;
		switch (dir[moved[i]-1]) {

		case 1: // up
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (temp[j][i]) q.push(temp[j][i]);
					temp[j][i] = 0;
				}

				int idx = 0;
				while (!q.empty()) {
					int num = q.front();
					q.pop();

					if (temp[idx][i] == 0)
						temp[idx][i] = num;
					else if (temp[idx][i] == num) {
						temp[idx][i] *= 2;
						idx++;
					}
					else {
						idx++;
						temp[idx][i] = num;
					}
				}
			}
			break;

		case 2: // right
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					if (temp[i][j]) q.push(temp[i][j]);
					temp[i][j] = 0;
				}

				int idx = n-1;
				while (!q.empty()) {

					int num = q.front();
					q.pop();

					if (temp[i][idx] == 0)
						temp[i][idx] = num;
					else if (temp[i][idx] == num) {
						temp[i][idx] *= 2;
						idx--;
					}
					else {
						idx--;
						temp[i][idx] = num;
					}
				}
			}
			break;

		case 3: // down
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					if (temp[j][i]) q.push(temp[j][i]);
					temp[j][i] = 0;
				}

				int idx = n - 1;
				while (!q.empty()) {

					int num = q.front();
					q.pop();

					if (temp[idx][i] == 0) temp[idx][i] = num;
					else if (temp[idx][i] == num) {
						temp[idx][i] *= 2;
						idx--;
					}
					else {
						idx--;
						temp[idx][i] = num;
					}
				}
			}
			break;

		case 4: // left
			for (int i = 0;i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (temp[i][j]) q.push(temp[i][j]);
					temp[i][j] = 0;
				}

				int idx = 0;
				while (!q.empty()) {

					int num = q.front();
					q.pop();

					if (temp[i][idx] == 0) temp[i][idx] = num;
					else if (temp[i][idx] == num) {
						temp[i][idx] *= 2;
						idx++;
					}
					else {
						idx++;
						temp[i][idx] = num;
					}
				}
			}
			break;
		}
	}
}

void dfs(int cnt) {

	if (cnt == 5) {
		copy();
		move_board();
		result = max(result, get_result());
		return;
	}

	for (int i = 0; i < 4; i++) {
		moved[cnt] = dir[i];
		dfs(cnt + 1);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	dfs(0);

	cout << result << "\n";

	return 0;
}
