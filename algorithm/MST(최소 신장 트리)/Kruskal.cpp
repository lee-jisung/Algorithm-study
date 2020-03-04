#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 10001
#define INF 987654321

/*
   Kruskal Algorithm
   정점을 최소한의 간선 개수로 연결 -> 간선 개수 = 정점 개수 - 1
   간선 오름차순으로 정렬 -> 순차적으로 간선을 선택하면서 사이클 발생 여부 확인
   --> 사이클을 형성하는 간선일 경우 제외 --> union-find 적용
   --> 간선 개수가 정점 개수 - 1 이면 종료
*/

using namespace std;

struct node {
    int node1;
    int node2;
    int weight;
};

int v, e, node1, node2, weight;
int parent[SIZE], result;
vector<node> graph;

bool cmp(node n1, node n2) {
    return n1.weight < n2.weight;
}

// 부모 노드를 찾는 함수
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

// 두 노드를 합치는 함수 (가장 작은 수를 부모노드로 갖음)
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모를 가지는지 확인
int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return 1;
    return 0;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    // v - 정점 개수, e - 간선 개수
    cin >> v >> e;
    
    // 최초 각각의 정점은 자신을 부모로 가짐
    for (int i = 1; i <= v; i++)
        parent[i] = i;

    // 간선 개수만큼 연결되어있는 정점과 가중치를 저장
    while (e--) {
        cin >> node1 >> node2 >> weight;
        graph.push_back({ node1, node2, weight });
    }
    // 가중치 기준 오름차순으로 정렬
    sort(graph.begin(), graph.end(), cmp);

    // 정렬된 간선의 정보중 
    for (int i = 0; i < graph.size(); i++) {
        node temp = graph[i];
        //아직 연결이 되어 있지 않은 두 노드에 대하여 연결 후 가중치를 더해줌 (사이클도 걸러지게 됨)
        if (!findParent(temp.node1, temp.node2)) {
            unionParent(temp.node1, temp.node2);
            result += temp.weight;
        }
    }
   
    cout << result << "\n";

	return 0;
}
