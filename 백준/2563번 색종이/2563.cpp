#include <iostream>

using namespace std;

/*
   도화지 => 2차원 배열 
   색종이가 붙는 위치 (y, x) ~ (y + 10, x + 10)을 1로 주고
   2차원 배열에서 1의 개수 카운트하여 출력
*/

int n, area;
int paper[101][101];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	while (n--) {
		int x, y; cin >> x >> y;
		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {
				paper[i][j] = 1;
			}
		}
	}

	for (int i = 1; i < 101; i++)
		for (int j = 1; j < 101; j++)
			if (paper[i][j]) area++;

	cout << area << "\n";

	return 0;
}
