#include <iostream>
#include <queue>

using namespace std;

/*
   minHeap의 크기가 n을 넘어가면 제일 작은 수를 하나 pop
   결국 제일 큰 숫자 n개만 남게 됨
*/

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			pq.push(num);
			if (pq.size() > n) {
				pq.pop();
			}
		}

	cout << pq.top() << "\n";

	return 0;
}
