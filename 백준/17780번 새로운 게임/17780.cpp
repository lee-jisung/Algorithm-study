#include <iostream>
#include <deque>

#define SIZE 13

using namespace std;

struct object {
	int r;
	int c;
	int direction;
	int no;
};

int n, k, t;
int map[SIZE][SIZE];
deque<object> chess[SIZE][SIZE];
object ob[11];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

bool isRange(int r, int c) {
	return r > 0 && c > 0 && r <= n && c <= n;
}

// 체스판에 옮길 말들을 넣어 줄 move 만듦
// 맨 마지막 말이어야만 움직일 수 있으니까 뒤에서부터 처음까지 다 move에 넣어주면됨
// 단, 새로운게임2 의 경우 해당 번호의 말이면 다 움직일 수 있으니
// 해당 번호의 말인지까지만 확인해서 넣어주는 식으로 index 매개변수를 넣어서 break걸면 됨
deque<object> make_move(int r, int c) {
	deque<object> move;
	while (!chess[r][c].empty()) {
		object temp = chess[r][c].back();
		move.push_front(temp);
		chess[r][c].pop_back();
	}
	return move;
}

// 흰색일 때 --> chess판에 쌓인 그대로 옮김
// 즉 move에 앞에서부터 빼서 chess판에 뒤에 넣어주면 됨
void white(int r, int c, deque<object> move) {
	while (!move.empty()) {
		object o = move.front();
		ob[o.no].r = r;
		ob[o.no].c = c;
		chess[r][c].push_back(ob[o.no]);
		move.pop_front();
	}
}

// 빨강일 때 --> chess판에 쌓인 말의 순서를 반대로 넣어줌 (ABC -> CBA로)
// move 뒤에서부터 빼주면서 chess판에 넣어주면 됨
void red(int r, int c, deque<object> move) {
	while (!move.empty()) {
		object o = move.back();
		ob[o.no].r = r;
		ob[o.no].c = c;
		chess[r][c].push_back(ob[o.no]);
		move.pop_back();
	}
}

int main(void) {

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	for (int i = 1; i <= k; i++) {
		cin >> ob[i].r >> ob[i].c >> ob[i].direction;
		ob[i].no = i;
		chess[ob[i].r][ob[i].c].push_back(ob[i]);
	}

	while (1) {
		t++;
		if (t > 1000)
			break;
		for (int i = 1;i <= k; i++) {

			int r = ob[i].r;
			int c = ob[i].c;
			int dr = ob[i].direction;

			int nr = r + dx[dr - 1];
			int nc = c + dy[dr - 1];
			deque<object> move;

			// 맨 마지막 말이 아니면 진행 x
			if (ob[i].no != chess[r][c].front().no)
				continue;

			// 파란색이거나 범위 밖이면 방향 바꿔놓음
			if (map[nr][nc] == 2 || !isRange(nr, nc)) {
				if (ob[i].direction % 2 == 0) ob[i].direction--;
				else ob[i].direction++;
				dr = ob[i].direction;
				nr = r + dx[dr - 1];
				nc = c + dy[dr - 1];
			}

			// 범위의 안에서만 흰색, 빨간색 진행하면 됨
			// 범위 바깥 혹은 파란색일 경우는 위에서 이미 방향을 바꾸었기 때문에
			// 그대로 두면 됨
			if (isRange(nr, nc)) {
				if (map[nr][nc] == 0) {
					move = make_move(r, c);
					white(nr, nc, move);
				}
				else if (map[nr][nc] == 1) {
					move = make_move(r, c);
					red(nr, nc, move);
				}
			}

			for (int i = 1; i <= k; i++) {
				if (chess[ob[i].r][ob[i].c].size() >= 4) {
					cout << t << "\n";
					return 0;
				}
			}
		}
	}

	cout << -1 << "\n";

	return 0;
}
