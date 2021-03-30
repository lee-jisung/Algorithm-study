#include <iostream>
#include <deque>
#include <vector>

using namespace std;

/* 
*  sliding window
* 
*  deque의 맨 앞 index <= (현재 index - window size) 라면 앞에서 pop front
* 
*  deuqe의 뒤에서부터 현재 입력된 값보다 큰것이 있으면 전부 pop back
* 
*  deque에 맨 앞값이 최솟값임을 보장 / deque의 뒤에서부터 값을 push
* 
*/

int N, L;
deque<pair<int, int>> dq;
vector<int> res;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	res.resize(N);

	for (int i = 0; i < N; i++) {
		int cur; cin >> cur;

		if (!dq.empty() && dq.front().second <= i - L) {
			dq.pop_front();
		}

		while (!dq.empty() && dq.back().first > cur) {
			dq.pop_back();
		}

		
		dq.push_back({ cur, i });
		res[i] = dq.front().first;
	}

	for (int i = 0; i < N; i++) cout << res[i] << " ";
	cout << "\n";

	return 0;
}
