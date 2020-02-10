#include <iostream>
#include <deque>

#define SIZE 13

using namespace std;

// 새로운 게임 1 과는 다른 방법 (처음 생각해낸 풀이)
// 매 턴마다 모든 r,c의 chess판 확인 안해서 계속 틀렸었음...

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


void white(int r, int c, deque<object> move) {
	while (!move.empty()) {
		object o = move.front();
		ob[o.no].r = r;
		ob[o.no].c = c;
		chess[r][c].push_back(ob[o.no]);
		move.pop_front();
	}
}


void red(int r, int c, deque<object> move) {
	while (!move.empty()) {
		object o = move.back();
		ob[o.no].r = r;
		ob[o.no].c = c;
		chess[r][c].push_back(ob[o.no]);
		move.pop_back();
	}
}


void blue(int r, int c, deque<object> move) {
	object a = move.front();
	if (a.direction % 2 == 0)
		ob[a.no].direction--;
	else 
		ob[a.no].direction++;

	int nr = r + dx[ob[a.no].direction - 1];
	int nc = c + dy[ob[a.no].direction - 1];
	
	if (isRange(nr, nc)) {
		if (map[nr][nc] == 0)
			white(nr, nc, move);
		else if (map[nr][nc] == 1)
			red(nr, nc, move);
		else {
			while (!move.empty()) {
				object o = move.front();
				chess[r][c].push_back(ob[o.no]);
				move.pop_front();
			}
		}
	}
	else {
		while (!move.empty()) {
			object o = move.front();
			chess[r][c].push_back(ob[o.no]);
			move.pop_front();
		}
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

			while (!chess[r][c].empty()) {
				object temp = chess[r][c].back();
				if (temp.no == i) {
					move.push_front(temp);
					chess[r][c].pop_back();
					break;
				}
				move.push_front(temp);
				chess[r][c].pop_back();
			}

			if (isRange(nr, nc)) {
				if (map[nr][nc] == 0) {
					white(nr, nc, move);
				}
				else if (map[nr][nc] == 1) {
					red(nr, nc, move);
				}
				else {
					blue(r, c, move);
				}
			}
			else {
				blue(r, c, move);
			}

			for (int i = 1; i <= k;i++) {
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
