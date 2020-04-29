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

int n, m; 
long long t, cnt, a[SIZE], b[SIZE];

vector<long long> va, vb;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];

	for (int i = 0; i < n; i++) { // a배열에서 나올 수 있는 합의 모든 경우를 저장
		long long temp = a[i];
		va.push_back(temp);
		for (int j = i + 1; j < n; j++) {
			temp += a[j];
			va.push_back(temp);
		}
	}

	for (int i = 0; i < m; i++) { // b에서 나올 수 있는 모든 조합 저장
		long long temp = b[i];
		vb.push_back(temp);
		for (int j = i + 1; j < m; j++) {
			temp += b[j];
			vb.push_back(temp);
		}
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	for (int i = 0; i < va.size(); i++) {
		int low = lower_bound(vb.begin(), vb.end(), t - va[i]) - vb.begin();
		int high = upper_bound(vb.begin(), vb.end(), t - va[i]) - vb.begin();
		cnt += high - low;
	}

	cout << cnt << "\n";
	return 0;
}
