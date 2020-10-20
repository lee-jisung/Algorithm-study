#include <iostream>
#include <queue>

using namespace std;

/*
   좌표상에 직사각형을 1로 모두 표시한다음, 1인 한 지점에서 BFS로 다른 모든 1을 방문처리 => 한붓그리기 가능한지
   => 한붓그리기가 가능한 직사각형이 몇개인지 확인하면 됨
   => 단, 몇번 연필을 띄워야하는지를 확인해야할 때 
   만약 0, 0부터 직사각형이 그려지면 result에서 -1을 해줘야함 
   => 0,0 에서부터 bfs를하고 result++를 하기때문에 처음에 연필을 띄운상태로 시작하는 것이지만 조건은 연필을 내린상태이기때문에
   -1을 해준것
*/

int n, result;
int board[2001][2001];
bool isVisit[2001][2001];

int dr[4] = { -1, 0, 1 ,0 }, dc[4] = { 0, -1, 0, 1 };

void bfs(int y, int x) {
	queue<pair<int, int >> q;
	q.push({ y, x });
	isVisit[y][x] = true;
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr>2000 || nc>2000) continue;
			if (isVisit[nr][nc] || board[nr][nc] == 0) continue;
			isVisit[nr][nc] = true;
			q.push({ nr, nc });
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;
		
		for (int x = x1; x <= x2; x++)
			board[y1][x] = board[y2][x] = 1;
		for (int y = y1; y <= y2; y++)
			board[y][x1] = board[y][x2] = 1;
	}

	//for (int i = 1000; i < 1050; i++) {
	//	for (int j = 1000; j < 1050; j++) {
	//		cout << board[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	for (int i = 0; i < 2001;i++) {
		for (int j = 0; j < 2001; j++) {

			if (!isVisit[i][j] && board[i][j] == 1) { 
				bfs(i, j);
				result++;
			}
		}
	}
	if (board[1000][1000] == 1) result--;
	cout << result << "\n";

	return 0;
}
