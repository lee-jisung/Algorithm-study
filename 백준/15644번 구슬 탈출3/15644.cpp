#include <iostream>
#include <queue>

using namespace std;

struct node {
	int red_r;
	int red_c;
	int blue_r;
	int blue_c;
	int depth;
};

struct moved {
	int r1, c1;
	int r2, c2;
	int moving;
};

int n, m, result;
char board[11][11];
bool isVisit[11][11][11][11];
moved moving[11][11][11][11], res;
node t;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

void bfs() {

	queue<node> q;
	q.push(t);
	isVisit[t.red_r][t.red_c][t.blue_r][t.blue_c] = true;
	moving[t.red_r][t.red_c][t.blue_r][t.blue_c] = {-1, -1, -1, -1, 0};

	while (!q.empty()) {

		int rr = q.front().red_r, rc = q.front().red_c;
		int br = q.front().blue_r, bc = q.front().blue_c;
		int depth = q.front().depth;
		q.pop();

		if (depth > 10) break;
		
		if (board[rr][rc] == 'O') {
			result = depth;
			res = { rr, rc, br, bc, 0 };
			return;
		}

		for (int i = 0; i < 4; i++) {

			int nrr = rr, nrc = rc;
			int nbr = br, nbc = bc;

			while (1) {
				if (board[nrr + dr[i]][nrc + dc[i]] == '#' || board[nrr][nrc] == 'O') break;
				nrr += dr[i];
				nrc += dc[i];
			}

			while (1) {
				if (board[nbr + dr[i]][nbc + dc[i]] == '#' || board[nbr][nbc] == 'O') break;
				nbr += dr[i];
				nbc += dc[i];
			}

			if (board[nbr][nbc] == 'O') continue;
			
			if (nrr == nbr && nrc == nbc) {
				switch (i) {
				case 0: //상
					rr > br ? nrr++ : nbr++;
					break;
				case 1: //하
					rr > br ? nbr-- : nrr--;
					break;
				case 2: //좌
					rc > bc ? nrc++ : nbc++;
					break;
				case 3: //우
					rc > bc ? nbc-- : nrc--;
					break;
				}
			}

			if (!isVisit[nrr][nrc][nbr][nbc]) {
				q.push({ nrr,nrc,nbr,nbc, depth + 1 });
				isVisit[nrr][nrc][nbr][nbc] = true;
				moving[nrr][nrc][nbr][nbc] = { rr, rc, br, bc, i };
			}

		}
	}
}

// 이전 좌표값 이용해서 추적 & 이동한 방향 대로 대문자 출력
void print(int r1, int c1, int r2, int c2) {
	if (moving[r1][c1][r2][c2].r1 == -1)
		return;
	
	auto pos = moving[r1][c1][r2][c2];
	print(pos.r1, pos.c1, pos.r2, pos.c2);

	switch (pos.moving) {
	case 0: cout << 'U'; break;
	case 1: cout << 'D'; break;
	case 2: cout << 'L'; break;
	case 3: cout << 'R'; break;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		string temp; cin >> temp;
		for (int j = 0;j < m; j++) {
			board[i][j] = temp[j];
			if (board[i][j] == 'R')
				t.red_r = i, t.red_c = j;
			if (board[i][j] == 'B')
				t.blue_r =i, t.blue_c = j;
		}
	}

	result = -1;

	bfs();

	if (result != -1) {
		cout << result << "\n";
		print(res.r1, res.c1, res.r2, res.c2);
	}
	else {
		cout << "-1\n";
	}

	return 0;
}
