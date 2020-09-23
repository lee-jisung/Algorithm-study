#include <iostream>
#include <algorithm>

/*
   정렬 후 양수, 음수로 나누어 
   양수 => 1보다 큰 수까지 곱해서 더하고
   음수 => 1보다 작은 수 까지 곱해서 더함 (0을 곱하면 최대가 될 수 있기 때문)

   남은 값은 그냥 더해주면 됨
*/

using namespace std;

int result;
int n, arr[10001];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n, greater<int>());

	int p = 0, q = n - 1;

	for (; p < q; p += 2) {
		if (arr[p] > 1 && arr[p + 1] > 1) {
			result += arr[p] * arr[p + 1];
		}
		else break;
	}
	
	for (; q > 0; q -= 2) {
		if (arr[q] < 1 && arr[q - 1] < 1) {
			result += arr[q] * arr[q - 1];
		}
		else break;
	}

	for (int i = p; i <= q; i++) {
		result += arr[i];
	}
	cout << result << "\n";

	return 0;
}
