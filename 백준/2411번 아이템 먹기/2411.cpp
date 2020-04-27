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

using namespace std;

/*
   왼쪽 하단 = (1,1), 오른쪽 상단 = (N,M) ==> 왼쪽 상단을 (1,1), 오른쪽 하단(N,M)으로 바꾸어 생각

   시작, 아이템, 도착 좌표들을 벡터에 넣고 각 좌표에서 다음 좌표로 이동하는 경우의 수를 곱해나가줌
   
   dp[n][m] = dp[n-1][m] + dp[n][m-1]
*/

int n, m, a, b, result; 
int board[SIZE][SIZE], dp[SIZE][SIZE];
vector<pair<int, int>> pos;

int getPath(pair<int, int> pos1, pair<int, int> pos2) {
	memset(dp, 0, sizeof(dp));
	int x1 = pos1.first, y1 = pos1.second;
	int x2 = pos2.first, y2 = pos2.second;

	for (int i = x1; i <= x2; i++) {
		if (board[i][y1] == -1) break;
		dp[i][y1] = 1;
	}
	for (int i = y1; i <= y2; i++) {
		if (board[x1][i] == -1) break;
		dp[x1][i] = 1;
	}
	for (int i = x1 + 1; i <= x2; i++) {
		for (int j = y1 + 1; j <= y2; j++) {
			if (board[i][j] != -1) // 장애물이 없는 경로에 대해서
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[x2][y2];
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> a >> b;
	pos.push_back({ 1, 1});
	pos.push_back({ n, m });
	for (int i = 0; i < a; i++) {
		int r, c; 
		cin >> r >> c;
		pos.push_back({ r, c });
	}
	for (int i = 0; i < b; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = -1;
	}

	sort(pos.begin(), pos.end());

	result = 1;

	for (int i = 0; i < pos.size() - 1; i++) {
		int temp = getPath(pos[i], pos[i + 1]);
		result *= temp;
	}
	
	cout << result << "\n";

	return 0;
}
