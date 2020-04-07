#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 500001
#define INF 987654321

using namespace std;

int n, m, temp, cnt, res[SIZE];
vector<int> v, f;

/*
   lower_bound & upper_bound 이용
   upper - lower -> 같은 값의 개수 나옴
*/

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
		cnt = 0;
		cnt = upper_bound(v.begin(), v.end(), f[i]) - lower_bound(v.begin(), v.end(), f[i]);
		res[i] = cnt;
	}

	for (int i = 0; i < m; i++) {
		cout << res[i] << " ";
	}

	return 0;
}
