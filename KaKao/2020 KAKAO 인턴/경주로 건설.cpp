#include <string>
#include <vector>
#include <queue>
#include <iostream>

#define INF 1e9

using namespace std;

/*
   BFS + Dijkstra
   4방향에 대해서 경주로를 건설할 때 현재 진행방향과 같은경우는 100원
   방향이 다르면 코너이므로 직선+코너 => 600원 추가
   
   최종 도착한 곳에서 값이 더 싼 경우로 갱신
*/

struct track {
	int r, c;
	int dir;
};

vector<vector<int>> Board;
int n, result;
int dist[26][26][4];
int dr[4] = { -1, 0, 1, 0 }, dc[4] = { 0, 1, 0, -1 };

void bfs() {
	queue<track> q;
	for (int i = 0; i < 4; i++) {
		q.push({ 0, 0, i });
		dist[0][0][i] = 0;
	}
	int depth = 1;
	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int dir = q.front().dir;
		q.pop();

		if (r == n - 1 && c == n - 1) {
			if (result > dist[r][c][dir]) result = dist[r][c][dir];
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= n || Board[nr][nc] == 1) continue;
            // 직선일 경우 (직선) = 100
			if (dir == i && dist[nr][nc][i] > dist[r][c][dir] + 100) {
				q.push({ nr, nc, i });
				dist[nr][nc][i] = dist[r][c][dir] + 100;
			}
            // 코너일 경우 (직선 + 코너) = 600
			else if (dir != i && dist[nr][nc][i] > dist[r][c][dir] + 600) {
				q.push({ nr, nc, i });
				dist[nr][nc][i] = dist[r][c][dir] + 600;
			}
		}

	}
}

int solution(vector<vector<int>> board) {
	int answer = 0;

	Board = board;
	n = board.size();
	result = INF;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < 4; k++)
				dist[i][j][k] = INF;

	bfs();
	answer = result;

	return answer;
}
