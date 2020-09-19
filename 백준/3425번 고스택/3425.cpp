#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

#define LIMIT 1e9

using namespace std;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	while (1) {
		vector<pair<string, int>> orders;
		while (1) {
			string s; cin >> s;
			if (s == "QUIT") return 0;
			if (s == "END") break;
			if (s == "NUM") {
				int a; cin >> a;
				orders.push_back({ s, a });
			}
			else {
				orders.push_back({ s, 0 });
			}
		}

		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			stack<int> st;
			int num; 
			bool ck = true;

			cin >> num;
			st.push(num);
			for (int i = 0; i < orders.size(); i++) {

				string order = orders[i].first;
				if (order == "NUM") {
					st.push(orders[i].second);
				}
				else if (order == "POP") { // 스택 가장 위의 숫자를 제거
					if (st.empty()) { ck = false; break; }
					st.pop();
				}
				else if (order == "INV") { // 첫 번째 수의 부호를 바꾼다.(42 -> -42)
					if (st.empty()) { ck = false; break; }
					int tmp = st.top() * (-1); st.pop();
					st.push(tmp);
				}
				else if (order == "DUP") { // 첫 번째 숫자를 하나 더 스택의 가장 위에 저장
					if (st.empty()) { ck = false; break; }
					st.push(st.top());
				}
				else if (order == "SWP") { // 첫 번째 숫자와 두 번째 숫자의 위치를 서로 바꾼다.
					if (st.size() < 2) { ck = false; break; }
					int n1 = st.top(); st.pop();
					int n2 = st.top(); st.pop();
					st.push(n1); 
					st.push(n2);
				}
				else if (order == "ADD") { // 첫 번째 숫자와 두 번째 숫자를 더한다
					if (st.size() < 2) { ck = false; break; }
					int n1 = st.top(); st.pop();
					int n2 = st.top(); st.pop();
					if(abs(n1+ n2) > LIMIT) { ck = false; break; }
					st.push(n1 + n2);
				}
				else if (order == "SUB") { //  첫 번째 숫자와 두 번째 숫자를 뺀다. (두 번째 - 첫 번째)
					if (st.size() < 2) { ck = false; break; }
					int n1 = st.top(); st.pop();
					int n2 = st.top(); st.pop();
					if (abs(n2 - n1) > LIMIT) { ck = false; break; }
					st.push(n2 - n1);
				}
				else if (order == "MUL") { // 첫 번째 숫자와 두 번째 숫자를 곱한다. // long long으로 받아야함
					if (st.size() < 2) { ck = false; break; }
					long long n1 = st.top(); st.pop();
					long long n2 = st.top(); st.pop();
					if (abs(n2 * n1) > LIMIT) { ck = false; break; }
					st.push(n2 * n1);
				}
				else if (order == "DIV") { // 첫 번째 숫자로 두 번째 숫자를 나눈 몫을 저장
					if (st.size() < 2 || st.top() == 0) { ck = false; break; }
					int cnt = 0;
					int n1 = st.top(); st.pop(); if (n1 < 0) cnt++;
					int n2 = st.top(); st.pop(); if (n2 < 0) cnt++;
					int tmp = abs(n2 / n1);
					if (cnt == 1) tmp *= -1;
					if (abs(tmp)> LIMIT) { ck = false; break; }
					st.push(tmp);
				}
				else if (order == "MOD") { // 첫 번째 숫자로 두 번째 숫자를 나눈 나머지를 저장
					if (st.size() < 2 || st.top() == 0) { ck = false; break; }
					int cnt = 0;
					int n1 = st.top(); st.pop(); 
					int n2 = st.top(); st.pop(); 
					int tmp = abs(n2 % n1);
					if (n2 < 0) { tmp *= -1; }
					if (abs(tmp) > LIMIT) { ck = false; break; }
					st.push(tmp);
				}
			}

			if (!ck || st.size() != 1) {
				cout << "ERROR\n";
			}
			else {
				cout << st.top() << "\n";
			}
		}
		cout << "\n";

	}

	return 0;
}
