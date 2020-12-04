#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

/*
   초밥을 집는 개수와 종류를 다르게 카운트 한다.

   circular array의 형태로 투포인터를 돌림 => left가 마지막 요소까지 가면 종료

   right 포인터를 증가시키면서 초밥을 선택한다.
   map으로 초밥을 고른 개수를 체크해줌 
    => 0개인 것을 골랐을 때는 pick & type을 ++해줌
	=> 1개 이상인 것을 골랐을 때는 pick만 ++

   k개롤 골랐을 때 쿠폰으로 먹을 수 있는 초밥을 이미 집었는지를 확인해서 최대 가짓수를 찾고
   left 포인터를 하나 줄여주고, 초밥 개수도 줄임 (개수가 0이되면 type도 줄임)

*/

int n, d, k, c, result;
int plate[3000001];
map<int, int> pickPlate;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d >> k >> c;

	for (int i = 0; i < n; i++) cin >> plate[i];

	int left = 0, right = 0, pick = 0, type = 0;

	while (left < n) {

		if (pick < k) {
			// 아직 고르지 않은 초밥이면 type을 ++
			if (pickPlate[plate[right]] == 0) type++;
			pickPlate[plate[right]]++;
			pick++;
			right++;
		}

		// n까지 갔으면 다시 처음으로 
		if (right == n) right = 0;

		// k개를 집었으면 left를 하나 줄인다.
		if (pick == k) {
			if (pickPlate[c] == 0) {
				result = max(result, type + 1);
			}
			else {
				result = max(result, type);
			}
			if (--pickPlate[plate[left]] == 0) type--;
			pick--;
			left++;
		}
	}

	cout << result << "\n";

	return 0;
}
