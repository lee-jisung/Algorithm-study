#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
   오름차순 정렬, 뒤에서부터 3개씩 잘라서 2개만 더하기
   나머지 정가지불하는 경우 다 더한 후 출력
*/

int n;
long long result;
vector<int> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n / 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (j != 2) result += v.back();
			v.pop_back();
		}
	}

	while (!v.empty()) {
		result += v.back();
		v.pop_back();
	}

	cout << result << "\n";

	return 0;
}
