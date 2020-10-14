#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int n, overtakeCnt;
unordered_map<string, int> enter;
vector<string> exited;

// 출차 순서를 보면서 먼저 나온 차량이 뒤에있는 차들보다 들어간 순서가 하나라도 높은게 있다면
// 추월한것

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		enter[s] = i;
	}
	
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		exited.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (enter[exited[i]] > enter[exited[j]]) {
				overtakeCnt++;
				break;
			}
		}
	}

	cout << overtakeCnt << "\n";

	return 0;
}

/*
5
ZG206A
PU234Q
OS945CK
ZG431SN
ZG5962J
ZG5962J
OS945CK
ZG206A
PU234Q
ZG431SN

answer = 2
*/

/*
5
ZG508OK
PU305A
RI604B
ZG206A
ZG232ZF
PU305A
ZG232ZF
ZG206A
ZG508OK
RI604B

answer = 3
*/
