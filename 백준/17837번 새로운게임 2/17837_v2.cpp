#include <iostream>
#include <deque>

#define SIZE 13

using namespace std;

struct horse {
	int r, c;
	int no;
	int dir;
};

int n, k, t;
int board[SIZE][SIZE];
bool ck;
deque<horse> chess[SIZE][SIZE];
horse hp[11];

int dr[4] = { 0, 0, -1, 1 }, dc[4] = { 1, -1, 0, 0 };

int reverse(int d) {
	if (d == 0) return 1;
	else if (d == 1) return 0;
	else if (d == 2) return 3;
	else if (d == 3) return 2;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1;j <= n; j++)
			cin >> board[i][j];

	for (int i = 1; i <= k; i++) {
		int r, c, d;
		cin >> r >> c >> d;
		hp[i] = { r, c, i, d - 1 };
		chess[r][c].push_back(hp[i]);
	}

	while (1) {
		t++;
		if (t > 1000) break;

		for (int i = 1; i <= k; i++) {

			int r = hp[i].r;
			int c = hp[i].c;
			int dir = hp[i].dir;

			int nr = r + dr[dir], nc = c + dc[dir];

			deque<horse> tmp;
			while (!chess[r][c].empty()) {
				if (chess[r][c].back().no == i) {
					tmp.push_front(chess[r][c].back());
					chess[r][c].pop_back();
					break;
				}
				tmp.push_front(chess[r][c].back());
				chess[r][c].pop_back();
			}

			if (nr < 1 || nc <1 || nr > n || nc > n || board[nr][nc] == 2) {
				hp[i].dir = dir = reverse(dir);
				
				nr = r + dr[dir], nc = c + dc[dir];

				if (nr < 1 || nc < 1 || nr> n || nc > n || board[nr][nc] == 2) {
					while (!tmp.empty()) {
						chess[r][c].push_back(tmp.front());
						tmp.pop_front();
					}
				}
				else if (board[nr][nc] == 0) {
					while (!tmp.empty()) {
						horse h = tmp.front();
						tmp.pop_front();
						hp[h.no].r = nr;
						hp[h.no].c = nc;
						chess[nr][nc].push_back(hp[h.no]);
					}

				}
				else if (board[nr][nc] == 1) {
					while (!tmp.empty()) {
						horse h = tmp.back();
						tmp.pop_back();
						hp[h.no].r = nr;
						hp[h.no].c = nc;
						chess[nr][nc].push_back(hp[h.no]);
					}
				}

			}
			else if (board[nr][nc] == 0) {
				while (!tmp.empty()) {
					horse h = tmp.front();
					tmp.pop_front();
					hp[h.no].r = nr;
					hp[h.no].c = nc;
					chess[nr][nc].push_back(hp[h.no]);
				}

			}
			else if (board[nr][nc] == 1) {
				while (!tmp.empty()) {
					horse h = tmp.back();
					tmp.pop_back();
					hp[h.no].r = nr;
					hp[h.no].c = nc;
					chess[nr][nc].push_back(hp[h.no]);
				}
			}

			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					if (chess[i][j].size() >= 4) {
						ck = true;
						break;
					}
		}
		if (ck) break;
	}

	if (t > 1000) cout << "-1\n";
	else cout << t << "\n";


	return 0;
}
