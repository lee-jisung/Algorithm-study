#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
   뒤에서부터 k자리를 잘랐을 때 중복이 없는 경우 찾기

   reverse로 문자열 순서를 바꿔서 substr를 이용해 앞에서부터 k자리를 자르기
   set을 이용해 중복 여부 확인
*/

int n;
vector<string> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		reverse(v[i].begin(), v[i].end());
	}

	for (int i = 1; i <= v[0].length(); i++) {
		set<string> st;
		bool isPos = true;
		for (int j = 0; j < v.size(); j++) {
			string str = v[j].substr(0, i);
			if (st.find(str) == st.end()) {
				st.insert(str);
			}
			else {
				isPos = false;
				break;
			}
		}
		if (isPos) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}
