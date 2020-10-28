#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, result;
int city[11][11];
bool isVisit[11];


void findPath(int no, int cur, int start, int sum) {
	
	// n번째 도시에 도착했고, 마지막 도시에서 출발도시로 갈수 있는 경우,
	// 현재까지 온 비용 + 마지막->출발지 비용 경로 값 구하기
	if (no == n && city[cur][start ] != 0) {
		result = min(result, sum + city[cur][start]);
		return;
	}

	for (int i = 0; i < n; i++) {
		// 방문했거나 비용이 0이어서 갈 수 없는 경우 pass
		if (isVisit[i] || city[cur][i] == 0) continue;
		isVisit[i] = true;
		findPath(no + 1, i, start, sum + city[cur][i]);
		isVisit[i] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> city[i][j];

	result = INF;

	// 출발 도시 선정
	for (int i = 0; i < n; i++) {
		isVisit[i] = true;
		findPath(1, i, i, 0);
		isVisit[i] = false;
	}

	cout << result << "\n";

	return 0;
}
