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

int n, m; 

priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 0) {
			if (!pq.empty()) {
				cout << pq.top().second << "\n";
				pq.pop();
			}
			else cout << "0\n";
		}
		else pq.push({ abs(m), m });
	}

	return 0;
}
