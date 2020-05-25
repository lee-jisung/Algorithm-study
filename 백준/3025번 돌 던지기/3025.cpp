#include <iostream>

#define SIZE 30001

using namespace std;

int R, C, N, col;
char board[SIZE][31];
int fromto[SIZE][31];
int rowPos[31];


/*
   fromto의 각 값을 해당 행에 도착했을 때 다음 행은 무슨 열인지 저장
   즉, fromto[0][0] = 1 이라면 0열에 돌을 놓으면 (1,1)로 돌이 간다는 뜻
  
   그래서 돌을 놓을 때 돌이 놓일 위치로 바로 놓아주고
   놓인 후의 각 행마다 가야할 열의 위치를 다시 갱신
*/

// 모든 열의 행마다 바로 갈 지점을 정해줌
void update_pos(int no) {

	int r = rowPos[no];
	
	while (1) {

		int c = fromto[r-1][no];
		if (r > 1 && board[r-1][c] != '.') { r--; continue; };

		if (r == R) break;
		if (board[r][c] == 'X') break;
		if (board[r][c] == '.') {
			fromto[r++][no] = c;
		}
		else {// 'O'를 만났을 때 
			if (c > 0 && board[r][c - 1] == '.' && board[r - 1][c - 1] == '.') { // 왼쪽, 왼쪽칸 아래가 . 이면 왼쪽아래로 바로 가도록
				fromto[r++][no] = c - 1;
			}
			else if (c <= C && board[r][c + 1] == '.' && board[r - 1][c + 1] == '.') {// 오른쪽, 오른쪽 아래가 . 이면 오른쪽 아래로 바로 가도록 
				fromto[r++][no] = c + 1;
			}
			else // 둘다 아닐 경우 해당 자리에서 끝
				break;
		}
	}
	rowPos[no] = r; // 마지막 r 위치를 저장
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0;i < R; i++) {
		string temp; cin >> temp;
		for (int j = 1;j <= C; j++) {
			board[i][j] = temp[j - 1];
		}
	}

	for (int i = 1; i <= C; i++) {
		fromto[0][i] = i;
		rowPos[i] = 1;
		update_pos(i);
	}

	cin >> N;
	while (N--) {

		cin >> col;
		int r = rowPos[col]-1;
		int c = fromto[r][col];
		board[r][c] = 'O';
		for (int i = 1;i <= C; i++)
			update_pos(i);
	}

	for (int i = 0; i < R; i++) {
		for (int j = 1;j <= C; j++) {
			cout << board[i][j];
		}
		cout << "\n";
	}

	return 0;
}

