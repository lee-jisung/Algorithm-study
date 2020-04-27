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

long long min_val, max_val, arr[SIZE], sqCnt;
bool visit[SIZE];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> min_val >> max_val;
	int result = max_val - min_val + 1;

	long long sq = (long long)sqrt(max_val); // min ~ max 중 제곱 수의 최대값 찾기

	// 2 ~ 제곱수의 최대값 까지 arr에 각 i의 제곱수를 저장
	for (long long i = 2; i <= sq; i++) { 
		arr[i] = (i * i);
		sqCnt++; // 제곱 수 count
	}

	// 제곱수 개수만큼 min ~ max사이의 숫자에서 빼줄 숫자 찾기
	for (int i = 2; i < sqCnt + 2; i++) {

		long long div = min_val; 
		if (div % arr[i] != 0) { // i번째 제곱수인 arr[i]로 min_val가 안나눠지면 min_val보다 큰 arr[i]의 배수를 만들어줌
			div = (min_val / arr[i] + 1) * arr[i]; // min_val 보다 큰 arr[i]의 배수 만들기
		}
		// min ~ max 사이의 arr[i]인 제곱수로 나누어떨어지는 수들을 모두 제거
		for (long long j = div; j <= max_val; j += arr[i]) {
			if (!visit[j - min_val]) {
				visit[j - min_val] = true;
				result--;
			}
		}
	}

	cout << result << "\n";

	return 0;
}
