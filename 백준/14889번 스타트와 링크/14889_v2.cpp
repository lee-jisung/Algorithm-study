#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, result;
int state[21][21], team[21];
bool sel[21];

/*
   dfs -> 순서 선택할 때 앞에서 선택한 것을 뒤에서 다시 보지않도록 제거하는것참고
*/

void dfs(int cur, int no) {
	if (no == n / 2) {

		int t1, t2;
		t1 = t2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (sel[i] && sel[j]) t1 += state[i][j] + state[j][i];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (!sel[i] && !sel[j]) t2 += state[i][j] + state[j][i];
			}
		}

		result = min(result, abs(t1 - t2));

		return;
	}

	for (int i = cur + 1; i <= n; i++) {
		if (!sel[i]) {
			team[no] = i;
			sel[i] = true;
			dfs(i, no + 1);
			sel[i] = false;
		}
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> state[i][j];

	result = INF;

	dfs(0, 0);

	cout << result << "\n";

	return 0;
}
