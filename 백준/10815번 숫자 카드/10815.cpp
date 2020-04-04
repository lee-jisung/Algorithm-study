#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

int n, m, temp; 
vector<int> v, f;

bool binary_search(int start, int end, int x) {
	if (start > end) return false;
	int mid = (start + end) / 2;
	if (v[mid] == x) return true;
	else if (v[mid] > x) {
		return binary_search(start, mid - 1, x);
	}
	else
		return binary_search(mid + 1, end, x);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		f.push_back(temp);
	}
	
	for (int i = 0; i < m; i++) {
		cout << binary_search(0, v.size() - 1, f[i]) << " ";
	}

	return 0;
}
