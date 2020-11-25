#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/*
   map으로 로그 기록 관리
   이름을 문자열 순으로 정렬 후 reverse로 역순 만든 후 출력
*/

int n;
map<string, bool> accessLog;
vector<string> nameList;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, access;
		cin >> name >> access;
		if (access.compare("enter") == 0) {
			accessLog[name] = true;
		}
		else {
			accessLog[name] = false;
		}
	}

	for (auto iter = accessLog.begin(); iter != accessLog.end(); iter++) {
		if (iter->second) nameList.push_back(iter->first);
	}

	sort(nameList.begin(), nameList.end());
	reverse(nameList.begin(), nameList.end());

	for (string name : nameList) {
		cout << name << "\n";
	}

	return 0;
}
