#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100001
#define INF 1e9

using namespace std;

int t;
int n, student[SIZE], cnt;
bool isVisit[SIZE], cycle[SIZE];

void dfs(int x) {

	isVisit[x] = true;
	int sel = student[x];
	if (!isVisit[sel]) dfs(sel); //한번도 방문하지 않았던 곳이면 dfs 처리
	else if (!cycle[sel]) { // 한번 방문했던 곳인데 사이클 처리를 안한 곳이면 해당 노드에서 한 사이클 완료
		for (int i = sel; i != x; i = student[i])
			cnt++; // 연결 된 학생 들 수 count
		cnt++; // 자기 자신 count
	}
	cycle[x] = true; // 방문했던 노드들 최종 방문 처리 

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {

		memset(isVisit, false, sizeof(isVisit));
		memset(cycle, false, sizeof(cycle));
		cnt = 0;

		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> student[i];

		for (int i = 1; i <= n; i++)
			if (!isVisit[i]) dfs(i);

		cout << n - cnt << "\n";
	}
	return 0;
}
