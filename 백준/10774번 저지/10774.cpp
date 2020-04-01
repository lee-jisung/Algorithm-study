#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 1000001
#define INF 987654321

using namespace std;

/*
   일차원적 disjoint-set // 왜 disjoint-set으로 분류되있는지?;;
*/

int j, a, res;
char arr[SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> j >> a;
	for (int i = 1; i <= j; i++)
		cin >> arr[i];

	for (int i = 0; i < a; i++) {
		char size;
		int num;
		cin >> size >> num;

		if (arr[num] != 'x') {

			if (arr[num] == 'S' && size == 'S') {
				res++;
				arr[num] = 'x';
			}
			else if (arr[num] == 'M' && (size == 'S' || size == 'M')) {
				res++;
				arr[num] = 'x';
			}
			else if (arr[num] == 'L') {
				res++;
				arr[num] = 'x';
			}

		}
	}

	cout << res << "\n";

	return 0;
}
