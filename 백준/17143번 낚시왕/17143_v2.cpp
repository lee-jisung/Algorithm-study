#include <iostream>
#include <vector>

#define SIZE 101

using namespace std;

struct shark {
	int r, c;
	int s, d, z;
	bool moved;
};

int R, C, M, result;
vector<shark> board[SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, 1, -1 };

void init_move() {
	for (int i = 1; i <= R; i++)
		for (int j = 1;j <= C; j++)
			if (!board[i][j].empty())
				board[i][j].back().moved = false;
}

int reverse(int d) {
	if (d == 1) return 2;
	else if (d == 2) return 1;
	else if (d == 3) return 4;
	else if (d == 4) return 3;
}

void shark_move() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			vector<shark> v;
			int len = board[i][j].size();
			while (len--) {
				shark tmp = board[i][j].back();
				board[i][j].pop_back();
				if (tmp.moved) {
					v.push_back(tmp);
					continue;
				}
				
			    // 시간 초과 이유 -> s를 그대로 모두 다 --해서 돌렷기 때문
				// 위아래일 경우 (R-1) *2보다 s가 크면 %연산
				// 좌우일경우 동일
				// 이전의 구현했던것 처럼 up, down, left, right을 따로해서 끝으로 보낸 후 다시 방향바꿔서 거리만큼 더해준값을/
				// 그대로 반환시키는 방법이 훨씬 빨랐음
				int rot;
				if (tmp.d == 1 || tmp.d == 2) rot = (R - 1) * 2;
				else rot = (C - 1) * 2;
				int r = i, c = j, s = tmp.s;
				if (s >= rot) s %= rot;
				
				while (s) {
					if (r + dr[tmp.d - 1] < 1 || c + dc[tmp.d - 1] < 1 || r + dr[tmp.d - 1] > R || c + dc[tmp.d - 1] > C) {
						tmp.d = reverse(tmp.d);
						continue;
					}
					r += dr[tmp.d - 1], c += dc[tmp.d - 1];
					s--;
				}
				tmp.r = r, tmp.c = c;
				tmp.moved = true;
				v.push_back(tmp);
			}
			for (int i = 0; i < v.size(); i++) {
				board[v[i].r][v[i].c].push_back(v[i]);
			}
		}
	}


}

void shark_eat() {
	for (int i = 1;i <= R; i++) {
		for (int j = 1;j <= C; j++) {

			if (board[i][j].size() > 1) {
				shark s = board[i][j].back();
				board[i][j].pop_back();

				while (!board[i][j].empty()) {
					shark tmp = board[i][j].back();
					board[i][j].pop_back();
					if (s.z < tmp.z) s = tmp;
				}
				board[i][j].push_back(s);
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> M;

	while (M--) {

		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark temp = { r, c , s, d, z, false };
		board[r][c].push_back(temp);
	}


	for (int i = 1; i <= C; i++) {

		int idx = 1;
		while (1) {
			if (idx > R) break;
			if (!board[idx][i].empty()) {
				shark s = board[idx][i].back();
				board[idx][i].pop_back();
				result += s.z;
				break;
			}
			idx++;
		}
		init_move();
		shark_move();
		shark_eat();
	}

	cout << result << "\n";
	return 0;
}
