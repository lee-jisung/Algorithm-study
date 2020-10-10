#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m, resultDist;
bool isSelect[13];
vector<pair<int, int>> chicken, home;

void selectChicken(int cur, int cnt) {
	if (cnt == m) {
		int distSum = 0;
		for (int i = 0; i < home.size(); i++) {
			int dist = INF;
			int r = home[i].first; int c = home[i].second;
			for (int j = 0; j < chicken.size(); j++) {
				if (!isSelect[j]) continue;
				dist = min(dist, abs(r - chicken[j].first) + abs(c - chicken[j].second));
			}
			distSum += dist;
		}
		resultDist = min(resultDist, distSum);
		return;
	}

	for (int i = cur; i < chicken.size(); i++) {
		if (isSelect[i]) continue;
		isSelect[i] = true;
		selectChicken(i, cnt + 1);
		isSelect[i] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num; cin >> num;
			if (num == 1) home.push_back({ i, j });
			else if (num == 2) chicken.push_back({ i, j });
		}
	}
	resultDist = INF;
	selectChicken(0, 0);

	cout << resultDist << "\n";

	return 0;
}
