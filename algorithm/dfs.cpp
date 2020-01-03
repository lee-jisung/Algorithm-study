#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[10];
bool check[10];

void dfs(int x) {

	check[x] = true;
	cout << x << "\n";
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!check[y]) {
			dfs(y);
		}
	}

}

int main(void) {

	graph[1].push_back(2);
	graph[2].push_back(1);
	graph[1].push_back(3);
	graph[3].push_back(1);
	graph[1].push_back(4);
	graph[4].push_back(1);

	graph[2].push_back(5);
	graph[5].push_back(2);
	
	graph[3].push_back(6);
	graph[6].push_back(3);
	graph[3].push_back(7);
	graph[7].push_back(3);
	graph[6].push_back(9);
	graph[9].push_back(6);

	graph[4].push_back(8);
	graph[8].push_back(4);


	dfs(1);


}
