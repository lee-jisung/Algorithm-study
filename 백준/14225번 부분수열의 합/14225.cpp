#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, arr[21], partSet[21];
int maxVal;
bool isVisit[21], numbers[2000001];
set<int> st;

//void makeSum(int idx, int no) {
//
//	int sum = 0;
//	for (int i = 0; i < no; i++) {
//		sum += partSet[i];
//	}
//	if(maxVal < sum) maxVal = sum;
//	st.insert(sum);
//
//	for (int i = idx; i < n; i++) {
//		if (isVisit[i]) continue;
//		isVisit[i] = true;
//		partSet[no] = arr[i];
//		makeSum(i, no + 1);
//		isVisit[i] = false;
//	}
//}

void makeSum(int idx, int sum) {

	if (idx == n) {
		if (maxVal < sum) maxVal = sum;
		numbers[sum] = true;
		st.insert(sum);
		return;
	}
	makeSum(idx + 1, sum + arr[idx]);
	makeSum(idx + 1, sum);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	makeSum(0, 0);
	
	// 시간이 너무 많이 차이남
	//for (int i = 1; i <= maxVal; i++) {
	//	if (!st.count(i)) {
	//		cout << i << "\n";
	//		return 0;
	//	}
	//}
	//cout << maxVal + 1 << "\n";

	int idx = 0;
	while (1) {
		if (!numbers[idx]) {
			cout << idx << "\n";
			break;
		}
		idx++;
	}

	return 0;
}
