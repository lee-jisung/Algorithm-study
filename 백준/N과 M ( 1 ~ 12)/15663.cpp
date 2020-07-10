#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int n, m, arr[9];
vector<int> num;
map<int, int> mp;

void func(int no) {
	if (no == m) {

		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < num.size(); i++) {
		if (mp[num[i]]) {
			mp[num[i]]--;
			arr[no] = num[i];
			func(no + 1);
			mp[num[i]]++;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;

		if (!mp.count(tmp)) {
			mp[tmp] = 1;
			num.push_back(tmp);
		}
		else {
			mp[tmp]++;
		}
	}
	sort(num.begin(), num.end());

	func(0);

	return 0;
}
