#include <iostream>
#include <string>

using namespace std;

long long sum;

string a, b;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		int A = a[i] - '0';
		for (int j = 0; j < b.length(); j++) {
			int B = b[j] - '0';
			sum += A * B;
		}
	}

	cout << sum << "\n";

	return 0;
}
