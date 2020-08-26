#include <iostream>

using namespace std;

int n, m;
int board[101][101];

// 대소비교 가능한 경우를 모두 찾음
void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][k] && board[k][j]) board[i][j] = 1;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		board[a][b] = 1;
	}

	floyd();

	// 1 > 2 라면 2도 1과 비교할 수 있다는 얘기 => 반대의 경우도 체크해주어야함
	for (int i = 1; i <= n;i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] && (i != j)) board[j][i] = 1;
		}
	}

	// 자기자신 제외 0의 개수 출력
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j && !board[i][j]) cnt++;
		}
		cout << cnt << "\n";
	}

	return 0;
}
