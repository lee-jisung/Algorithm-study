#include <iostream>

using namespace std;

/*
   첫줄을 N만큼 미리 채우고
    그 다음에는 N - 1 ~ 1 까지 2번씩 반복하면서 수를 채워나감
*/

int N, r, c, val, target;
int R, C;
int board[1001][1001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> target;
	val = N * N;
	
	// 첫줄 채우기 
	for (int i = 1; i <= N; i++) {
		// 첫줄에 타겟이 있을 경우
		if (target == val) R = i, C = 1;
		board[i][1] = val--;
	}

	// r, c 좌표 => 값을 채워나가기 위한 좌표 설정
	r = N; c = 2;
	
	for (int k = N-1; k >= 1; k--) {
		// 짝수일 때 우, 상 방향으로 채우기
		if (k % 2 == 0) {

			// 우 방향
			for (int i = 0;i < k; i++) {
				if (target == val) R = r, C = c;
				board[r][c] = val--;
				c++;
			}
			r--; c--; // 범위 벗어난 좌표를 제자리로 돌려놓기

			// 상 방향
			for (int i = 0; i < k; i++) {
				if (target == val) R = r, C = c;
				board[r][c] = val--;
				r--;
			}
			c--; r++;
		}
		// 홀수 일 때 좌, 하 방향으로 채우기
		else {

			// 좌 방향
			for (int i = 0; i < k; i++) {
				if (target == val) R = r, C = c;
				board[r][c] = val--;
				c--;
			}
			r++; c++;

			// 하 방향
			for (int i = 0; i < k; i++) {
				if (target == val) R = r, C = c;
				board[r][c] = val--;
				r++;
			}
			r--; c++;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1;j <= N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << R << " " << C << "\n";


	return 0;
}
