#include <iostream>
#include <vector>

/*
   1, 2, 3의 부분수열 => {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}

   backtracking => 현재 가리키는 수를 합에 추가할지 말지로 가지치기 => n번째까지 갔을 때 합을 비교
*/

using namespace std;

int n, s, cnt;
vector<int> v(20, 0);

void backtrack(int cur, int sum) {
	if (cur == n) {
		if (sum == s) cnt++;
		return;
	}

	backtrack(cur + 1, sum);
	backtrack(cur + 1, sum + v[cur]);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	backtrack(0, 0);
	if (s == 0) cnt--; // 부분 수열 크기가 양수인 경우만 세야하므로 합이 0일 때는 공집합도 포함하기 때문에 1 빼줌
	cout << cnt << "\n";

	return 0;
}
