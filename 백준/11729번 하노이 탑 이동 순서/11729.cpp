#include <iostream>

using namespace std;

int N;

void hanoi(int from, int by, int to, int n) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	hanoi(from, to, by, n-1);
	cout << from << " " << to << "\n";
	hanoi(by, from, to, n-1);
}

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cout << (1 << N) - 1 << "\n";
	hanoi(1, 2, 3, N);
	return 0;
}
