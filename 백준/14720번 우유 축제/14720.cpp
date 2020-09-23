#include <iostream>

using namespace std;

int n, milk, cur, cnt;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> milk;
		if (milk == cur % 3) {
			cur++; 
			cnt++;
		}
	}

	cout << cnt << "\n";

	return 0;
}
