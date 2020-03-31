#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1001
#define INF 987654321

using namespace std;

int n, res;
int arr[SIZE];

// 에라토스테네스의 체 
// 소수 찾는 법

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i <= 1000; i++) {
		arr[i] = i;
	}

	// sqrt(n) 만큼만 확인해도 됨
	for (int i = 2; i <= sqrt(1000); i++) {
		if (arr[i] == 0) continue; // 0이면 pass
		// i의 자기자신 제외 i의 배수는 전부 0으로 
		for (int j = i + i; j <= 1000; j += i) { 
			arr[j] = 0;
		}
	}


	for (int i = 2; i <= 1000; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
