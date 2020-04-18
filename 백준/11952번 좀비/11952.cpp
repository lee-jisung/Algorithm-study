#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <limits.h>

#define SIZE 100001
#define INF 1987654321

using namespace std;

/*
   danger() : 감연된 도시를 기준으로 감염 범위(s) 거리까지 bfs를 돌면서 city 배열 값을 1로 바꿔줌

   find_pay(): 시작 정점 1부터 n까지 bfs를 돌리면서 
               현재 도시에서 다음 도시로 가는 비용 < 이미 표시된 다음 도시로 가는 비용
			   --> dist[next] = (pay + p) or (pay + q)를 갱신해줌 

			   --> 이렇게 하는 이유는 방문 처리를 해준다면 더 싸게 갈 수 있는 경로가 다른 경로로 먼저 방문이 되어 
			       갈 수 없게 되기 때문
			   --> 즉, 최소 거리가 아니라 조건에 따른 최소 비용을 찾는 문제 이기 때문에 dist배열을 사용함

*/

int n, m, k, s, p, q;
int city[SIZE]; // 점령 도시: -1, 위험 도시: 1, 안전 도시: 0
bool isVisit[SIZE];
long long dist[SIZE]; // 최소 비용 범위 

vector<int> graph[SIZE], infect;

void danger() {
	for (int i = 0; i < infect.size(); i++) {
		memset(isVisit, false, sizeof(isVisit));

		queue<pair<int, int>> qu;
		qu.push({ infect[i], 0 });
		isVisit[infect[i]] = true;
		while (!qu.empty()) {
			int ct = qu.front().first;
			int depth = qu.front().second;
			qu.pop();

			if (depth == s) continue;

			for (int i = 0; i < graph[ct].size(); i++) {
				int next = graph[ct][i];
				if (!isVisit[next] && city[next] != -1 ) {
					qu.push({ next, depth + 1 });
					city[next] = 1;
					isVisit[next] = true;
				}
			}
		}
	}
}

void find_path() {
	memset(isVisit, false, sizeof(isVisit));
	queue<pair<int, long long>> qu;
	qu.push({ 1, 0 }); // city, pay
	dist[1] = 0;
	isVisit[1] = true;
	
	while (!qu.empty()) {

		int ct = qu.front().first;
		long long pay = qu.front().second;
		qu.pop();

		for (int i = 0; i < graph[ct].size(); i++) {
			int next = graph[ct][i];
			if (city[next] != -1) {
				if (city[next] && dist[next] > pay + q) { // 위험 도시면
					qu.push({ next, pay + q });
					dist[next] = pay + q;
				}
				else if(!city[next] && dist[next] > pay+ p) { // 안전 도시
					qu.push({ next, pay + p });
					dist[next] = pay + p;
				}
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> s;
	cin >> p >> q;

	for (int i = 1;i <= n; i++)
		dist[i] = LONG_MAX;

	while (k--) {
		int temp;
		cin >> temp;
		infect.push_back(temp);
		city[temp] = -1;
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	danger();
	find_path();
	if (!city[n]) cout << dist[n] - p << "\n";
	else cout << dist[n] - q << "\n";

	return 0;
}
