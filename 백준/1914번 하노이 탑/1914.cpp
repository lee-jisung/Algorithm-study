#include <iostream>
#include <algorithm>

using namespace std;

int N;

void hanoi(int from, int by, int to, int n) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	hanoi(from, to, by, n - 1);
	cout << from << " " << to << "\n";
	hanoi(by, from, to, n - 1);
}

string makeNum(string num1, string num2) {
	long long sum = 0;
	string res;

	while (!num1.empty() || !num2.empty() || sum) {
		if (!num1.empty()) {
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()) {
			sum += num2.back() - '0';
			num2.pop_back();
		}
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	if (N <= 20) {
		cout << (1 << N) - 1 << "\n";
		hanoi(1, 2, 3, N);
	}
	else {
		string num = "2";
		for (int i = 0; i < N - 1; i++) {
			string tmp = makeNum(num, num);
			num = tmp;
		}
		int last = num.back() - '0';
		num.pop_back();
		last--;
		num.push_back(last + '0');
		cout << num << "\n";
	}

	return 0;
}
