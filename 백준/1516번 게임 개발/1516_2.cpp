#include <iostream>
#include <queue>
#include <vector>

#define SIZE 501

using namespace std;

/*
   time complexity = O(V+E)
   1. 진입 차수가 0인 정점을 큐에 삽입 -> 시작 노드가 됨
   2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거
   3. 간선 제거 이후 진입 차수가 0이 된 정점을 큐에 삽입
   4. 큐가 빌 때 까지 2~3번의 과정을 반복, 
     4 - 1모든 원소를 방문하기 전 큐가 빈다면 사이클이 존재하는것이고, 
	 4 - 2원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과
*/

int n;
int inDegree[SIZE]; // 각 노드로 들어오는 간선의 개수
int result[SIZE], time[SIZE];
vector<int> graph[SIZE];

void topologySort() {
	queue<int> q;
	//진입 차수 0인 노드 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = time[i];
			q.push(i);
		}
	}
	//위상 정렬이 완전히 수행되려면 정확히 n개 노드를 방문
	for (int i = 1; i <= n; i++) {
		//n개를 방문하기 전 큐가 비면 사이클 발생
		if (q.empty())
			return;
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			result[y] = max(result[y], result[x] + time[y]);
			//새롭게 진입 차수가 0이 된 노드를 큐에 삽입
			if (--inDegree[y] == 0) q.push(y);
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, cnt = 0;
		while (1) {
			cin >> a; if (a == -1) break;
			cnt++;
			if (cnt == 1)
				time[i] = a;
			else {
				graph[a].push_back(i);
				inDegree[i]++;
			}
		}
	}

	topologySort();

	for (int i = 1; i <= n; i++) cout << result[i] << "\n";
	return 0;
}
