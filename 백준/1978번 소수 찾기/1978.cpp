#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1001
#define INF 987654321

using namespace std;

int n, res;
int arr[SIZE];

vector<int> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 2; i <= 1000; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(1000); i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j <= 1000; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < v.size(); i++) {
		if (arr[v[i]]) res++;
	}

	cout << res << "\n";

	return 0;
}
