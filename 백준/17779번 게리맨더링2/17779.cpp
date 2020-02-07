#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int n, d1, d2, sum, min_pop, res = INF;
int map[21][21], population[21][21], result[5];
int dx[4] = { -1, 1, 0, 0 }, dy[4] = { 0, 0, -1, 1 };

bool isRange(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

void clean() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = 0;
	memset(result, 0, sizeof(result));
}

void draw_border(int x, int y, int d1, int d2) {
	for (int i = 0; i <= d1; i++) {
		if (isRange(x + i, y - i))
			map[x + i][y - i] = 5;

		if (isRange(x + d2 + i, y + d2 - i))
			map[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		if (isRange(x + i, y + i))
			map[x + i][y + i] = 5;

		if (isRange(x + d1 + i, y - d1 + i))
			map[x + d1 + i][y - d1 + i] = 5;
	}
}

void divide_section(int x, int y, int d1, int d2) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (map[i][j] == 5)
				continue;
			if (i < (x + d1) && 1<= j && j <= y)
				map[i][j] = 1;
			else if (i <= (x + d2) && j > y && j <= n)
				map[i][j] = 2;
			else if ((x + d1) <= i && i <= n  && j < (y - d1 + d2))
				map[i][j] = 3;
			else if ((x + d2) < i && i <= n && (y - d1 + d2) <= j && j <= n)
				map[i][j] = 4;
			
		}
	}
}

void sum_pop() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			result[map[i][j] - 1] += population[i][j];
		}
	}
}

int main(void) {

	cin >> n;
	for (int r = 1; r <= n; r++)
		for (int c = 1; c <= n; c++)
			cin >> population[r][c];

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {

			int x = r, y = c;
			sum = n - x; // sum = d1 + d2
			for (int i = 1; i < sum; i++) {
				bool ck = true;
				d1 = i;
				for (int j = 1; j <= sum - d1; j++) {
					clean();
					d2 = j;
					if (y - d1 >= y || y + d2 <= y)
						continue;

					// 경계선 그리면서 경계선 그리는 방법으로 
					// 속을 채워 나감
					int bx, bd1, bd2;
					bx = x; bd1 = d1; bd2 = d2;
					do {
						draw_border(bx, y, bd1, bd2);
						bx++;
					} while (bd1-- && bd2--);

					// 1234 구역 나누기
					divide_section(x, y, d1, d2);
					// 인구 계산
					sum_pop();

					// 인구 더한 구역 값이 0인 구역이 있다면 
					// 선거구는 적어도 하나의 구역 포함 조건 해당 x 
					for (int k = 0; k < 5; k++)
						if (result[k] == 0)
							ck = false;

					if (ck) {
						sort(result, result + 5);
						min_pop = result[4] - result[0];
						res = min(res, min_pop);
					}
				}
			}
		}
	}
	cout << res << "\n";
	return 0;
}
