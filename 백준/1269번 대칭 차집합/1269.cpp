#include <iostream>
#include <set>

using namespace std;

/*
   B의 원소 중 A 에 없는것 + A의 원소 중 B에 없는것 카운트하면 됨
*/

int n, m, result;
set<int> A, B;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num; cin >> num; 
		A.insert(num);
	}
	for (int i = 0; i < m; i++) {
		int num; cin >> num; 
		B.insert(num);
	}

	// A - B
	// B의 원소 중 A 에 없는것
	for (int b : B) {
		if (A.find(b) == A.end()) {
			result++;
		}
	}

	// B - A
	// A의 원소 중 B에 없는것
	for (int a : A) {
		if (B.find(a) == B.end()) {
			result++;
		}
	}

	cout << result << "\n";

	return 0;
}
