#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 100001

/*
   dfs => 이동할 때 마다 cnt세서
   arr에 길이 저장,

   2번에 도착했을 때 arr sorting해서 max값 제외, 합 결과로 도출
*/

using namespace std;

int n, robo1, robo2, res;
int arr[SIZE];
bool isVisit[SIZE];
vector<pair<int, int> > graph[SIZE];

void dfs(int cur, int cnt) {
	if (cur == robo2) {
		sort(arr, arr + cnt);
		for (int i = 0; i < cnt - 1; i++) {
			res += arr[i];
		}
		return;
	}

	for (int i = 0; i < graph[cur].size(); i++) {
		int nxt = graph[cur][i].first;
		if (isVisit[nxt]) continue;
		isVisit[nxt] = true;
		arr[cnt] = graph[cur][i].second;
		dfs(nxt, cnt + 1);
		isVisit[nxt] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> robo1 >> robo2;
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	isVisit[robo1] = true;
	dfs(robo1, 0);
	
	cout << res << "\n";

	return 0;
}
