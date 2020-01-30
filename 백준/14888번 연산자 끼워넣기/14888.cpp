#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n;
long long max_res, min_res;
int seq[12];

// + : 0
// - : 1
// * : 2
// / : 3
// 각 번호별로 맞는 연산자 수만큼 vector에 넣은 후 next_permutation을 이용하여
// 경우의 수를 모두 찾으면서 우선순위 없이 앞에서부터 연산하고 
// 최대, 최소값 비교하여 저장

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];
	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			v.push_back(i);
		}
	}

	sort(v.begin(), v.end());
	min_res = 1000000001;
	max_res = -1000000001;
	do {
		long long result = seq[0];

		for (int i = 0; i < v.size(); i++) {
			switch (v[i]) {
			case 0:
				result += seq[i + 1];
				break;
			case 1:
				result -= seq[i + 1];
				break;
			case 2:
				result *= seq[i + 1];
				break;
			case 3:
				result /= seq[i + 1];
				break;
			}
		}
		min_res = min(result, min_res);
		max_res = max(result, max_res);
	} while (next_permutation(v.begin(), v.end()));


	cout << max_res << "\n" << min_res << "\n";
	return 0;
}
