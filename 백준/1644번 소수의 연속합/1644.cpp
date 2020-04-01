#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 4000001
#define INF 987654321

using namespace std;

int n, p1, p2, res, comp;
int arr[SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 2; i < SIZE; i++)
		arr[i] = i;
	
	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (arr[i]) {
			for (int j = i + i; j < SIZE;j += i)
				arr[j] = 0;
		}
	}

	p1 = p2 = 2;
	comp = 2;
	while (p1 <= p2 && p2 <= n) {
		if (comp < n) {
			while (1) {
				p2++;
				if (arr[p2] != 0) break;
			}
			comp += arr[p2];
		}
		else if (comp > n) {
			comp -= arr[p1];
			while (1) {
				p1++;
				if (arr[p1] != 0) break;
			}
		}
		else if (comp == n) {
			res++;
			while (1) {
				p2++;
				if (arr[p2] != 0) break;
			}
			comp += arr[p2];
		}
	}

	cout << res << "\n";

	return 0;
}
