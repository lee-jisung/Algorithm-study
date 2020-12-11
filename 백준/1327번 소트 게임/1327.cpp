#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;

/*
*  bfs로 모든 경우의 수 탐색
*  k개를 골라 역순으로 바꾼 순열을 map을 이용해서 방문 처리
* 
*  문자열 역순 => (0 ~ k /2)만큼 (idx + 1) 과 (idx + k -1 - i)를 swap하면 됨

*/

int n, k, chooseNumber;
string origin, result;
map<string, bool> isVisit;

int bfs() {
	queue<pair<string, int>> q;
	q.push({ origin, 0 });
	isVisit[origin] = true;
	while (!q.empty()) {

		string permu = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (permu.compare(result) == 0) {
			return depth;
		}

		for (int idx = 0; idx <= n - k; idx++) {
			string temp = permu;
			for (int i = 0; i < k / 2; i++) {
				char c = temp[idx + i];
				temp[idx + i] = temp[(idx + k - 1) - i];
				temp[(idx + k - 1) - i] = c;
			}
			if (isVisit[temp]) continue;
			isVisit[temp] = true;
			q.push({ temp, depth + 1 });
		}
	}
	return -1;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		origin += c;
	}

	result = origin;
	sort(result.begin(), result.end());

	cout << bfs() << "\n";

	return 0;
}
