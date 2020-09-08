#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
	int idx;
	int r, c;
};

vector<node> info;
vector<node> graph[10001];
vector<int> v;
node root;

void init() {
	node tmp = { -1, -1, -1 };
	for (int i = 0; i < 10001;i++) {
		graph[i].push_back(tmp);
		graph[i].push_back(tmp);
	}
}

bool cmp(node v1, node v2) {
	if (v1.r == v2.r)
		return v1.c < v2.c;
	return v1.r > v2.r;
}

void insertTree(node rot, node candi) {
	if (candi.c < rot.c && graph[rot.idx][0].idx == -1) {
		graph[rot.idx][0].idx = candi.idx;
		graph[rot.idx][0].r = candi.r;
		graph[rot.idx][0].c = candi.c;
		return;
	}
	else if (candi.c < rot.c && graph[rot.idx][0].idx != -1) {
		node tmp = { graph[rot.idx][0].idx, graph[rot.idx][0].r, graph[rot.idx][0].c };
		insertTree(tmp, candi);
	}
	else if (candi.c > rot.c && graph[rot.idx][1].idx == -1) {
		graph[rot.idx][1].idx = candi.idx;
		graph[rot.idx][1].r = candi.r;
		graph[rot.idx][1].c = candi.c;
		return;
	}
	else if (candi.c > rot.c && graph[rot.idx][1].idx != -1) {
		node tmp = { graph[rot.idx][1].idx, graph[rot.idx][1].r, graph[rot.idx][1].c };
		insertTree(tmp, candi);
	}
}

void preorder(node nd) {
	if (nd.idx != -1) {
		v.push_back(nd.idx);
		preorder(graph[nd.idx][0]);
		preorder(graph[nd.idx][1]);
	}
}

void postorder(node nd) {
	if (nd.idx != -1) {
		postorder(graph[nd.idx][0]);
		postorder(graph[nd.idx][1]);
		v.push_back(nd.idx);
	}
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

	vector<vector<int>> answer;

	for (int i = 0; i < nodeinfo.size(); i++)
		info.push_back({ i + 1, nodeinfo[i][1], nodeinfo[i][0] });

	sort(info.begin(), info.end(), cmp);
	init();
	root = info[0];
	for (int i = 1; i < info.size(); i++) {
		insertTree(root, info[i]);
	}

	preorder(root); answer.push_back(v); v.clear();
	postorder(root); answer.push_back(v);
	return answer;
}


int main(void) {

	vector<vector<int>> infos{
		{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6,1}, {1,3}, {8,6}, {7, 2}, {2, 2}
	};

	solution(infos);

	return 0;
}
