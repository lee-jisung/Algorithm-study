#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 401
#define INF 987654321

using namespace std;

int n, m; 
vector<int> v[SIZE];
bool isVisit[SIZE], ck;

/*
  단방향 그래프로 node 연결
  사건을 a, b로 입력 받았을 때 dfs(a,b)를 통해서 true가 되면 a가 먼저 일어난 것
  반대로 dfs(b, a)일 경우 b가 먼저 일어난 것
  둘다 아닐 경우 관계 없는 사건
*/

void dfs(int x, int b) {

	isVisit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (y == b) {
			ck = true;
			return;
		}
		if (!isVisit[y]) {
			dfs(y, b);
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		memset(isVisit, false, sizeof(isVisit)); ck = false;
		dfs(a, b);
		if (ck) {
			cout << -1 << "\n";
			continue;
		}
		memset(isVisit, false, sizeof(isVisit)); ck = false;
		dfs(b, a);
		if (ck) {
			cout << 1 << "\n";
		}
		else
			cout << 0 << "\n";
	}

	return 0;
}
