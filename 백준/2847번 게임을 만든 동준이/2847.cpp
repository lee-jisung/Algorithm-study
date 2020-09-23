#include <iostream>

using namespace std;

/*
   점수를 더해가면서 증가하는 순으로 표시 => 뒤에서부터 자신보다 전값이 크거나 같다면 => 바로 전값이 자신 -1값이 되게 만듦
*/

int sum;
int n, level[101];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> level[i];

	for (int i = n-2; i >= 0; i--) {
		if (level[i] >= level[i + 1]) {
			sum += level[i] - (level[i + 1] - 1);
			level[i] = level[i + 1] - 1;
		}
	}

	cout << sum << "\n";

	return 0;
}
