#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
   내림차순으로 정렬 
   1. 박스의 가장 무거운 무게 > 크레인 무게제한 => 불가능 : -1 출력
   2. 크레인이 들 수 있는 가장 무거운 무게의 박스를 순서대로 탐색하면서 옮기기
*/

int n, m, result;
vector<int> crane, box;
queue<int> boxQ;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	crane.resize(n);
	for (int i = 0; i < n; i++) cin >> crane[i];
	cin >> m;
	box.resize(m);
	for (int i = 0; i < m; i++) cin >> box[i];

	sort(crane.begin(), crane.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	if (box[0] > crane[0]) {
		cout << -1 << "\n";
		return 0;
	}

	// 무거운 무게부터 차례대로 탐색
	while (1) {
		int p, q, cnt;
		p = q = cnt = 0;
		while (q < box.size() && p < crane.size()) {
			if (cnt == box.size()) break; // 모든 박스를 다 옮겼을 경우
		
			if (box[q] == 0) { // 이미 옮긴 건 pass
				cnt++; q++;
				continue;
			}
			if (box[q] != 0 && crane[p] >= box[q]) { // 아직 안옮긴 박스 중 옮기는 것이 가능하면 0으로 만들고 다음 탐색
				box[q] = 0;
				p++; q++;
				cnt++;
			}
			else if (box[q] > crane[p]) { // 크레인 무게제한보다 박스 무게가 크다면 그다음 박스를 탐색
				q++;
			}
		}
		result++;
		if (cnt == box.size()) break;
	}

	cout << result << "\n";

	return 0;
}
