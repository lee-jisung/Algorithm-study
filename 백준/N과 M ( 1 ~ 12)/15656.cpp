#include <iostream>
#include <algorithm>

using namespace std;

int n, m, num[9], arr[9];
bool used[9];

void func(int no) {
	if (no == m) {
		
		for (int i = 0; i < m; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[no] = num[i];
		func(no + 1);
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> num[i];
	sort(num, num + n);
	func(0);

	return 0;
}
