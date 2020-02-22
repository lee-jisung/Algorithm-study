#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 8
#define INF 987654321

using namespace std;

int n, m, arr[SIZE]; 
bool cache[SIZE];

void solve(int k) { // k 개 숫자를 선택
	if (k == m) { // 선택한 숫자가 m개면
		for (int i = 0; i < m;i++) {
			cout << arr[i] + 1 << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) { // 1 ~ n까지 숫자 중 (0 ~ n-1)
		if (!cache[i]) { // i를 사용하지않았으면
			arr[k] = i; // k번째 수로 i를 넣고
			cache[i] = true; // i는 사용
			solve(k + 1); // k + 1번째 숫자 정함
			cache[i] = false; // k번째 수를 i로 정한 모든 경우를 확인한 후이기때문에 i를 다시 되돌려놓음
		}
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	solve(0);

	return 0;
}
