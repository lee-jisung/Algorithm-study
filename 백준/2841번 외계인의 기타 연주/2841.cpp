#include <iostream>
#include <stack>

using namespace std;

/*
   1 ~ 6 번 줄 마다 stack을 선언해서 fret 번호 관리
   
   1. 비어있거나, 번호가 높은것이 들어오면 push (움직임 +1)
   2. 번호가 낮은것이 들어오면 번호가 같거나 더 낮은 수가 나올때 까지 pop (움직임 => pop 한 수 만큼 +)
   3. 번호가 같다면 pass
*/

int n, p, result;
stack<int> st[7];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int line, fret; cin >> line >> fret;
		if (st[line].empty()) {
			st[line].push(fret);
			result++;
		}
		else if (st[line].top() < fret) {
			st[line].push(fret);
			result++;
		}
		else if (st[line].top() > fret) {
			while (!st[line].empty()) {
				if (st[line].top() <= fret) break;
				st[line].pop();
				result++;
			}
			if (!st[line].empty() && st[line].top() == fret) continue;
			else {
				st[line].push(fret);
				result++;
			}
		}
		else if (st[line].top() == fret) continue;
	}
	cout << result << "\n";
	return 0;
}
