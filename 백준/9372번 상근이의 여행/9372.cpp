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

using namespace std;

int tc, n, m; 
vector<int> v[SIZE];

// 최소 신장 트리 --> 모든 정점이 간선의 가중치가 가장 최소로 연결되는 그래프
// 여기서는 모든 간선의 가중치가 동일하다면 간선의 최소값은 당연 정점 개수 - 1임
// 따라서 n-1....

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> tc;
	while (tc--) {

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}

		cout << n-1 << "\n";
		
	}
	return 0;
}
