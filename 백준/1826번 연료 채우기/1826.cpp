#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
/*
   보유한 가스량 => 갈 수 있는 주유소를 모두 탐색하면서 pq에 연료 넣고
   가장 많은 연료량을 보유한 주유소의 연료를 보유 가스량에 추가

   보유 가스량 >= 마을 거리 가 될 때까지 반복

*/

int n, L, P, idx, gasCnt;
vector<pair<int, int>> gas;
priority_queue<int> pq;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		gas.push_back({ a, b });
	}
	cin >> L >> P;

	// 거리 순으로 정렬
	sort(gas.begin(), gas.end());

	// 보유 가스량이 마을 거리보다 클때까지
	while (P < L) {
		while (gas[idx].first <= P) { // 보유가스량으로 갈 수 있는 주유소면
			pq.push(gas[idx].second); // pq에 연료 넣기
			idx++;
			if (idx == n) break; // n번째 주유소면 탐색 x 
		}
		if (pq.empty()) break; // pq가 비어있으면 갈 수 있는 주유소가 더이상 없으므로 중지
		
		// 주유소 추가, 가스 보유량 추가
		gasCnt++;
		P += pq.top();
		pq.pop();
	}

	// 최종 가스 보유량이 마을 거리보다 작으면 -1, 크면 주유소 개수
	P < L ? cout << -1 << "\n" : cout << gasCnt << "\n";

	return 0;
}
