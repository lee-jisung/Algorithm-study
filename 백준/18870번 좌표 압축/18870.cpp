#include <iostream>
#include <algorithm>
#include <vector>

/*
   정렬 후 중복 제거 
   각 정수가 해당하는 index값이 좌표값이라고 볼 수 잇음
*/

using namespace std;

int n;
vector<int> v, tmp;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		v.push_back(num);
		tmp.push_back(num);
	}
	
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
		cout << pos << " ";
	}
	
	return 0;
}
