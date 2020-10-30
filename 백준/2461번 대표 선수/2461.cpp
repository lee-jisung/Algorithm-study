#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;
/*
   능력치, 학급별 정보를 바탕으로 vector에 저장 => 능력치 순으로 정렬
   투 포인터를 이용해서 N개의 팀이 모인 연속한 구간을 계속 오른쪽으로 옮겨가며 능력치 차이의 최솟값 계산

   two pointer 이용
   endPtr => 한칸씩 뒤로 옮기면서 학급별로 cnt에 몇개의 학급이 지나왔는지 체크
   classCount => 현재까지 지나온 학급별 수 ( cnt의 값이 0일 때 ++ => 새로운 학급이 증가된 것)
       => classCount이 n이 됐을 때, 학급별로 모든 선수가 최소 1명씩은 지나온 것
	   => startPtr을 앞에서부터 뒤로 옮겨가면서 (endPtr -1)이 가리키는 값과 차이를 갱신
	   => 만약 cnt값이 0이 되면, 학급수가 n보다 작은경우가 되므로 이때 다시 endPtr을 늘려가면서 n개가 될 때가지 탐색
*/

int n, m, result;
vector<pair<int, int>> stats;
int cnt[1005], classCount;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m;j++) {
			int tmp; cin >> tmp;
			stats.push_back({ tmp, i });
		}
	}

	sort(stats.begin(), stats.end());

	result = INF + 1;
	int startPtr = 0, endPtr = 0;
	while (endPtr < n * m) {
		if (cnt[stats[endPtr].second] == 0) classCount++;
		cnt[stats[endPtr].second]++;
		endPtr++;
		while (classCount == n) {
			//endPtr -1을 하는 이유 -> endPtr++로 탐색을 위한 값보다 1칸 뒤로 왓기 때문
			result = min(result, stats[endPtr - 1].first - stats[startPtr].first);
			// 학급 수가 0이 될 때가지 startPtr을 증가시키면서 endPtr - 1 이 가리키는 값과 비교
			cnt[stats[startPtr].second]--;
			if (cnt[stats[startPtr].second] == 0) classCount--; 
			startPtr++;
		}
	}

	cout << result << "\n";

	return 0;
}
