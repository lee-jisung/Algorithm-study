#include <iostream>
#include <map>

/*
   A * B * C + A*B + B*C + A*C + A + B + C + 1 = (A+1) * (B+1) * (C+1)
*/

using namespace std;

int t, n, result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {

		map<string, int> clothes;
		result = 1;
		
		cin >> n;

		for (int i = 0; i < n; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			clothes[str2]++;
		}

		for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
			result *= (clothes[iter->first] + 1);
		}

		cout << --result << "\n";

	}

	return 0;
}
