#include <iostream>
#include <string>
#include <set>

using namespace std;

// all, empty 명령어에서 set을 clear()하는 연산 or 1 ~20까지 insert하는 연산이 오래 걸려 시간초과가 발생함
// 빈 set, 1 ~ 20 가진 set를 미리 만들어서 대입으로 해결

set<int> s, tmp1, tmp2;;
int M, num;
string cal;

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M;
	for (int i = 1;i <= 20; i++) tmp1.insert(i);

	while (M--) {

		cin >> cal;

		if (!cal.compare("add")) {
			cin >> num;
			if (s.find(num) == s.end()) s.insert(num);
		}
		else if (!cal.compare("remove")) {
			cin >> num;
			if (s.find(num) != s.end()) s.erase(num);
		}
		else if (!cal.compare("check")) {
			cin >> num;
			if (s.find(num) == s.end()) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
		else if (!cal.compare("toggle")) {
			cin >> num;
			if (s.find(num) == s.end()) s.insert(num);
			else s.erase(num);
		}
		else if (!cal.compare("all")) {
			s = tmp1;
		}
		else if (!cal.compare("empty"))
			s = tmp2;
	}

	return 0;
}
