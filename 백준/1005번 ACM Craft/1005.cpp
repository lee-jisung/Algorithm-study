#include <iostream>
#include <vector>
#include <queue>

#define SIZE 1001

using namespace std;

int tc, n, k, w;
int time[SIZE];
int build[SIZE], inDegree[SIZE];
vector<int> graph[SIZE];
queue<pair<int,int>> q;

void init() {
	for (int i = 0; i < SIZE;i++) {
		inDegree[i] = 0;
		graph[i].clear();
		time[i] = 0;
	}
	while (!q.empty()) q.pop();
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> tc;

	while (tc--) {

		cin >> n >> k;
		init();
		for (int i = 1; i <= n; i++) cin >> build[i];
		for (int i = 0; i < k; i++) {
			int x, y; cin >> x >> y;
			graph[x].push_back(y);
			inDegree[y]++;
		}
		cin >> w;

		for (int i = 1; i <= n; i++)
			if (inDegree[i] == 0) q.push({ i, 0 });

		for (int i = 1; i <= n; i++) {
			int building = q.front().first; // 새로 지을 건물 번호
			int t = q.front().second; // 현재 까지 건물을 지은 시간
			q.pop();
			int newTime = build[building] + t;
			// 이전에 새로 짓는 건물이 걸리는 시간 보다 더 긴 시간이 걸리는 경우가 있으면 갱신
			if (time[building] < newTime) time[building] = newTime;

			for (int j = 0; j < graph[building].size(); j++) {
				int newBuilding = graph[building][j];

				// 간선이 모두 없어지는 경우 새로운 건물 번호와 현재까지 지은 시간을 q에 push
				if (--inDegree[newBuilding] == 0) q.push({ newBuilding, time[building] }); 
				// 간선이 아직 남아 있는 경우 
				// (새로운 건물 짓는 시간 + 현재까지 온 시간) 이 새로 짓는 건물 시간보다 오래 걸리는 경우가 있으면 갱신
				else { 
					if (time[newBuilding] < time[building] + build[newBuilding])
						time[newBuilding] = time[building] + build[newBuilding];
				}
			}
		}
		cout << time[w] << "\n";
	}


	return 0;
}
