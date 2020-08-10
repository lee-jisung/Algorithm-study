#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <tuple>

#define INF 1e9

/* 
  모든 행성에 대하여 거리를 계산하여 graph를 만들고 정렬하여 계산 -> 메모리 초과 

  두 행성의 터널 비용이 min(|xA-xB|, |yA-yB|, |zA-zB|)이기 때문에 
  각 행성간의 거리를 x, y, z 각각의 좌표로 정렬한 후
  i, i+1의 행성에 대하여 정렬한 좌표 값 abs(x1 -x2)로 비용을 계산하여 graph에 psuh

  graph를 정렬하여 kruskal을 적용
*/

using namespace std;

struct STAR {
	int no, x, y, z;
};
struct TURNEL {
	int cost, n1, n2;
};

int n, result;
int parent[100001];
vector<STAR> star;
vector<TURNEL> graph;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

bool cmpX(STAR a, STAR b) {
	return a.x < b.x;
}

bool cmpY(STAR a, STAR b) {
	return a.y < b.y;
}

bool cmpZ(STAR a, STAR b) {
	return a.z < b.z;
}

bool cmpG(TURNEL a, TURNEL b) {
	return a.cost < b.cost;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		int x, y, z; cin >> x >> y >> z;
		star.push_back({ i, x, y, z });
	}

	sort(star.begin(), star.end(), cmpX);
	for (int i = 0;i < star.size() - 1; i++) {
		graph.push_back({ abs(star[i + 1].x - star[i].x), star[i].no, star[i+1].no });
	}
	sort(star.begin(), star.end(), cmpY);
	for (int i = 0;i < star.size() - 1; i++) {
		graph.push_back({ abs(star[i + 1].y - star[i].y), star[i].no, star[i + 1].no });
	}
	sort(star.begin(), star.end(), cmpZ);
	for (int i = 0;i < star.size() - 1; i++) {
		graph.push_back({ abs(star[i + 1].z - star[i].z), star[i].no, star[i + 1].no });
	}

	sort(graph.begin(), graph.end(), cmpG);

	for (int i = 0; i < graph.size(); i++) {
		int cost = graph[i].cost;
		int n1 = graph[i].n1;
		int n2 = graph[i].n2;

		if (!findParent(n1, n2)) {
			unionParent(n1, n2);
			result += cost;
		}
	}

	cout << result << "\n";

	return 0;
}
