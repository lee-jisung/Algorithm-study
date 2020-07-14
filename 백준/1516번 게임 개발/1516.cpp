#include <iostream>
#include <vector>
#include <queue>

#define SIZE 501

using namespace std;

int n;
int build[SIZE], time[SIZE], inDegree[SIZE];
vector<int> graph[SIZE];
queue<pair<int, int>> q;

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
				build[i] = a;
			else {
				graph[a].push_back(i);
				inDegree[i]++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) q.push({ i, 0 });

	for (int i = 1; i <= n; i++) {
		int no = q.front().first;// 새로 지을 건물 번호
		int t = q.front().second;// 현재 까지 건물을 지은 시간
		q.pop();
		// if (q.empty()) exit(0); // cycle

		// 이전 건물을 짓는데 걸리는 시간보다 현재 짓는 시간이 더 오래 걸린다면 갱신
		if (time[no] < build[no] + t) time[no] = build[no] + t;

		for (int j = 0; j < graph[no].size(); j++) {
			int newNo = graph[no][j];
			// 간선이 모두 없어지는 경우 새로운 건물 번호와 현재까지 지은 시간을 q에 push
			if (--inDegree[newNo] == 0) q.push({ newNo, time[no] });
			// 간선이 아직 남아 있는 경우 
			// (새로운 건물 짓는 시간 + 현재까지 온 시간) 이 기존에 새로 짓는 건물 시간보다 오래 걸리는 경우가 있으면 갱신
			else {
				if (time[newNo] < time[no] + build[newNo])
					time[newNo] = time[no] + build[newNo];
			}
		}
	}

	for (int i = 1; i <= n; i++)
		cout << time[i] << "\n";

	return 0;
}
