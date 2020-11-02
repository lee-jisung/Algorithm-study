#include <iostream>
#include <algorithm>

using namespace std;
/*
   s에서 택배를 받아 e에 내려놓는다고 할 때, s ~ e - 1 구간까지는 들고있어야함
   예를들어 가방 용량이 40이고 s =2, e=4, 택배 = 20이라고 하면
   1   2  3  4  5  6   이라고 할 때  ==>   1  2  3  4  5  6
   40 40 40 40 40 40                       40 20 20 40 40 40
   의 가방 용량이 됨

   그러면 1 ~ 4 까지 택배 용량이 30인걸 나르려고해도 2, 3 구간에서 20이기때문에 최대 20만큼만 가능함

   즉, 택배를 내릴 도착지점이 1쪽에 가까울 수록 (시작지점이 어디든 상관없이) 더 많은 택배를 실어 나를 수 있음

   1. 한번 방문한 도시를 다시방문하지 않고 1번 도시부터 출발 => 1번 도시와 가까운 순으로 박스 옮기는 것이 최적
   2. 도착도시 기준 오름차순 정렬 (같다면 시작도시 기준 오름차순)
   3. 시작도시 ~ 도착도시까지 가장 많이 적재된 박스 양 구함
   4. 3번에서 구한값에 더 적재할 수 있는 양을 파악, 결과값에 더해줌
   5. 해당 구간에 4번에서 구한값 만큼 더함
   6. 3 ~ 5를 m번 반복

*/

int n, m, c;
int capacityWeight[2001]; // idx에서 트럭에 차 있는 박스 양
pair<pair<int, int>, int> box[10001];

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.second == b.first.second)
		return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c >> m;
	for (int i = 0; i < m; i++) {
		cin >> box[i].first.first >> box[i].first.second >> box[i].second;
	}

	sort(box, box + m, cmp);

	int result = 0;
	for (int i = 0; i < m; i++) {

		int boxCount = 0;
		// i번째 출발 ~ 도착 도시 돌면서 적재된 박스 중 최대값
		for (int j = box[i].first.first; j < box[i].first.second; j++)
			boxCount = max(boxCount, capacityWeight[j]);
		// 더 실을 수 있는 양
		int availWeight = min(box[i].second, c - boxCount);
		result += availWeight;
		// 해당 구간에 더 적재함
		for (int j = box[i].first.first; j < box[i].first.second; j++)
			capacityWeight[j] += availWeight;
	}
	cout << result << "\n";
	return 0;
}
