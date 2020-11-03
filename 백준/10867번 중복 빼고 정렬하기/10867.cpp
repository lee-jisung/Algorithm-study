#include <iostream>
#include <queue>
#include <set>

using namespace std;

int n;
bool visit[2001];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (!visit[num + 1000]) {
			visit[num + 1000] = true;
			pq.push(num);
		}
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << "\n";
	return 0;
}
