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


// 물통 3가지 경우로 나눠서 방문 처리해서 확인
// isVisit[a][b][c] 식으로

using namespace std;

struct node {
	int a, b, c;
};

int A, B, C;
vector<int> v;
bool isVisit[SIZE][SIZE][SIZE];

void bfs() {
	
	queue<node> q;
	q.push({ 0, 0, C });

	while (!q.empty()) {

		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if (isVisit[a][b][c]) continue;
		isVisit[a][b][c] = true;

		if (a == 0) {
			v.push_back(c);
		}

		// A -> B
		if (a + b > B) q.push({ a + b - B, B, c });
		else q.push({ 0, a + b, c });

		// A -> C
		if (a + c > C) q.push({ a + c - C, b, C });
		else q.push({ 0, b, a + c });

		// B -> A
		if (b + a > A) q.push({ A, b + a - A, c });
		else q.push({ b + a, 0, c });

		// B -> C
		if (b + c > C) q.push({ a, b + c - C, C });
		else q.push({ a, 0, b + c });

		// C -> A 
		if (c + a > A) q.push({ A, b, c + a - A });
		else q.push({ c + a, b, 0 });

		// C -> B
		if (c + b > B) q.push({ a, B, c + b - B });
		else q.push({ a, c + b, 0 });
	}
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> A >> B >> C;

	bfs();

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";

	return 0;
}
