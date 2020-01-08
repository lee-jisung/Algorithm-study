#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define SIZE 100

using namespace std;

int check[SIZE];
vector<int> v[SIZE];

void bfs(int a) {

	queue<int> q;
	q.push(a);
	check[a] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << "\n";
		for (int i = 0; i < v[x].size(); i++) {
			
			if (!check[v[x][i]]) {
				q.push(v[x][i]);
				check[v[x][i]] = true;
			}
		}
	}
}

int main(void) {

	v[1].push_back(2);
	v[2].push_back(1);

	v[1].push_back(3);
	v[3].push_back(1);

	v[2].push_back(4);
	v[4].push_back(2);

	v[4].push_back(6);
	v[6].push_back(4);

	v[3].push_back(5);
	v[5].push_back(3);

	v[6].push_back(7);
	v[7].push_back(6);

	bfs(1);

	return 0;
}
