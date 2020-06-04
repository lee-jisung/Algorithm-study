#include <iostream>
#include <queue>

#define SIZE 11

using namespace std;

struct node {

	int rr, rc;
	int br, bc;
	int depth;
};

int n, m, result;
int r_r, r_c, b_r, b_c;
char board[SIZE][SIZE];
bool isVisit[SIZE][SIZE][SIZE][SIZE];

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1 ,1 };

void bfs() {

	queue<node> q;
	q.push({ r_r, r_c, b_r, b_c, 0 });
	isVisit[r_r][r_c][b_r][b_c] = true;

	while (!q.empty()) {

		int rr = q.front().rr;
		int rc = q.front().rc;
		int br = q.front().br;
		int bc = q.front().bc;
		int depth = q.front().depth;
		q.pop();

		if (depth > 10) {
			result = -1;
			return;
		}

		if (board[rr][rc] == 'O') {
			result = depth;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nrr = rr, nrc = rc;
			int nbr = br, nbc = bc;
			while (1) {
				if (board[nrr + dr[i]][nrc + dc[i]] == '#' || board[nrr][nrc] == 'O') break;
				nrr += dr[i], nrc += dc[i];
			}

			while (1) {
				if (board[nbr + dr[i]][nbc + dc[i]] == '#' || board[nbr][nbc] == 'O') break;
				nbr += dr[i], nbc += dc[i];
			}

			if (board[nbr][nbc] == 'O') continue;

			if (nrr == nbr && nrc == nbc) {
				switch (i) {
				case 0:
					rr > br ? nrr++ : nbr++;
					break;
				case 1:
					rr > br ? nbr-- : nrr--;
					break;
				case 2:
					rc > bc ? nrc++ : nbc++;
					break;
				case 3:
					rc > bc ? nbc-- : nrc--;
					break;
				}
			}

			if (!isVisit[nrr][nrc][nbr][nbc]) {
				q.push({ nrr, nrc, nbr, nbc, depth + 1 });
				isVisit[nrr][nrc][nbr][nbc] = true;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < m; j++) {
			board[i][j] = tmp[j];
			if (board[i][j] == 'R') {
				r_r = i, r_c = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				b_r = i, b_c = j;
				board[i][j] = '.';
			}
		}
	}
	result = -1;
	bfs();
	cout << result << "\n";

	return 0;
}
