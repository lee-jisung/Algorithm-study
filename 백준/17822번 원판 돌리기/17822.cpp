#include <iostream>

#define SIZE 51

/*
   처음 상태에서 각 n번째 원판을 회전 시킨 후

   연산
	 연산 -> 양 옆 or 위 아래 를 보고 같은 숫자가 있으면 0으로 바꿈
		  -> 지우는 연산을 끝난 후엔 각 원판마다 평균을 구해서 평균보다 큰수는 -1, 작은 수는 +1을 해줌

   이걸 반복 한 후

   최종 원판의 수의 합 출력 

   단, 값이 0이 된 것은 +, - 연산처리 안함

   temp를 사용해서 원본값 복사 및 원본에서 회전 후 인접값 비교해서 temp에 0을 표시
   그 후에 temp를 다시 원본에 넣기
*/

using namespace std;

int n, m, t, result;
int x, d, k;
int board[SIZE][SIZE], temp[SIZE][SIZE];

void copy() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			temp[i][j] = board[i][j];
		}
	}
}

void copy_origin() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			board[i][j] = temp[i][j];
		}
	}
}

// d방향으로 k칸 회전
// 시계방향 -> 1칸씩 뒤로 땡긴 후, 맨 뒤의 값을 맨 앞으로 (k번 반복)
// 반시계   -> 1칸씩 앞으로 떙긴후, 맨 앞의 값을 맨 뒤로 (k번 반복)
void rotation() {
	for (int i = 1; i <= n; i++) {
		if (i % x != 0) continue;
		if (d == 0) {
			for (int j = 0; j < k; j++) {
				int tmp = board[i][m];
				for (int w = m; w > 1; w--) {
					board[i][w] = board[i][w - 1];
				}
				board[i][1] = tmp;
			}
		}
		else {
			for (int j = 0; j < k; j++) {
				int tmp = board[i][1];
				for (int w = 1; w < m; w++)
					board[i][w] = board[i][w + 1];
				board[i][m] = tmp;
			}
		}
	}
}

// i행이 맨 윗줄, 맨 아랫줄일 때 3방향
// 그 외에는 4방향으로 보고 처리
// idx1, idx2를 만들어서 j-1, j+1이 범위를 벗어났을 때 각각 처리
bool find_same() {
	bool ck = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			if (temp[i][j] == 0) continue;

			if (i == 1) {
				int idx1 = j - 1, idx2 = j + 1;
				if (idx1 < 1) idx1 = m;
				if (idx2 > m) idx2 = 1;
				if (board[i][j] == board[i][idx1]) {
					temp[i][j] = temp[i][idx1] = 0;
					ck = true;
				}
				else if (board[i][j] == board[i][idx2]) {
					temp[i][j] = temp[i][idx2] = 0;
					ck = true;
				}
				else if (board[i][j] == board[i + 1][j]) {
					temp[i][j] = temp[i + 1][j] = 0;
					ck = true;
				}
			}
			else if (i == n) {
				int idx1 = j - 1, idx2 = j + 1;
				if (idx1 < 1) idx1 = m;
				if (idx2 > m) idx2 = 1;
				if (board[i][j] == board[i][idx1]) {
					temp[i][j] = temp[i][idx1] = 0;
					ck = true;
				}
				else if (board[i][j] == board[i][idx2]) {
					temp[i][j] = temp[i][idx2] = 0;
					ck = true;
				}
				else if (board[i][j] == board[i - 1][j]) {
					temp[i][j] = temp[i - 1][j] = 0;
					ck = true;
				}
			}
			else {
				int idx1 = j - 1, idx2 = j + 1;
				if (idx1 < 1) idx1 = m;
				if (idx2 > m) idx2 = 1;
				if (board[i][j] == board[i][idx1]) {
					temp[i][j] = temp[i][idx1] = 0;
					ck = true;
				}
				else if (board[i][j] == board[i][idx2]) {
					temp[i][j] = temp[i][idx2] = 0;
					ck = true;
				}
				else if (board[i][j] == board[i + 1][j]) {
					temp[i][j] = temp[i + 1][j] = 0;
					ck = true;
				}
				else if (board[i][j] == board[i - 1][j]) {
					temp[i][j] = temp[i - 1][j] = 0;
					ck = true;
				}
			}
		}
	}
	return ck;
}

void calculate() {
	int sum = 0, cnt = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			if (temp[i][j] != 0) {
				sum += temp[i][j];
				cnt++;
			}
		}
	}

	double avg = (double)sum / cnt; // (double)(sum/cnt)로 하면 정수형이 반환되서 안됨 // 틀린이유
	for (int i = 1; i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			if (temp[i][j] > avg) {
				temp[i][j]--;
			}
			else if (temp[i][j] < avg && temp[i][j] > 0) {
				temp[i][j]++;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <=m; j++)
			cin >> board[i][j];

	for (int i = 0; i < t; i++) {
		cin >> x >> d >> k;
		rotation();
		copy();
		if (!find_same()) calculate();
		copy_origin();

	}

	for (int i = 1; i <=n; i++)
		for (int j = 1;j <=m; j++)
			if (board[i][j] != 0) result += board[i][j];

	cout << result << "\n";

	return 0;
}
