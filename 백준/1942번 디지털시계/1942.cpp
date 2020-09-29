#include <iostream>
#include <string>

using namespace std;

string t1, t2;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; i++) {
		int idx = 0;
		int h1, m1, s1, h2, m2, s2;
		int num1, num2, cnt = 0;

		cin >> t1 >> t2;

		h1 = stoi(t1.substr(0, 2));
		m1 = stoi(t1.substr(3, 2));
		s1 = stoi(t1.substr(6, 2));

		h2 = stoi(t2.substr(0, 2));
		m2 = stoi(t2.substr(3, 2));
		s2 = stoi(t2.substr(6, 2));

		num1 = h1 * 10000 + m1 * 100 + s1;
		num2 = h2 * 10000 + m2 * 100 + s2;

		while (num1 != num2) {
			if (num1 % 3 == 0) cnt++;

			s1++;
			if (s1 == 60) {
				m1++;
				s1 = 0;
				if (m1 == 60) {
					h1++;
					m1 = 0;
					if (h1 == 24) {
						h1 = 0;
					}
				}
			}

			num1 = h1 * 10000 + m1 * 100 + s1;
		}
		if (num2 % 3 == 0) cnt++;
		cout << cnt << "\n";
	}
	return 0;
}
