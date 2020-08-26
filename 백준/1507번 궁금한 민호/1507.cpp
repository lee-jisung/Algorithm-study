#include <iostream>

using namespace std;

int n, sum;
bool ck;
int board[21][21], temp[21][21];

void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || i == k || j == k) continue;
				// i -> j로 바로 가는 경로의 값이 k를 거쳐가는 값보다 큰 경우가 존재한다면
				// 그것은 최단경로를 구한 경우가 아니므로 애초에 floyd를 만족하지 않음
				if (board[i][j] > board[i][k] + board[k][j]) {
					ck = false;
					return;
				}
				// i->k->j 경로가 i->j랑 같다면 i->j는 i->k->j를 통해 값이 나온것이므로
				// i->j를 지움
				else if (board[i][j] == board[i][k] + board[k][j])
					temp[i][j] = -1;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	ck = true;
	floyd();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (temp[i][j] != -1) sum += board[i][j];
		}
	}

	if (ck) cout << sum / 2 << "\n";
	else cout << -1 << "\n";

	return 0;
}
