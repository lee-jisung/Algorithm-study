#include <iostream>
#include <algorithm>
#include <vector>

#define INF 2e9

/*
  양 끝 => two pointer
  가운데로 오면서 2개의 합 구하기
  합이 0보다 작으면 앞 pointer를 증가, 0보다 크면 뒤 pointer를 감소
   => 0보다 작단얘기 => 음수의 크기가 더 큼 => 음수 숫자를 하나 줄여야 0에 더 가까워 질 수 있음
*/

using namespace std;

typedef pair<int, int> PAIR;

int n, sum;
vector<int> v;
PAIR res;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		v.push_back(a);
	}

	sum = INF;
	int p = 0, q = n - 1;

	while (p < q) {

		int a = v[p];
		int b = v[q];
		if (abs(a + b) < sum) {
			sum = abs(a + b);
			res.first = v[p];
			res.second = v[q];
		}

		if ((a + b) < 0) p++;
		else q--;
	}

	cout << res.first << " " << res.second << "\n";

	return 0;
}
