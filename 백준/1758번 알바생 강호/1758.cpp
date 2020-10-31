#include <iostream>
#include <algorithm>
#include <vector>

/*
   큰 대로 정렬해서 더하기
*/

using namespace std;

int n;
long long result;
vector<int> line;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	line.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> line[i];
	}

	sort(line.begin(), line.end(), greater<int>());

	for (int i = 1; i <= n; i++) {
		line[i - 1] - (i - 1) >= 0 ? result += line[i - 1] - (i - 1) : result;
	}

	cout << result << "\n";

	return 0;
}
