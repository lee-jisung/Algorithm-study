#include <iostream>

#define SIZE 501
#define INF 1e9

using namespace std;

/*
   d1 -> 키가 작은 쪽 -> 큰쪽으로 갈 수 있는 경우
   d2 -> 키가 큰쪽에서 작은쪽으로 갈 수 있는 경우

   a, b를 입력받을 때 각각 d1[a][b] = 1, d2[b][a]= 1로 초기화

   floyd를 통해서 각각 d1, d2에 본인이 갈 수 있는 정점을 모두 표시

   i번째 행에서 본인 수를 제외한 나머지 수가 d1 또는 d2에서 INF가 아니면 자신이 몇번째인지 정확히 아는 학생
*/

int n, m, result;
int d1[SIZE][SIZE], d2[SIZE][SIZE];

void floyd() {

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d1[i][j] > d1[i][k] + d1[k][j]) {
					d1[i][j] = d1[i][k] + d1[k][j];
				}
				if (d2[i][j] > d2[i][k] + d2[k][j]) {
					d2[i][j] = d2[i][k] + d2[k][j];
				}
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			d1[i][j] = d2[i][j] = INF;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		d1[a][b] = 1;
		d2[b][a] = 1;
	}
	floyd();

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (d1[i][j] != INF || d2[i][j] != INF) cnt++;
		}
		if (cnt == n - 1) result++;
	}

	cout << result << "\n";

	return 0;
}
