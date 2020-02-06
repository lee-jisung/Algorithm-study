#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 50
#define INF 987654321

using namespace std;

int n, m, result = INF;
int map[SIZE][SIZE];

vector<pair<int, int> > chicken, house;
vector<int> v;

int main(void) {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				chicken.push_back({ i, j });
			if (map[i][j] == 1)
				house.push_back({ i, j });
		}

	// m -> 폐업시키지 않을 최대 치킨집 개수
	for (int c = 0; c <= m; c++) {

		v.clear();
		for (int i = c + 1; i <= chicken.size(); i++)
			v.push_back(0);
		for (int i = 1; i < c + 1; i++)
			v.push_back(1);

		// chicken size = v size
		do {
			int sum = 0, cnt = 0;;
			for (int i = 0; i < house.size(); i++) {
				int min_dis = INF;
				for (int j = 0; j < v.size(); j++) { // 폐업시키지 않는 경우의 수에서 거리 계산
					if (v[j]) {
						int distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
						min_dis = min(min_dis, distance);
					}
				}
				sum += min_dis;
				if (sum > INF) sum = INF;
			}
			result = min(result, sum);
		} while (next_permutation(v.begin(), v.end()));
		
	}
	cout << result << "\n";

	return 0;
}
