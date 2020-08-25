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
#define SIZE 10001

/*
   indegree가 0개인것을 queue에 넣고 탐색
   연결되어 있는 점들을 탐색하면서 시간 갱신
   ** 선행관계가 모두 없는 경우들도 존재할 수 있음
   => 1~n까지 돌면서 최대 시간을 찾아 결과로 도출
*/

using namespace std;

typedef pair<int, int> PAIR;
typedef tuple<int, int, int> TUPLE;

int n, m, res;
int inDegree[SIZE], time[SIZE], result[SIZE];
vector<int> graph[SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		time[i] = a;
		for (int j = 0; j < b; j++) {
			cin >> m;
			graph[m].push_back(i);
			inDegree[i]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) 
		if (inDegree[i] == 0) {
			q.push(i);
			result[i] = time[i];
		}

	for (int i = 1; i <= n; i++) {
		int cur = q.front();
		q.pop();
		

		for (int j = 0; j < graph[cur].size(); j++) {
			int nxt = graph[cur][j];
			result[nxt] = max(result[nxt], result[cur] + time[nxt]);
			if (--inDegree[nxt] == 0) q.push(nxt);
		}
	}

	for (int i = 1;i <= n; i++) {
		res = max(res, result[i]);
	}

	cout << res << "\n";

	return 0;
}
