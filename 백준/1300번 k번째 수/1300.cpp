#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

/*
   n x n 행렬에서 

   i번째 행 -> i x 1, i x 2, i x 3, ... , i x n 으로 이루어짐
   i번째 행에서 특정 수 mid보다 작은 값을 가지는 것의 개수 -> i x j <= mid 을 만족하는 j 개수
   --> ix1, ... , ixj -> mid/i개임
   단, mid/i가 n보다 커질 수 있음 --> cnt = min(mid/i, n)

   따라서 모든 i행에 대해서 min(mid/i,n)을 더해주었을 때 모든 숫자의 갯수가 k개 이상이 되면
   mid는 k번째 숫자가 될 수 있음
   
 */

int n, k, m, res;

void binary_search(int st, int end) {
    if (st > end) return;
    int mid = (st + end) / 2;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += min(mid / i, n);
    }
    if (sum >= k) {
        res = mid;
        binary_search(st, mid - 1);
    }
    else if (sum < k) {
        binary_search(mid + 1, end);
    }
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;

    binary_search(0, k);
    
    cout << res << "\n";

	return 0;
}
