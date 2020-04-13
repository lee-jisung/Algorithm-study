#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 10001
#define INF 987654321

/*
   a 가 b를 신뢰: b를 해킹 -> a 해킹 가능
   b와 연결된 a로 bfs()
*/

using namespace std;

int n, m; 
bool isVisit[SIZE];

vector<int> graph[SIZE], res;
vector<pair<int, int>> hack;

bool cmp(pair<int, int> a, pair<int, int >b) {
	return a.first > b.first;
}

void bfs(int x) {
	int cnt = 0;
	queue<int> q;
	q.push(x);
	isVisit[x] = true;

	while (!q.empty()) {

		int y = q.front();
		q.pop();
		for (int i = 0; i < graph[y].size(); i++) {
			int temp = graph[y][i];
			if (!isVisit[temp]) {
				q.push(temp);
				isVisit[temp] = true;
				cnt++;
			}
		}
	}
	hack.push_back({cnt, x});
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1;i <= n; i++) {
		memset(isVisit, false, sizeof(isVisit));
		bfs(i);
	}
	sort(hack.begin(), hack.end(), cmp );
	for (int i = 0; i < hack.size(); i++)
		if (hack[0].first == hack[i].first) res.push_back(hack[i].second);
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << "\n";

	return 0;
}
