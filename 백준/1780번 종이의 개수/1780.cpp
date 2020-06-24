#include <iostream>

// 1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
// 2. (1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서(1)의 과정을 반복한다.

using namespace std;

int n, paper[2188][2188];
int cnt[3];

bool samePaper(int r, int c, int len) {
	for (int i = r; i < r + len; i++)
		for (int j = c; j < c + len; j++)
			if (paper[r][c] != paper[i][j]) return false;
	return true;
}

void findPaper(int r, int c, int len) {
	if (samePaper(r, c, len)) {
		cnt[paper[r][c] + 1]++;
		return;
	}

	int divlen = len / 3;

	for (int i = 0;i < 3;i++) {
		for (int j = 0; j < 3; j++) {
			findPaper(r + i * divlen, c + j * divlen, divlen);
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0;j < n;j++)
			cin >> paper[i][j];

	findPaper(0, 0, n);

	for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";

	return 0;
}
