#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
   임의의 투표 수 최대값 >= 다솜 투표값 
   => 최대값 -1, 다솜 +1 (매수할 사람+1)을
   다른 후보군의 투표수 최대값이 다솜의 투표수 보다 적을때까지 반복
*/

int n, dasom, person;
priority_queue<int> pq;
vector<int> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);

	if (n == 1) {
		cout << 0 << "\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i > 0) pq.push(v[i]);
	}

	dasom = v[0];

	while (pq.top() >= dasom) {
		int tmp = pq.top();
		pq.pop();
		tmp--; person++; dasom++;
		pq.push(tmp);
	}
	
	cout << person << "\n";

	return 0;
}
