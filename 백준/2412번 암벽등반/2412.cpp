#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 50001
#define INF 987654321

using namespace std;

/*
   5만개의 홈을 방문 처리,
   현재 홈의 좌표값의 양 옆으로 (x-a) <= 2, (y - b) <= 2인 coordinate 범위까지만 탐색하면서
   방문하지 않았던 홈을 큐에 넣어 줌
*/

int n, m, result; 
bool isVisit[SIZE];

vector<pair<int, int>> coordinate;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	coordinate.push_back({ 0, 0 });
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		coordinate.push_back({ x, y });
	}
	result = -1;
	sort(coordinate.begin(), coordinate.end());

	queue<pair<int, int>>q;
	q.push({ 0, 0 });
	isVisit[0] = true;

	while (!q.empty()) {

		int idx = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (coordinate[idx].second == m) {
			result = depth;
			break;
		}

		for (int i = idx; i > 0; i--) {
			if (abs(coordinate[idx].first - coordinate[i].first) > 2) break;
			if (!isVisit[i] && abs(coordinate[idx].second - coordinate[i].second) <= 2) {
				q.push({ i, depth + 1 });
				isVisit[i] = true;
			}
		}
		for (int i = idx; i <= n; i++) {
			if (abs(coordinate[idx].first - coordinate[i].first) > 2) break;
			if (!isVisit[i] && abs(coordinate[idx].second - coordinate[i].second) <= 2) {
				q.push({ i, depth + 1 });
				isVisit[i] = true;
			}
		}
	}

	cout << result << "\n";

	return 0;
}
