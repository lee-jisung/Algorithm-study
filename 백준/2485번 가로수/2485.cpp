#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

/*
   가로수 좌표 사이 간격 차이들의 GCD구하기
   ( 각 차이값 / gcd - 1 ) 을 모두 더하면 됨
*/

int n, gcdVal, tmp, result;
vector<int> diff, tree;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	tree.resize(n); diff.resize(n);
	
	gcdVal = INF;

	for (int i = 0; i < n; i++) {
		cin >> tree[i];

		if (i > 0) {

			diff[i] = tree[i] - tree[i - 1];
			tmp = gcd(diff[i], diff[i-1]);

			if (gcdVal > tmp)
				gcdVal = tmp;
		}
	}

	for (int i = 1; i < n; i++)
		result += diff[i] / gcdVal - 1;
        
	cout << result << "\n";
	return 0;
}
