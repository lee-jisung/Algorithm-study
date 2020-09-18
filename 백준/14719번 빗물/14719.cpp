#include <iostream>
#include <vector>
#include <algorithm>

/*
   현재 블록 기준 -> 왼쪽, 오른쪽 모든 블록을 탐색 => 현재 block보다 큰 블록의 최댓값을 각각 구함
   두개의 최대 블록 높이 중 최솟값 - 현재블록 높이를 결과에 누적
*/

using namespace std;


int w, h, p, q;
int result;
vector<int> blocks;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;
	vector<int> v(w);

	for (int i = 0; i < w; i++) cin >> v[i];

	for (int i = 1; i < w; i++) {
		p = q = v[i];
		for (int j = 0; j < i; j++) p = max(p, v[j]);
		for (int j = i + 1; j < w; j++) q = max(q, v[j]);
		result += min(p, q) - v[i];
	}

	cout << result << "\n";

	return 0;
}
