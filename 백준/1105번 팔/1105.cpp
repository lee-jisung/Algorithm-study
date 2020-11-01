#include <iostream>
#include <string>

using namespace std;

string L, R;
int result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> R;

	// 길이가 같을 때만 비교
	if (L.length() == R.length()) {
		// 앞에서부터 8일때 count
		for (int i = 0; i < L.length(); i++) {
			if (L[i] == '8' && R[i] == '8')
				result++;
			// 단, R 숫자가 더 커지는 구간이오면 그 이후에는 8이아닌 다른 숫자들이 올 수 있으므로 break
			else if (L[i] < R[i]) {
				break;
			}
		}
	}

	cout << result << "\n";
	return 0;
}
