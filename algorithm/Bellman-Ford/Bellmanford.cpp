#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

/* 
   Node의 개수 = n
   탐색 => n-1번만큼만 탐색하여 출발 노드로부터 다른 모든 노드로 가는 거리를 Dist[]에 update

   n번째 탐색할 때 dist[]의 요소가 하나라도 새롭게 갱신되는것이 있다면 
   => 음의 사이클이 존재하는 것.
   
   
    단순 그래프 => 사이클 유무 파악할때 Dist[]의 값을 어떤값으로 초기화해도 상관없음
    => 거리를 구하는 것이 아닌 음의 사이클이 존재할 때, 변화만 파악하기 때문

  dist[from]이 INF라서 지나치게 되면 , 뒤에 있는 cycle의 유무를 판단할 수 없게 됨

  만약 단절이 된 경우라면 dist[from]은 INF일테고, 단절된 정점끼리 cycle을 형성했다면? 

  cycle은 형성되었지만, 문제에서의 cycle 유무는 알수가없음 =>이유는 1에서만 조사를 하기 때문

  세 정점 1, 2, 3 이고, 간선이 두 개
  2 3 -1
  3 2 -1
  인 경우
   
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
