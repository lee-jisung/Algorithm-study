#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 201
#define INF 987654321

using namespace std;

int n, m; 
int parent[SIZE], arr[SIZE][SIZE];
bool flag = true;
vector<int> city;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	else return false;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		parent[i] = i;

	// 행렬로 주어진 경로 --> 1이면 union
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				unionParent(i + 1, j + 1);
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		city.push_back(temp);
	}

	// 여행 목적지에서 이어지지 않는 경로가 존재 --> 여행 불가능
	for (int i = 0; i < city.size() - 1; i++)
		if (!findParent(city[i], city[i + 1])) 
			flag = false;

	if (flag) cout << "YES\n";
	else cout << "NO\n";


	return 0;
}
