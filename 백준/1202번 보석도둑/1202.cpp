#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 300001
#define INF 987654321

using namespace std;

/*
   가방 무게가 작은것 부터 -> 담을 수 있는 보석은 전부 pq에 push
   --> 가장 위에 있는 것이 현재 가방 무게에서 담을 수 있는 제일 비싼 것이므로 결과에 누적
*/

int n, k, m, v, c, idx;
long long result;

priority_queue<int> pq;
pair<int, int> jw[SIZE];
vector<int> bag;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jw[i].first = m, jw[i].second = v;
	}

	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push_back(c);
	}

	sort(jw, jw + n);
	sort(bag.begin(), bag.end());

	for (int i = 0; i < k; i++) {

		while (idx < n && jw[idx].first <= bag[i])
			pq.push(jw[idx++].second);

		if (!pq.empty()) {
			result += pq.top();
			pq.pop();
		}
	}

	cout << result << "\n";

	return 0;
}
