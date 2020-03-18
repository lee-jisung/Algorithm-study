#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 101
#define INF 987654321

using namespace std;

struct pos {
	int x;
	int y;
};

int tc, n, m; 
int curx, cury, fesx, fesy;
bool isVisit[SIZE], res;
pos convenient[SIZE];

// 편의점에 대한 방문 처리

// 현재 위치 -> 거리가 1000 이하인 편의점이 존재 -> 큐에 넣고 bfs
// 매 위치에서 목표지점까지 거리가 1000이하면 true
// 모든 편의점을 다 돌아도 목표까지 거리가 1000 이하가 없으면 false

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> tc;

	while (tc--) {

		memset(isVisit, false, sizeof(isVisit));
		res = false;

		cin >> n;
		cin >> curx >> cury;
		for (int i = 0; i < n; i++)
			cin >> convenient[i].x >> convenient[i].y;
		cin >> fesx >> fesy;

		queue<pos> q;
		q.push({ curx, cury });
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			if (abs(x - fesx) + abs(y - fesy) <= 1000) {
				res = true;
				break;
			}
				
			for (int i = 0; i < n; i++) {
				if (!isVisit[i] && abs(x - convenient[i].x) + abs(y - convenient[i].y) <= 1000) {
					q.push({ convenient[i].x, convenient[i].y });
					isVisit[i] = true;
				}
			}

		}

		if (res) cout << "happy\n";
		else cout << "sad\n";

	}

	return 0;
}
