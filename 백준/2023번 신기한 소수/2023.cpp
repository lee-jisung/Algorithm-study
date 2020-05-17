#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int n, st, last;
vector<int> res;

bool isPrime(int num) {
	if (num == 0 || num == 1) return false;
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0) return false;
	return true;
}

void dfs(int num, int depth) {

	if (depth == n) {
		res.push_back(num);
		return;
	}

	// 홀수만 더해서 소수면 재귀 탐색
	for (int i = 1; i <= 9; i += 2) {
		if (isPrime(num * 10 + i)) dfs(num * 10 + i, depth+1);
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	// 맨 앞자리가 2, 3, 5, 7 로 소수여야 함
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
	
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << "\n";

	return 0;
}
