#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;

/*
   곱을 누적 => 누적할 때 곱 결과가 자신보다 크다면 누적하는 형태로 진행 (음수가 없기 때문에 가능)
*/

int n; 
double arr[10001], result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	result = arr[1];
	for (int i = 2;i <= n; i++) {
		if (arr[i] * arr[i - 1] >= arr[i])
			arr[i] = arr[i - 1] * arr[i];
		result = max(arr[i], result);
	}

	printf("%0.3lf", result);

	return 0;
}
