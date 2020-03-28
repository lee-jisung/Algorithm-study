#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <map>
#include <cmath>

#define SIZE 200001
#define INF 987654321

using namespace std;

int tc, f;
int parent[SIZE], fcnt[SIZE];

/*
  단순히 union-find를 해서 부모가 같은것들끼리 count를 해서 출력--> time out
  합칠때 친구의 누적 수를 계산하여 바로 출력해주면 됨
*/

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

// 가장 작은 숫자의 부모쪽으로 친구 수를 계속 누적시켜주는것
int merge(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
		fcnt[a] += fcnt[b];
		fcnt[b] = 1;
		return fcnt[a];
	}
	else if(a > b) {
		parent[a] = b;
		fcnt[b] += fcnt[a];
		fcnt[a] = 1;
		return fcnt[b];
	}
	return fcnt[b];
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> tc;
	while (tc--) {
		map<string, int> name;
		string s1, s2;
		int cnt = 1;

		cin >> f;
		for (int i = 0; i < f * 2; i++) {
			parent[i] = i;
			fcnt[i] = 1;
		}

		for (int i = 0; i < f; i++) {
			int res = 0;
			cin >> s1 >> s2;
			if (name.count(s1) == 0) name.insert({ s1, cnt++ });
			if (name.count(s2) == 0) name.insert({ s2, cnt++ });

			cout << merge(name[s1], name[s2]) << "\n";
		}
	}
	
	return 0;
}
