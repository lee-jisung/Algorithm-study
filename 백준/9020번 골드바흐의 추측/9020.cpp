#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 10001
#define INF 987654321

using namespace std;


int tc, n, m; 
int arr[SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	for (int i = 2; i <= 10000;i++) arr[i] = i;

	for (int i = 2; i <= sqrt(10000); i++) {
		if (!arr[i]) continue;
		for (int j = i + i; j <= 10000; j += i)
			arr[j] = 0;
	}


	while (tc--) {
		cin >> n;
		vector<int> v;
		int r1, r2, res = INF;

		for (int i = 2;i <= n; i++) {
			if (arr[i] != 0) {
				v.push_back(arr[i]);
			}
		}

		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				if (v[i] + v[j] == n) {
					if (res > abs(v[j] - v[i])) {
						if (v[j] > v[i]) r1 = v[i], r2 = v[j];
						else r1 = v[j], r2 = v[i];
						res = abs(v[j] - v[i]);
					}
				}
			}
		}
		cout << r1 << " " << r2 << "\n";
	}
	return 0;
}
