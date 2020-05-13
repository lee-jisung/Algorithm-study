#include <iostream>
#include <deque>

#define SIZE 101

using namespace std;

/*
   deque을 사용해서 snake의 머리부분을 deque의 back으로 생각하고 새롭게 이동하는 부분을 deque에 push해줌

   만약 새롭게 이동하는 부분에 사과가 있다면 snake deque에서 front부분을 그대로 두고 apple만 먹은 표시를 해줌

   새롭게 이동하는 부분에 사과가 없다면 새로 이동한 좌표를 back에 넣고, snake에 front부분을 pop해줌 (moved도 false로)

   moved의 역할 -> 현재 snake의 위치를 표시해서 만약 머리가 꼬리부분에 닿는다면 종료하기 위함

   명령을 수행해야 할 시간이 온 경우 방향을 바꿔 새롭게 이동할 방향을 정해줌
*/

int n, k, l, time, idx;
bool moved[SIZE][SIZE], apple[SIZE][SIZE];

deque<pair<int, int>> snake;
deque<pair<int, char>> order;

int dr[4] = { 0, 1, 0, -1 }, dc[4] = { 1, 0, -1, 0 }; // E, S, W, N

int main(void) {

	cin >> n >> k;
	while (k--) {
		int r, c;
		cin >> r >> c;
		apple[r][c] = true;
	}
	cin >> l;
	while (l--) {
		int a; char c;
		cin >> a >> c;
		order.push_back({ a, c });
	}

	snake.push_back({ 1, 1 });
	moved[1][1] = true;

	while (1) {

		time++;

		pair<int, int> prev = snake.back();
		pair<int, int> cur = { prev.first + dr[idx], prev.second + dc[idx] };

		if (cur.first < 1 || cur.second < 1 || cur.first > n || cur.second > n || moved[cur.first][cur.second]) {
			cout << time << "\n";
			break;
		}

		snake.push_back(cur);
		moved[cur.first][cur.second] = true;

		if (apple[cur.first][cur.second]) {
			apple[cur.first][cur.second] = false;
		}
		else {
			pair<int, int> tail = snake.front();
			moved[tail.first][tail.second] = false;
			snake.pop_front();
		}

		if (!order.empty() && order.front().first == time) {
			if (order.front().second == 'D')
				idx = (idx + 1) % 4;
			else
				idx = (idx + 3) % 4;
			order.pop_front();
		}
	}

	return 0;
}
