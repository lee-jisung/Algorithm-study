#include <iostream>
#include <vector>

using namespace std;

/*
   speed %= n
*/

struct fireball {
	int r, c;
	int weight;
	int dir;
	int speed;
};

int n, m, k, result;
vector<fireball> board[51][51];
             
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dc[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
		board[r][c].push_back({ r, c, m, d, s });
	}

	while (k--) {

		// 이동을 위해 board에서 볼을 다 빼서 moves 벡터에 넣음
		vector<fireball> moves;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j].empty()) continue;
				int size = board[i][j].size();
				while (size--) {
					moves.push_back(board[i][j].back());
					board[i][j].pop_back();
				}
			}
		}

		// 방향, 속도를 이용해서 이동 => % 연산을 이용해서 시간 줄이기 (크기가 n이면 n으로 %연산하면 됨)
		// 범위를 넘어갈 경우 넘어간 길이 만큼 새로운 좌표 위치를 계산해주어야 함
		for (int i = 0; i < moves.size(); i++) {
			fireball fb = moves[i];
			int nr = fb.r + dr[fb.dir] * (fb.speed % n);
			int nc = fb.c + dc[fb.dir] * (fb.speed % n);
			if (nr < 1) nr = (n + nr); 
			if (nr > n) nr -= n;
			if (nc < 1) nc = (n + nc); 
			if (nc > n) nc -= n;
			fb.r = nr; fb.c = nc;
			board[nr][nc].push_back(fb);
		}

		moves.clear();

		// 2개 이상인 경우만 확인해서 
		// 동일하게 벡터에 넣고, 4개로 나눈 후 다시 board에 넣어주기 
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (board[i][j].size() < 2) continue;
				int size = board[i][j].size();
				int odd = 0, even = 0, weightSum = 0, speedSum = 0;

				for (int k = 0; k < size; k++) {
					fireball fb = board[i][j].back();
					board[i][j].pop_back();

					if (fb.dir % 2 == 0) even++;
					else odd++;
					weightSum += fb.weight;
					speedSum += fb.speed;
				}

				weightSum /= 5;
				speedSum /= size;
				if (weightSum == 0) continue;

				if (odd == 0 || even == 0) {
					for (int k = 0; k <= 6; k += 2) {
						moves.push_back({ i, j, weightSum, k, speedSum });
					}
				}
				else {
					for (int k = 1; k <= 7; k += 2) {
						moves.push_back({ i, j, weightSum, k, speedSum });
					}
				}
			}
		}

		for (int i = 0; i < moves.size(); i++) {
			board[moves[i].r][moves[i].c].push_back(moves[i]);
		}
		moves.clear();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < board[i][j].size(); k++) {
				result += board[i][j][k].weight;
			}
		}
	}  

	cout << result << "\n";

	return 0;
}
