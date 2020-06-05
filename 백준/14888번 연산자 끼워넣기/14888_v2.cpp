#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, max_val, min_val;
int num[11], oper[11], cal[4];

void dfs(int no) {
	if (no == n - 1) {

		int sum = num[0];
		for (int i = 0;i < no; i++) {
			if (oper[i] == 0) sum += num[i + 1];
			else if (oper[i] == 1) sum -= num[i + 1];
			else if (oper[i] == 2) sum *= num[i + 1];
			else if (oper[i] == 3) sum /= num[i + 1];
		}

		max_val = max(max_val, sum);
		min_val = min(min_val, sum);

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (cal[i] != 0) {
			cal[i]--;
			oper[no] = i;
			dfs(no + 1);
			cal[i]++;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];

	for (int i = 0; i < 4; i++) {
		int tmp; cin >> tmp;
		cal[i] = tmp;
	}

	max_val = -INF; min_val = INF;
	
	dfs(0);
	
	cout << max_val << "\n" << min_val << "\n";
	
	return 0;

}
