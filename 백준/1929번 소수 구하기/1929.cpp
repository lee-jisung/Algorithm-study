#include <iostream>
#include <queue>
#include <cmath>

#define SIZE 1000001

using namespace std;

int a[SIZE];
int n, m;
queue<int> q;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;

	for (int i = 1; i < SIZE; i++)
		a[i] = i;

	for (int i = 2; i < sqrt(SIZE); i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j < SIZE; j += i) {
			a[j] = 0;
		}
	}

	for (int i = m; i <= n; i++)
		if (a[i] && i != 1) q.push(a[i]);

	while (!q.empty()) {
		cout << q.front() << "\n";
		q.pop();
	}
	
	return 0;
}
