#include <iostream>
#include <vector>
#include <cstring>

#define INF 1e9

using namespace std;

/*
   Node의 개수 = V
   탐색 => V-1번만큼만 탐색할 것

   단순 그래프 => 사이클 유무 파악할때 Dist[]의 값을 어떤값으로 초기화해도 상관없음
    => 거리를 구하는 것이 아닌 음의 사이클이 존재할 때, 변화만 파악하기 때문

  dist[from]이 INF라서 지나치게 되면 , 뒤에 있는 cycle의 유무를 판단할 수 없게 됨

  만약 단절이 된 경우라면 dist[from]은 INF일테고, 단절된 정점끼리 cycle을 형성했다면? 

  cycle은 형성되었지만, 문제에서의 cycle 유무는 알수가없음 =>이유는 1에서만 조사를 하기 때문

  세 정점 1, 2, 3 이고, 간선이 두 개
  2 3 -1
  3 2 -1
  인 경우

  1 / 2 <=>3
*/

struct edge {
	int from;
	int to;
	int cost;
};

int tc, n, m, w;
int Dist[501];
vector<edge> v;

bool bellman_ford(int st) {
	Dist[st] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].from;
			int to = v[j].to;
			int cost = v[j].cost;
			//if(Dist[from] == INF) continue;
			if (Dist[to] > Dist[from] + cost) {
				Dist[to] = Dist[from] + cost;
				if (i == n) return false;
			}
		}
	}
	return true;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {

		cin >> n >> m >> w;

		for (int i = 1; i <= n; i++) Dist[i] = -1;
		v.clear();


		for (int i = 0; i < m; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			v.push_back({ from, to, cost });
			v.push_back({ to, from, cost });
		}
		for (int i = 0; i < w; i++) {
			int from, to, cost;
			cin >> from >> to >> cost;
			v.push_back({ from, to, -cost });
		}

		if (bellman_ford(1)) cout << "NO\n";
		else cout << "YES\n";

		/* 모든 정점에 대해서 조사하면 시간초과

		bool isCycle = false;
		for (int i = 1;i <= n; i++)
			isCycle = bellman_ford(i);

		if (!isCycle) cout << "NO\n";
		else cout << "YES\n";
		*/
	}
	return 0;
}
