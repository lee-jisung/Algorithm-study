#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

#define SIZE 51
#define INF 1e9

using namespace std;

int n, cnt, result;

int adj[SIZE][SIZE];

bool isVisit[SIZE];
vector<int> graph[SIZE];

void bfs(int no) {
	queue<pair<int, int>> q;
	q.push({ no, 0 });
	isVisit[no] = true;

	while (!q.empty()) {
		int idx = q.front().first;
		int depth = q.front().second;
		q.pop();
		
		if (depth == 2) continue;

		for (int i = 0; i < graph[idx].size(); i++) {
			int next = graph[idx][i];
			if (!isVisit[next]) {
				isVisit[next] = true;
				q.push({ next, depth + 1 });
				cnt++;
			}
		}
	}
}

void floyd() {

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0;j < n; j++) {
				if (i == j || j == k || i == k) continue;
				if (adj[i][j] >= adj[i][k] + adj[k][j]) {
					adj[i][j] = adj[i][k] + adj[k][j];
				}
			}
		}
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	//// graph
	//for (int i = 1; i <= n; i++) {
	//	string temp; cin >> temp;
	//	for (int j = 0;j < temp.length(); j++) {
	//		if (temp[j] == 'Y')
	//			graph[i].push_back(j+1);
	//	}
	//}

	//for (int i = 1; i <= n; i++) {
	//	memset(isVisit, false, sizeof(isVisit));
	//	cnt = 0;
	//	bfs(i); cout << "\n\n";
	//	result = max(result, cnt); 
	//}

	//cout << result << "\n";

	// floyd
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		for (int j = 0; j < temp.length(); j++) {
			if (i == j) adj[i][j] = INF;
			else if (temp[j] == 'Y') adj[i][j] = 1;
			else if (temp[j] == 'N') adj[i][j] = INF;
		}
	}

	floyd();

	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			else if (adj[i][j] <= 2) cnt++;
		}
		result = max(result, cnt);
	}

	cout << result << "\n";

	return 0;
}
