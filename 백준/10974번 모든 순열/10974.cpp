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
   N과M 똑같음
*/

int n, m; 
int arr[9];
bool isVisit[9];

void backtracking(int k) {
	if (k == n) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isVisit[i]) {
			isVisit[i] = true;
			arr[k] = i+1;
			backtracking(k + 1);
			isVisit[i] = false;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	backtracking(0);

	return 0;
}
