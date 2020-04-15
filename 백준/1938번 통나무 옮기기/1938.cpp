#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 101
#define INF 987654321

/*
   queue -> 나무 중심점, 방향(가로,세로), 움직인 횟수 저장
   나무 중심점을 가지고 U, D, L, R, T 의 움직임을 할 수 있는지 확인 (범위를 벗어나거나 1이 아니면 됨)
   방문처리를 3차원으로 해서 가로일때, 세로일때 방문한 여부를 체크해줌

   check 함수 -> 중심점과 방향 정보를 바탕으로 통나무 3개의 좌표를 만들어 return 해 줌
*/

using namespace std;

struct POS {
	int r;
	int c;
};

struct node {
	POS pos; // mid coordinate
	int dir; // 0 = width, 1 = height
	int depth;
};

int n, result, status;
int board[SIZE][SIZE];
bool isVisit[SIZE][SIZE][2]; // 가로, 세로 상태 

vector<POS> B, E;

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < n;
}

vector<POS> check(POS pos, int dir) {
	vector<POS> temp;
	if (dir) 
		for (int i = -1; i < 2; i++)
			temp.push_back({ pos.r + i, pos.c });
	else 
		for (int i = -1; i < 2; i++)
			temp.push_back({ pos.r , pos.c + i});
	return temp;
}

bool isArrive() {
	for (int i = 0; i < 3; i++)
		if (B[i].r != E[i].r || B[i].c != E[i].c)
			return false;
	return true;
}

bool up(int dir) {
	for (int i = 0; i < 3; i++) 
		if (B[i].r - 1 < 0 || board[B[i].r - 1][B[i].c] == 1) return false;
	return true;
}

bool down(int dir) {
	for (int i = 0; i < 3; i++)
		if (B[i].r +1 >= n || board[B[i].r + 1][B[i].c] == 1) return false;
	return true;
}

bool left(int dir) {
	for (int i = 0; i < 3; i++)
		if (B[i].c - 1 < 0 || board[B[i].r][B[i].c - 1] == 1) return false;
	return true;
}

bool right(int dir) {
	for (int i = 0; i < 3; i++)
		if (B[i].c + 1 >= n || board[B[i].r][B[i].c + 1] == 1) return false;
	return true;
}

bool turn(int dir) {
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (board[B[1].r + i][B[1].c + j] == 1 || !isRange(B[1].r + i, B[1].c + j)) return false;
	return true;
}

void bfs() {
	queue<node> q;
	q.push({ {B[1].r, B[1].c}, status, 0 });
	isVisit[B[1].r][B[1].c][status] = true;

	while (!q.empty()) {

		POS pos = q.front().pos;
		int dir = q.front().dir;
		int depth = q.front().depth;
		q.pop();
			
		B = check(pos, dir);

		if (isArrive()) {
			result = depth;
			return;
		}

		if (up(dir) && !isVisit[pos.r - 1][pos.c][dir]) {
			isVisit[pos.r - 1][pos.c][dir] = true;
			q.push({ {pos.r - 1, pos.c}, dir, depth + 1 });
		}
		if (down(dir) && !isVisit[pos.r + 1][pos.c][dir]) {
			isVisit[pos.r + 1][pos.c][dir] = true;
			q.push({ {pos.r + 1, pos.c}, dir, depth + 1 });
		}
		if (left(dir) && !isVisit[pos.r][pos.c - 1][dir]) {
			isVisit[pos.r][pos.c - 1][dir] = true;
			q.push({ {pos.r, pos.c - 1}, dir, depth + 1 });
		}
		if (right(dir) && !isVisit[pos.r][pos.c + 1][dir]) {
			isVisit[pos.r][pos.c + 1][dir] = true;
			q.push({ {pos.r, pos.c + 1}, dir, depth + 1 });
		}
		if (turn(dir)) {
			if (dir && !isVisit[pos.r][pos.c][dir - 1]) {
				isVisit[pos.r][pos.c][dir - 1] = true;
				q.push({ {pos.r, pos.c}, dir - 1 , depth + 1 });
			}
			else if (!dir && !isVisit[pos.r][pos.c][dir + 1]) {
				isVisit[pos.r][pos.c][dir + 1] = true;
				q.push({ {pos.r, pos.c}, dir + 1 , depth + 1 });
			}
		}

	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n;i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'B') B.push_back({ i, j }), board[i][j] = 0;
			else if (str[j] == 'E') E.push_back({ i, j }), board[i][j] = 0;
			else board[i][j] = str[j] - '0';
		}
	}

	if (B[0].r != B[1].r) status = 1;
	else status = 0;
	
	bfs();

	cout << result << "\n";

	return 0;
}
