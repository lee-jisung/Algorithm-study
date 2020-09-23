#include <iostream>
#include <algorithm>

using namespace std;

/* 
    1위 ~ N위 동석차 없음

	서류, 면접 접수로 비교

	서류로 sorting을 하면 1, 2, 3 ,4...n등까지 정렬
	=> i번째 사람 면접 등수 => i-1번째보다 높으면 선발 가능 => 서류, 면접 둘 중 하나만 높으면 선발 가능하기 때문
*/

int T, n;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		pair<int, int> candidate[100001];
		cin >> n;
		for (int i = 0; i < n; i++) cin >> candidate[i].first >> candidate[i].second;

		sort(candidate, candidate + n);

		int rank = candidate[0].second;
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (rank > candidate[i].second) {
				rank = candidate[i].second;
				cnt++;
			}
		}
		cout << cnt << "\n";
	}

	return 0;
}
