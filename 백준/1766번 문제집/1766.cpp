#include <iostream>
#include <vector>
#include <queue>

#define SIZE 32001

using namespace std;

/*
   min heap -> 간선이 없는 문제들을 push해서 가장 숫자가 적은 것 부터 출력
*/

int n, m;
int inDegree[SIZE], result[SIZE];
vector<int> problem[SIZE];
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		problem[a].push_back(b);
		inDegree[b]++;
	}

	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) pq.push(i);

	for (int i = 1; i <= n; i++) {
		
		int no = pq.top();
		pq.pop();
		result[i] = no;

		for (int j = 0; j < problem[no].size(); j++) {
			int nextNo = problem[no][j];
			if (--inDegree[nextNo] == 0) pq.push(nextNo);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << " ";
	cout << "\n";

	return 0;
}
