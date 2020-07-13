#include <iostream>
#include <vector>

using namespace std;

/*
   https://www.crocus.co.kr/666
   https://www.acmicpc.net/blog/view/21

   (i & -i)의 의미: 특정 값에서 1이 나타나는 최하위 비트를 알려주는 역할

   ex, i = 12라고 했을 때, i = 1100(2)이다
   그럼 ~i = 0011(2)이고 ~i + 1 = -i = 0100(2)가 된다.
   (i & -i)를 하면 1100 & 0100을 하는 것이므로 0100이 최종 값이다
   따라서 1100의 1이 나타나는 최하위 비트 0100이 결과값으로 나온다.

   (i & -i)를 더하거나 빼가면서 tree[i]가 나타내는 구간의 합을 더하고, 변경값을 더해줄 수 있다.

*/
long long sum(vector<long long >& tree, int i) {
	long long ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}

void update(vector<long long>& tree, int i, long long diff) {
	while (i < tree.size()) {
		tree[i] += diff;
		i += (i & -i);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> a(n + 1);
	vector<long long> tree(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(tree, i, a[i]);
	}

	 // a ~ b 구간 합 
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum(tree, b) - sum(tree, a - 1) << "\n";
	}


	return 0;
}
