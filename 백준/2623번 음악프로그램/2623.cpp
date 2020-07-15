#include <iostream>
#include <vector>
#include <queue>

#define SIZE 1001

using namespace std;

/*
   위상정렬
   각 pd가 정한 순서에 따라 graph와 indegree 추가
   모든 노드를 방문하기 전 q가 빈다면 사이클 존재 -> 순서 정할 수 없음
*/

int n, m;
int inDegree[SIZE];
vector<int> seq[SIZE], result;
queue<int> q;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a; 
		cin >> a;
		vector<int> tmp(a);
		for (int j = 0; j < a; j++) cin >> tmp[j];
		for (int j = 0; j < tmp.size() - 1;j++) {
			seq[tmp[j]].push_back(tmp[j + 1]);
			inDegree[tmp[j + 1]]++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (inDegree[i] == 0) q.push(i);

	for (int i = 1;i <= n; i++) {
		if (q.empty()) {
			cout << 0 << "\n";
			return 0;
		}

		int no = q.front();
		q.pop();
		result.push_back(no);

		for (int j = 0; j < seq[no].size(); j++) {
			int nextNo = seq[no][j];
			if (--inDegree[nextNo] == 0) q.push(nextNo);
		}
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "\n";
	}

	return 0;
}
