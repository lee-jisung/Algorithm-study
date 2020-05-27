#include <iostream>
#include <queue>

#define SIZE 11

using namespace std;

struct node {
	int red_r;
	int red_c;
	int blue_r;
	int blue_c;
	int depth;
};

int n, m;
char board[SIZE][SIZE];
bool isVisit[SIZE][SIZE][SIZE][SIZE];

node t;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

bool bfs() {

	queue<node> q;
	q.push(t);
	isVisit[t.red_r][t.red_c][t.blue_r][t.blue_c] = true;

	while (!q.empty()) {

		int rr = q.front().red_r;
		int rc = q.front().red_c;
		int br = q.front().blue_r;
		int bc = q.front().blue_c;
		int depth = q.front().depth;
		q.pop();

		if (depth > 10)
			return false;

		if (board[rr][rc] == 'O')
			return true;

		for (int i = 0; i < 4; i++) {

			int nrr = rr, nrc = rc;
			int nbr = br, nbc = bc;

			while (1) {
				if (board[nrr + dr[i]][nrc + dc[i]] == '#' ||  board[nrr][nrc] == 'O') break;
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
				case 0: // 상
					rr > br ? nrr++ : nbr++;
					break;
				case 1: //하
					rr > br ? nbr-- : nrr--;
					break;
				case 2://좌
					rc > bc ? nrc++ : nbc++;
					break;
				case 3://우
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
	return false;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		for (int j = 0;j < m; j++) {
			board[i][j] = temp[j];
			if (board[i][j] == 'R') 
				t.red_r = i, t.red_c = j;
			if (board[i][j] == 'B')
				t.blue_r = i, t.blue_c = j;
		}
	}

	cout << bfs() << "\n";


	return 0;
}
