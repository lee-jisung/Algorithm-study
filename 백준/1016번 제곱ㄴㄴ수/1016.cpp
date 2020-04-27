#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1000001
#define INF 987654321

using namespace std;

/*
   min ~ max 사이의 제곱근의 최대값(max의 제곱근)을 구한 후 이보다 작은 제곱근들을 저장
   제곱근들의 배수 중 min ~ max 사이의 값들을 찾아 count
   전체 수의 개수에서 찾은 제곱근 배수 들의 수를 뺌
*/

long long min_val, max_val, arr[SIZE], cnt;
bool ck[SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> min_val >> max_val;

	long long sq_max_val = (long long)sqrt(max_val);
	
	// 2 ~ 제곱근의 최대값 사이의 제곱 수를 찾음
	for (long long i = 2; i <= sq_max_val; i++) {
		arr[i] = i * i;
		cnt++;
	}

	int count = 0; // min_val ~ max_val 사이 -> 제곱 수로 나누어 떨어지는 수

	for (int i = 2; i < cnt + 2; i++) { // 제곱 개수만큼 for문 

		long long temp = min_val;
		if (temp % arr[i] != 0) { // -> temp가 arr[i](제곱수) 로 나누어 떨어지지 않으면
			temp = (min_val / arr[i] + 1) * arr[i];// -> min값을 arr[i](제곱수)로 나눈 몫에 +1 후 arr[i]를 다시 곱해서 범위 안 값으로 만듦
		}

		// 제곱 수의 배수를 모두 count하고, ck 배열로 방문처리 해주어 중복 제거 
		for (long long div = temp; div <= max_val; div += arr[i]) { 
			if (!ck[div - min_val]) {
				ck[div - min_val] = true;
				count++;
			}
		}
	}

	cout << max_val - min_val + 1 - count;

	return 0;
}
