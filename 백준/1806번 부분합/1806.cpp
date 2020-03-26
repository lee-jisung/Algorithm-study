#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100001
#define INF 987654321

using namespace std;

int n, s, front, rear, res, sum;
int a[SIZE];

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	res = INF;
	sum = a[0];

	while (front <= rear && rear < n) {

		if (sum < s) {
			sum += a[++rear];
		}
		else if (sum == s) {
			res = min(res, (rear - front) + 1);
			sum += a[++rear];
		}
		else if (sum > s) {
			res = min(res, (rear - front) + 1);
			sum -= a[front++];
		}
	}
	
	if (res == INF) cout << 0 << "\n";
	else cout << res << "\n";

	return 0;
}
