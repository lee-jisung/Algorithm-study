#include <iostream>
#include <queue>

#define SIZE 501

/*
   작년 순위를 기준으로 인접 배열(graph)을 형성
   높은 순위에서 낮은 순위로 갈 수 있는 경우를 모두 check
   ex) 5 - 4 - 3 - 2 - 1의 순위일 경우 adj[5][4], adj[5][3], ... , adj[5][1] = true

   순위가 뒤바뀐 경우를 체크할 때,
   a, b가 들어오면 작년 기준 순위가 바뀐 것이기 때문에
   adj[a][b]와 adj[b][a]를 각각 반대로 만들어 주고, inDegree도 각각 반대로 증감

   위상 정렬에서 q가 비었을 때는 cycle이 존재하므로 impossible을
   q의 크기가 1 이상일 경우 동일 한 순위가 여러 팀이 있다는 얘기 이므로 ?를
   그 외의 경우 순위를 출력

*/

using namespace std;

int tc;
int n, m;
int inDegree[SIZE], ranking[SIZE], result[SIZE];
bool graph[SIZE][SIZE];
queue<int> q;

void init() {
	for (int i = 0; i < SIZE; i++) {
		inDegree[i] = ranking[i] = result[i] = 0;
		for (int j = 0; j < SIZE;j++)
			graph[i][j] = false;
	}
	while (!q.empty()) q.pop();
}

void topology() {
	for (int i = 1; i <= n; i++) if (inDegree[i] == 0) q.push(i);

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << "IMPOSSIBLE\n";
			return;
		}
		if (q.size() > 1) {
			cout << "?\n";
			return;
		}

		int no = q.front();
		q.pop();
		result[i] = no;
		inDegree[no]--;// 이걸 안해주면 0인 node가 계속 유지가 되므로 q size가 1이 무조건 넘어가게 되므로 -1을 만들어줘야함

		for (int j = 1; j <= n; j++) {
			if (graph[no][j]) inDegree[j]--;
			if (inDegree[j] == 0)q.push(j);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";
	cout << "\n";
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	while (tc--) {
		init();
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> ranking[i];

		for (int i = 1; i <= n - 1; i++)
			for (int j = i + 1; j <= n; j++) {
				graph[ranking[i]][ranking[j]] = true;
				inDegree[ranking[j]]++;
			}

		cin >> m;
		while (m--) {
			int a, b; cin >> a >> b;
			if (graph[a][b]) {
				graph[a][b] = false; graph[b][a] = true;
				inDegree[b]--; inDegree[a]++;
			}
			else {
				graph[a][b] = true; graph[b][a] = false;
				inDegree[b]++; inDegree[a]--;
			}
		}

		topology();
	}
	return 0;
}
