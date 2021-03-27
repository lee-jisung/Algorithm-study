#include <iostream>
#include <queue>

#define INF 1e9

using namespace std;

struct node {
	int r, c;
	int rupi;
};

bool operator<(node a, node b) {
	return a.rupi > b.rupi;
}

int TC, N, result;
int board[126][126], dist[126][126];

int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, -1, 0, 1 };

void input() {
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			dist[i][j] = INF;
		}
}

void dijkstra() {
	
	priority_queue<node> pq;
	pq.push({ 0, 0, board[0][0] });
	dist[0][0] = board[0][0];

	while (!pq.empty()) {

		node cur = pq.top();
		pq.pop();

		for (int i = 0; i < 4; i++) {

			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];
			int nextRupi = cur.rupi + board[nr][nc];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			
			if (dist[nr][nc] > nextRupi) {
				dist[nr][nc] = nextRupi;
				pq.push({ nr, nc, nextRupi });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while(1) {

		cin >> N;
		if (N == 0) break;

		input();
		dijkstra();

		cout << "Problem " << ++TC << ": " << dist[N-1][N-1] << "\n";
	}


	return 0;
}
