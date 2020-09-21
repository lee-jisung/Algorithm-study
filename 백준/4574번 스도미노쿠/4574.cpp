#include <iostream>
#include <cstring>
#include <string>

/*

   row, col => 1 ~ 9 행, 1 ~ 9 열 마다 숫자 사용 표시
	square => 3 x 3 사각형 9개를 만들어 각 사각형 당 숫자 사용 표시  // 3 x 3 square의 a번째 숫자 사용 -> square[i][j][a] = true
	domino => 도미노 타일 사용 표시

	(0, 0) = 0, (0, 1) = 1 ... (8, 8) = 80 로 좌표를 숫자로 변환해서 dfs 수행
	idx가 81까지 갓다는건 => 모든 좌표를 숫자로 다 채웠다는 얘기

	idx에서 좌표 값 얻기 => r = idx / 9,   c = idx % 9

	전체 좌표인 (r, c)로 3x3의 사각형 좌표 찾기 => r / 3, c / 3
*/

using namespace std;

int n, board[9][9], cnt;
bool row[9][10], col[9][10];
bool domino[10][10];
bool square[3][3][10];
bool chk;

void init() {
	chk = false;
	memset(board, 0, sizeof(board));
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	memset(domino, false, sizeof(domino));
	memset(square, false, sizeof(square));
}

int getIdx(int idx) {
	return idx / 3;
}

void getBoard(int idx) {
	if (chk) return;

	if (idx == 81) {
		chk = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << board[i][j];
			cout << "\n";
		}
		return;
	}

	int r = idx / 9;
	int c = idx % 9;

	if (board[r][c]) getBoard(idx + 1);
	else {
		// 가로로 타일을 놓는 경우
		if (c < 8 && !board[r][c + 1]) {
			for (int i = 1; i <= 9; i++) {
				for (int j = i + 1; j <= 9; j++) {
					if (!domino[i][j]) {
						domino[i][j] = domino[j][i] = true;

						// i, j
						if (!row[r][i] && !col[c][i] && !square[getIdx(r)][getIdx(c)][i]) {
							if (!row[r][j] && !col[c + 1][j] && !square[getIdx(r)][getIdx(c + 1)][j]) {

								row[r][i] = row[r][j] = true;
								col[c][i] = col[c + 1][j] = true;
								square[getIdx(r)][getIdx(c)][i] = square[getIdx(r)][getIdx(c + 1)][j] = true;
								board[r][c] = i; board[r][c + 1] = j;

								getBoard(idx + 2); // idx, idx+1 까지 채웠기 때문 (가로)

								board[r][c] = 0; board[r][c + 1] = 0;
								row[r][i] = row[r][j] = false;
								col[c][i] = col[c + 1][j] = false;
								square[getIdx(r)][getIdx(c)][i] = square[getIdx(r)][getIdx(c + 1)][j] = false;
							}
						}

						// j, i
						if (!row[r][j] && !col[c][j] && !square[getIdx(r)][getIdx(c)][j]) {
							if (!row[r][i] && !col[c + 1][i] && !square[getIdx(r)][getIdx(c + 1)][i]) {

								row[r][j] = row[r][i] = true;
								col[c][j] = col[c + 1][i] = true;
								square[getIdx(r)][getIdx(c)][j] = square[getIdx(r)][getIdx(c + 1)][i] = true;
								board[r][c] = j; board[r][c + 1] = i;

								getBoard(idx + 2); // idx, idx+1 까지 채웠기 때문 (가로)

								board[r][c] = 0; board[r][c + 1] = 0;
								row[r][j] = row[r][i] = false;
								col[c][j] = col[c + 1][i] = false;
								square[getIdx(r)][getIdx(c)][j] = square[getIdx(r)][getIdx(c + 1)][i] = false;

							}
						}
						domino[i][j] = domino[j][i] = false;
					}
				}
			}
		}

		// 세로로 타일 놓는 경우
		if (r < 8 && !board[r + 1][c]) {
			for (int i = 1; i <= 9; i++) {
				for (int j = i + 1; j <= 9; j++) {
					if (!domino[i][j]) {
						domino[i][j] = domino[j][i] = true;

						// i, j
						if (!row[r][i] && !col[c][i] && !square[getIdx(r)][getIdx(c)][i]) {
							if (!row[r + 1][j] && !col[c][j] && !square[getIdx(r + 1)][getIdx(c)][j]) {

								row[r][i] = row[r + 1][j] = true;
								col[c][i] = col[c][j] = true;
								square[getIdx(r)][getIdx(c)][i] = square[getIdx(r + 1)][getIdx(c)][j] = true;
								board[r][c] = i; board[r + 1][c] = j;

								getBoard(idx + 1);

								board[r][c] = 0; board[r + 1][c] = 0;
								row[r][i] = row[r + 1][j] = false;
								col[c][i] = col[c][j] = false;
								square[getIdx(r)][getIdx(c)][i] = square[getIdx(r + 1)][getIdx(c)][j] = false;

							}
						}

						// j, i
						if (!row[r][j] && !col[c][j] && !square[getIdx(r)][getIdx(c)][j]) {
							if (!row[r + 1][i] && !col[c][i] && !square[getIdx(r + 1)][getIdx(c)][i]) {

								row[r][j] = row[r + 1][i] = true;
								col[c][j] = col[c][i] = true;
								square[getIdx(r)][getIdx(c)][j] = square[getIdx(r + 1)][getIdx(c)][i] = true;
								board[r][c] = j;board[r + 1][c] = i;

								getBoard(idx + 1);

								board[r][c] = 0; board[r + 1][c] = 0;
								row[r][j] = row[r + 1][i] = false;
								col[c][j] = col[c][i] = false;
								square[getIdx(r)][getIdx(c)][j] = square[getIdx(r + 1)][getIdx(c)][i] = false;
							}
						}
						domino[i][j] = domino[j][i] = false;
					}
				}
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {

		cin >> n;
		if (n == 0) break;
		init();

		for (int i = 0; i < n; i++) {
			int a, b; string s1, s2;
			cin >> a >> s1 >> b >> s2;
			int r1 = s1[0] - 'A';
			int c1 = s1[1] - '0' - 1;
			int r2 = s2[0] - 'A';
			int c2 = s2[1] - '0' - 1;

			board[r1][c1] = a; board[r2][c2] = b;

			domino[a][b] = domino[b][a] = true;
			row[r1][a] = row[r2][b] = true;
			col[c1][a] = col[c2][b] = true;
			square[getIdx(r1)][getIdx(c1)][a] = square[getIdx(r2)][getIdx(c2)][b] = true;
		}

		for (int i = 1; i <= 9; i++) {
			string s;cin >> s;
			int r = s[0] - 'A';
			int c = s[1] - '0' - 1;

			board[r][c] = i;
			row[r][i] = col[c][i] = true;
			square[getIdx(r)][getIdx(c)][i] = true;
		}

		cout << "Puzzle " << ++cnt << "\n";
		getBoard(0);
	}

	return 0;
}
