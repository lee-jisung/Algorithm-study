#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
   센서 위치 정렬 => 각 센서별 인접 거리 차이 계산
   기지국을 인접 거리가 긴 위치 순대로 k개 배치하면 수신가능 영역 거리의 합의 최솟값 구할 수 있음

   => 기지국 개수 k-1개 만큼 가장 긴 길이를 지울 수 있다고 생각 ==> n-k개만큼 더해주면됨

   ex, 1 6 9 3 6 7 => 1 3 6 6 7 9가 되고 각 센서별 차이는 2 3 0 1 2가됨
   가장 길이가긴 3을 제거하면, 두개의 기지국에서 한개는 2만큼 수신, 나머지 한개는 0 + 1 + 2만큼 수신하면 됨
   따라서 0 + 1 + 2 + 2를 하면 됨

   즉, 센서들간 가장먼 거리 순대로 K-1개의 연결고리를 제거하면 됨

*/

int n, k, result;
vector<int> sensor, diff;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	// 센서 1개당 기지국 1개가 맡으면 되므로 0
	if (k >= n) {
		cout << 0 << "\n";
		return 0;
	}

	sensor.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> sensor[i];
	}

	sort(sensor.begin(), sensor.end());

	diff.resize(n - 1);
	for (int i = 0; i < n - 1; i++) {
		diff[i] = sensor[i + 1] - sensor[i];
	}

	sort(diff.begin(), diff.end());

	for (int i = 0; i < n - k; i++) {
		result += diff[i];
	}

	cout << result << "\n";

	return 0;
}
