#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

/*
   0 <= i < j < m
*/

struct node {
	string str;
	int depth;
};

int res;
bool isVisit[11][1000001];
int n, k, m;

void bfs() {
	
	queue<node> q;
	q.push({ to_string(n), 0 });
	isVisit[0][n] = true;
	
	while (!q.empty()) {

		string str = q.front().str;
		int num = stoi(str);
		int depth = q.front().depth;
		q.pop();

		if (depth == k) {
			res = max(res, num);
			continue;
		}

		for (int j = 0; j < m; j++) {
			for (int i = j+1; i < m; i++) {
				string s = str;
				swap(s[i], s[j]);
				if (isVisit[depth + 1][stoi(s)] || s[0] == '0') continue;
				isVisit[depth + 1][stoi(s)] = true;
				q.push({ s, depth + 1 });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	string tmp = to_string(n);
	m = tmp.length();
	res = -1;
	bfs();
	cout << res << "\n";

	return 0;
}
