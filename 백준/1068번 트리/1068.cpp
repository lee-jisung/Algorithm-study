#include <iostream>
#include <vector>

using namespace std;

/*
   1. Tree의 Node를 지웠으면 그 이하로 탐색 X
   2. tree의 중간 node의 자식이 1개였는데, 해당 자식 노드가 지워진경우 중간 node가 leafnode가 됨 =>count해줘야함
*/

int n, leafNode, removeNode;
bool isRemove[51];
vector<int> graph[51], rootNode;

void getLeaf(int no) {
	if (isRemove[no]) return;
	if (graph[no].empty() || (graph[no].size() == 1 && isRemove[graph[no][0]])) {
		leafNode++;
		return;
	}
	for (int i = 0; i < graph[no].size(); i++)
		getLeaf(graph[no][i]);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num == -1) {
			rootNode.push_back(i);
			continue;
		}
		graph[num].push_back(i);
	}
	cin >> removeNode;
	isRemove[removeNode] = true;

	for (int i = 0; i < rootNode.size(); i++)
		getLeaf(rootNode[i]);

	cout << leafNode << "\n";

	return 0;
}
