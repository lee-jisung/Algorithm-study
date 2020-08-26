#include <iostream>
#include <vector>

/*
   최장 증가 수열 
   => 꼬인 전깃줄 == 앞보다 적은 번호의 전깃줄이 나오면 꼬인 선 
   => 증가하는 수열을 계속해서 삽입 
   => 증가하는 수가 아닐 경우, lower_bound를 이용해서 해당 수가 기존 vector에서 적절한 위치에 삽입될 수 있는지 확인해서 삽입
   => 최대한 많은 경우를 삽입하기 위함
   ex) 10 40 70의 경우 50이 들어오면 10 40 50으로 됨.
      이후 55가 들어오면 10 40 50 55로 되지만, 70이 유지되었다면 55가 들어오지 못했을 것.
*/

#define INF 1e9

using namespace std;

int n, cnt;
vector<int> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	v.push_back(-INF);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;

		if (v.back() < x) {
			v.push_back(x);
			cnt++;
		}
		else {
			auto iter = lower_bound(v.begin(), v.end(), x);
			*iter = x;
		}
	}

	cout << n - cnt;

	return 0;
}
