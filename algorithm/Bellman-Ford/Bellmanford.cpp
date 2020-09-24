#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

/* 
   Node의 개수 = n
   탐색 => n-1번만큼만 탐색하여 출발 노드로부터 다른 모든 노드로 가는 거리를 Dist[]에 update

   n번째 탐색할 때 dist[]의 요소가 하나라도 새롭게 갱신되는것이 있다면 
   => 음의 사이클이 존재하는 것.
   
*/ 

struct edge {
	int from;
	int to;
	int cost;
};

int n;
int Dist[101];
vector<edge> v;

void bellman_ford(int st) {
	Dist[st] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < v.size(); j++) {
			int from = v[j].from;
			int to = v[j].to;
			int cost = v[j].cost;

			if (Dist[from] == INF) continue;
			if (Dist[to] > Dist[from] + cost) Dist[to] = Dist[from] + cost;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int from = v[i].from;
		int to = v[i].to;
		int cost = v[i].cost;
		if (Dist[from] == INF) continue;
		if (Dist[to] > Dist[from] + cost) {
			cout << "음수 cycle 존재";
			return;
		}
	}
	cout << "Cycle이 존재하지 않는 그래프\n";
	return;
}

int main(void) {


	return 0;
}
