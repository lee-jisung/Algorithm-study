#include <iostream>
#include <vector>

/*
   전위 순회 결과 노드들을 하나씩 받아서 insertTree 함수에 넣어 tree에 insert함
   완성된 tree를 이용해서 postorder로 출력
*/

using namespace std;
int rootNode;
pair<int, int>  graph[1000001];

void insertTree(int root, int num) {

	if (root > num) {
		if (graph[root].first == 0) {
			graph[root].first = num;
			return;
		}
		insertTree(graph[root].first, num);
	}
	else if (root < num) {
		if (graph[root].second == 0) {
			graph[root].second = num;
			return;
		}
		insertTree(graph[root].second, num);
	}
}

void postOrder(int root) {
	if (graph[root].first != 0)
		postOrder(graph[root].first);
	if (graph[root].second != 0)
		postOrder(graph[root].second);
	cout << root << "\n";
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	cin >> rootNode;
	while (cin >> num) {
		insertTree(rootNode, num);
	}

	postOrder(rootNode);

	return 0;
}
