//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//#define MAX 101
//
//using namespace std;
//
//int n, m;
//vector<int> fr[MAX];
//vector<pair<int, int> > result;
//
//// 2644번과 비슷
//// 현재 노드에서 다음 노드로 갈 때 +1을 해주면서 거리 수 update
//// 시작 노드 제외하고 다른 모든 노드의 cache값을 더해주면 거리 수가 나옴
//void bfs(int start) {
//
//	int cache[MAX] = { 0, };
//	int val = 0;
//	queue<int> q;
//	q.push(start);
//
//	while (!q.empty()) {
//		int cur = q.front();
//		q.pop();
//
//		for (int i = 0; i < fr[cur].size(); i++) {
//			int next = fr[cur][i];
//			if (cache[next] == 0) {
//				q.push(next);
//				cache[next] = cache[cur] + 1;
//			}
//		}
//	}
//
//	for (int i = 1; i <= n; i++){
//		if (start == i)
//			continue;
//		val += cache[i];
//	}
//	result.push_back(make_pair(val, start));
//		
//}
//
//int main(void) {
//
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int f1, f2;
//		cin >> f1 >> f2;
//		fr[f1].push_back(f2);
//		fr[f2].push_back(f1);
//
//	}
//
//	for (int i = 1; i <= n; i++) {
//		bfs(i);
//	}
//
//	sort(result.begin(), result.end());
//	cout << result[0].second << "\n";
//
//	return 0;
//}
