#include <iostream>
#include <vector>

using namespace std;

/*
   터트린 풍선을 isCrash로 체크
*/

int n;
int bollun[1001];
bool isCrash[1001];
vector<int> result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> bollun[i];
		isCrash[i] = true;
	}

	int idx = 1, move = 0;
	for (int i = 0; i < n - 1; i++) {
		result.push_back(idx);
		move = bollun[idx];
		isCrash[idx] = false;
		
		// 양수 일 때 오른쪽 이동
		if (move > 0) {
			while (move) {
				idx++;
				if (idx > n) idx = 1;
				if (isCrash[idx]) move--;
			}
		}
		else { // 음수일 때 왼쪽 이동
			move *= -1;
			while (move) {
				idx--;
				if (idx < 1) idx = n;
				if (isCrash[idx]) move--;
			}
		}
	}

	result.push_back(idx);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}
