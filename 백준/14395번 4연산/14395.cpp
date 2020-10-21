#include <iostream>
#include <queue>
#include <map>

using namespace std;

/*
   +, *, / 일 경우만 고려 => s - s인 경우는 무조건 0이 되기 때문에 고려 x
   /의 경우 s / s는 1이 되므로 무조건 1은 한번만 방문하면 되기 때문에
   divide boolean 변수를 두어서 1을 방문처리하면 그 이후 안하게 만듦
*/

struct Node {
	long long num;
	string operand;
};

long long s, t;
bool isAvail;
map<int, bool> visit;

void bfs() {
	queue<Node> q;
	q.push({ s, "" });
	visit[s] = true;
	bool divide = true;

	while (!q.empty()) {
		long long num = q.front().num;
		string op = q.front().operand;
		q.pop();
		if (num == t) {
			cout << op << "\n";
			isAvail = true;
			return;
		}
		long long tmp = num * num;
		if (tmp <= t && !visit.count(tmp)) {
			q.push({ tmp, op + '*'});
			visit[tmp] = true;
		}

		tmp = num + num;
		if (tmp <= t && !visit.count(tmp)) {
			q.push({ tmp, op  + '+'});
			visit[tmp] = true;
		}

		// s / s 일때는 1이 한번만 등장하면 되기 때문에 divde인 boolean으로 처린
		if (divide) {
			q.push({ 1, op + '/' });
			divide = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s >> t;

	if (s == t)
		cout << 0 << "\n";
	else {
		bfs();
		if (!isAvail) cout << -1 << "\n";
	}
	return 0;
}
