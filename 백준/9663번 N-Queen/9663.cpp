#include <iostream>

/*
   bool check를 3개만듦
   check1 -> 열 마다 퀸을 한개씩 놓는 것이 가능
   check2 -> 좌상우하 대각선을 체크 (x + y)가 전부 같은 값인 대각선임
   check3 -> 우상좌하 대각선 체크 (x - y)가 0인 대각선 
     (0, 3)일 경우 음수로 가기 때문에 (n-1)을 더해줌
*/

using namespace std;

int n, cnt;
bool check1[15], check2[40], check3[40];

void nQueen(int cur) {
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) { // i = row
		if (check1[i] || check2[i + cur] || check3[cur - i + n - 1]) continue;
		check1[i] = true;
		check2[i + cur] = true;
		check3[cur - i+ n - 1] = true;
		nQueen(cur + 1);
		check1[i] = false;
		check2[i + cur] = false;
		check3[cur - i + n - 1] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	nQueen(0);

	cout << cnt << "\n";

	return 0;
}
