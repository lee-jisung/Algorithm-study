#include <iostream>

using namespace std;

/*
   비밀번호 만든 후, 사용한 비밀번호가 선견지명으로 알게된 번호를 모두 사용했으면 count
*/

int n, m, result;
int arr[7], hint[7];

void makePassword(int no) {
	if (no == n) {
		bool isUsed[10] = { false, };
		for (int i = 0; i < n; i++)
			isUsed[arr[i]] = true;
		for (int i = 0; i < m; i++)
			if (!isUsed[hint[i]]) return;
		result++;
		return;
	}

	for (int i = 0; i < 10; i++) {
		arr[no] = i;
		makePassword(no + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> hint[i];
	}

	makePassword(0);

	cout << result << "\n";

	return 0;
}
