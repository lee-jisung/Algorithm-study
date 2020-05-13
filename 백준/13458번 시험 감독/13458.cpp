#include <iostream>
#include <cmath>

#define SIZE 1000001

using namespace std;

long long n, b, c, res;
long long test[SIZE];

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> test[i];
	cin >> b >> c;

	for (int i = 0; i < n; i++) {

		test[i] -= b; res++;
		if (test[i] > 0) {
			int temp = ceil((double)test[i] / c);
			res += temp;
		}
	}
	cout << res << "\n";
	return 0;
}
