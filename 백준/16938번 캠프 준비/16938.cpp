#include <iostream>
#include <algorithm>

using namespace std;

/*
   L <=  문제 난이도 합 <= R
   가장 어려운 문제 - 가장 쉬운 문제 >= X
*/

int n, l, r, x, result;
int level[15], problem[15];
bool isUsed[15];

// 중복되는 경우 제거위해서 cur로 인덱스 표시
void makeProblem(int cur, int no) {
	if (no > n) return;
	if (no >= 2) {
		int maxLevel = 0, minLevel = 1e9, sum = 0;
		for (int i = 0; i < no; i++) {
			sum += level[problem[i]];
			maxLevel = max(maxLevel, level[problem[i]]);
			minLevel = min(minLevel, level[problem[i]]);
		}
		if (sum >= l && sum <= r && maxLevel - minLevel >= x)
			result++;
	}

	for (int i = cur; i < n; i++) {
		if (isUsed[i]) continue;
		isUsed[i] = true;
		problem[no] = i;
		makeProblem(i, no + 1);
		isUsed[i] = false;
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) cin >> level[i];

	makeProblem(0, 0);

	cout << result << "\n";

	return 0;
}
