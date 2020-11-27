#include <iostream>

using namespace std;

int arr[5];

bool check() {
	for (int i = 0; i < 5; i++) {
		if (arr[i] != i + 1) return false;
	}
	return true;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) cin >> arr[i];

	while (1) {

		for (int i = 0; i < 4; i++) {
			if (arr[i] > arr[i + 1]) {
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				for (int i = 0; i < 5; i++) cout << arr[i] << " ";
				cout << "\n";
			}
		}
		if (check()) break;
	}

	return 0;
}
