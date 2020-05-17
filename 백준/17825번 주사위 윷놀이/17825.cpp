#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100
#define INF 987654321

using namespace std;

int result;
int horse[4];
int board[33], moving[33], turn[33], dice[10];
bool isVisit[33];

void initialize() {
	// 각 칸마다 얻는 점수
	for (int i = 1; i <= 20; i++) board[i] = i * 2;
	board[22] = 13; board[23] = 16; board[24] = 19; board[25] = 25;
	board[26] = 30; board[27] = 35; board[28] = 28; board[29] = 27;
	board[30] = 26; board[31] = 22; board[32] = 24;

	//각 칸에서 다음 칸으로 가는 index 지정
	for (int i = 0; i < 21; i++) moving[i] = i + 1; moving[21] = 21;
	for (int i = 22; i < 27; i++) moving[i] = i + 1;
	moving[28] = 29; moving[29] = 30; moving[30] = 25;
	moving[31] = 32; moving[32] = 25;moving[27] = 20;
	
	// 회전할 곳 지정
	turn[5] = 22; turn[10] = 31; turn[15] = 28; turn[25] = 26;
	
}

void dfs(int cnt, int sum) {
	if (cnt == 10) { //10번 주사위를 다 돌렷을 때
		result = max(result, sum); return;
	}

	for (int i = 0; i < 4; i++) {
		int prev = horse[i];
		int cur = prev;
		int move = dice[cnt];

		// 5, 10, 15, 25의 경우 파란색 선을 따라 이동해야 하는 칸으로 이동
		if (turn[cur] > 0) {
			cur = turn[cur];
			move--;
		}
		
		// 남은 move 수만큼 이동
		while (move--) {
			cur = moving[cur];
		}

		// i번째 말이 21로 끝난지점이 아닌 다른 말이 있는 위치로 가게 된 경우 i+1번째 말을 움직임
		if (cur != 21 && isVisit[cur]) continue;
		
		// 이전에서 현재 위치로 움직임을 표시
		isVisit[prev] = false; 
		isVisit[cur] = true;
		horse[i] = cur;
		
		// 주사위 1칸 움직인 후 다시 dfs 탐색
		dfs(cnt + 1, sum + board[cur]);

		// 4개의 말의 모든 움직이는 경우의 수 탐색해야 하므로 다시 원래대로 복귀
		horse[i] = prev;
		isVisit[cur] = false;
		isVisit[prev] = true;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
		cin >> dice[i];

	initialize();	

	dfs(0, 0);

	cout << result << "\n";
	return 0;
}
