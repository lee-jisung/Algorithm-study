#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 6;
int INF = 1000000000;

vector<pair<int, int >> a[7]; // 간선 정보 (연결된 정점, 비용)
int dist[7]; // 최소비용

void dijkstra(int start) {
	dist[start] = 0;
	//priority_queue<pair<int, int >> pq; // 힙구조 -> 기본 구조가 max heap
	priority_queue<pair<int, int >, vector<pair<int, int> >, greater<pair<int,int>> > pq; //-> 이렇게 선언하면 음수화 할 필요 없음
	pq.push({ 0, start });
	//가까운 순서대로 처리
	while (!pq.empty()) {

		//짧은 것이 먼저 오도록 음수화(-) 
		//int distance = -pq.top().first;
		int distance = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		//최단거리가 아닌 경우 스킵
		if (dist[current] < distance) continue;
		for (int i = 0; i < a[current].size(); i++) {
			//선택된 노드의 인접 노드
			int next = a[current][i].second;
			//선택된 노드를 거쳐 인접 노드로 가는 비용
			int nextDistance = distance + a[current][i].first;
			//기존의 최소 비용 보다 더 저렴하다면 교체
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push({ nextDistance, next });
			}
		}
	}
}

int main(void) {
	// 기본적으로 연결 되지 않은 경우 비용 무한
	for (int i = 1; i <= number; i++) {
		dist[i] = INF;
	}
	a[1].push_back({ 2, 2 });
	a[1].push_back({ 5, 3 });
	a[1].push_back({ 1, 4 });

	a[2].push_back({ 2, 1 });
	a[2].push_back({ 3, 3 });
	a[2].push_back({ 2, 4 });

	a[3].push_back({ 5, 1 });
	a[3].push_back({ 3, 2 });
	a[3].push_back({ 3, 4 });
	a[3].push_back({ 1, 5 });
	a[3].push_back({ 5, 6 });

	a[4].push_back({ 1, 1 });
	a[4].push_back({ 2, 2 });
	a[4].push_back({ 3, 3 });
	a[4].push_back({ 1, 5 });

	a[5].push_back({ 1, 3 });
	a[5].push_back({ 1, 4 });
	a[5].push_back({ 2, 6 });

	a[6].push_back({ 5, 3 });
	a[6].push_back({ 2, 5 });

	dijkstra(1);

	for (int i = 1; i <= number;i++) {
		cout << dist[i] << " ";
	}


	return 0;
}
