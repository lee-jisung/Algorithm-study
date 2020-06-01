#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 51
#define INF 1e9

using namespace std;

/* 
   DFS로 풀긴했는데, next_permutation으로 치킨집 경우의 수를 구한게 시간이 더 빠르고 코드길이도 짧음
   
   집마다 가까운 치킨 거리를 최솟값으로 갱신 -> 모든 집의 치킨거리 합 = 도시 치킨거리
   
   치킨집 최대 m개를 고르고 나머지는 모두 폐업
   1, 2, 3 ... m개 마다 치킨 거리를 계산하여 도시치킨거리가 최솟값이 되는 경우
*/

int n, m, result;
int board[SIZE][SIZE], dist[SIZE][SIZE];
bool isVisit[SIZE][SIZE];

vector<pair<int, int>> chicken, house;

int cal_dist() {
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		auto pos = house[i];
		for (int j = 0; j < chicken.size(); j++) {
			int d = abs(pos.first - chicken[j].first) + abs(pos.second - chicken[j].second);
			dist[pos.first][pos.second] = min(dist[pos.first][pos.second], d);
		}
		sum += dist[pos.first][pos.second];
	}
	return sum;
}

void dfs(int r, int c, int cnt, int rm) {
	if (cnt == rm) {

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = INF;
		result = min(result, cal_dist());
		return;
	}

	for (int i = r; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 2 && !isVisit[i][j]) {
				isVisit[i][j] = true;
				chicken.push_back({ i, j });
				dfs(i, j, cnt + 1, rm);
				isVisit[i][j] = false;
				chicken.pop_back();
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) house.push_back({ i,j });
		}

	result = INF;

	for (int k = 1; k <= m; k++) {

		for (int i = 1; i <= n; i++) {
			for (int j = 1;j <= n; j++) {
				if (board[i][j] == 2 && !isVisit[i][j]) {
					isVisit[i][j] = true;
					chicken.push_back({ i, j });
					dfs(i, j, 1, k);
					isVisit[i][j] = false;
					chicken.pop_back();
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}
