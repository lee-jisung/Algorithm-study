#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// LIS algorithm

vector<int> v, vt;
int n, result;

int main(void) {
	
	cin >> n;
	vt.push_back(-1);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	for (int i = 0; i < n; i++) {
		if (vt.back() < v[i]) {
			vt.push_back(v[i]);
			result++;
		}
		else {
			auto it = lower_bound(vt.begin(), vt.end(), v[i]);
			*it = v[i];
		}
	}
	cout << result << "\n";
	return 0;
}
