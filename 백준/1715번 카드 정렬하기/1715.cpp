#include <iostream>
#include <queue>

using namespace std;

/*
   최소 비교 횟수 구하기 => 값을 적은것 끼리 계속 더해서 누적하는 것이 최선
   minHeap을 이용해서 2개의 합을 result에 누적하고, minHeap에 push
   1개가 남을 때까지 반복 후 출력
*/

int n;
long long result;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		pq.push(num);
	}

	if (n == 1) {
		cout << 0 << "\n";
		return 0;
	}

	while (pq.size() != 1) {
		long long num1 = pq.top(); pq.pop();
		long long num2 = pq.top(); pq.pop();
		result += (num1 + num2);
		pq.push(num1 + num2);
	}

	cout << result << "\n";

	return 0;
}
