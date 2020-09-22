#include <iostream>
using namespace std;

/*
	반례 => 같은 그룹은 아니지만 서로의 반지름 상 원이 겹칠 수 있는 경우도 한그룹으로 치기 떄문에
		 parent의 개수로 카운트를 하면안되고 두 점이 통신가능한 거리 상에 있을 때 그룹의 개수를 줄여줘야 함
		1
		4
		0 0 1
		0 4 1
		0 1 1
		0 3 1
*/
struct base {
	int x, y, r;
};

int T, n;
int parent[3001];

int findParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		base enemy[3001];

		for (int i = 0; i < n; i++) {
			int x, y, r; cin >> x >> y >> r;
			enemy[i] = { x, y, r };
			parent[i] = i;
		}
		int cnt = n;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {

				int x = enemy[j].x - enemy[i].x;
				int y = enemy[j].y - enemy[i].y;
				int r = enemy[i].r + enemy[j].r;

				int area = x * x + y * y;
				if (area <= r * r) {
					if (findParent(i) != findParent(j)) {
						unionParent(i, j);
						cnt--;
					}
				}
			}
		}

		//반례 틀림
		//set<int> s;
		//for (int i = 0; i < n; i++) {
		//	s.insert(parent[i]);
		//}
		//cout << s.size() << "\n";

		cout << cnt << "\n";
	}

	return 0;
}
