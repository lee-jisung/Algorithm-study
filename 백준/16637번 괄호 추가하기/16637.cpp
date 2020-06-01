#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

int n, result;
string str;

/*
   dfs -> 괄호를 묶는경우 / 안묶는 경우를 나눠서 생각
  
  3+8*7-9를 예로들어서

   1. 괄호를 아예 안묶는 경우
   2. 괄호 1개 -> (3+8)*7-9,  3 + (8*7) -9 ,  3+8*(7-9)
   3. 괄호 2개 -> (3+8) * (7-9)
   4. 괄호 3개 -> 불가
   ...

   식으로 진행해서 모든 경우를 확인

 */

int cal(int a, int b, char c) {
	if (c == '+') return a + b;
	else if (c == '-') return a - b;
	else if (c == '*') return a * b;
}

void dfs(int idx, int sum) {

	if (idx > n-1) {
		result = max(result, sum);
		return;
	}
	char c;
	// idx가 0일땐 sum이 0인경우와 첫번째 숫자를 더해줘야하기때문에 +로 주고 그 이상의 idx면 이전 계산결과와 다음 숫자 사이의
	// 연산을 하기 위해서 str[idx-1]로 저장
	if (idx == 0) c = '+';
	else c = str[idx - 1];

	if (idx + 2 < n) {
		// 괄호를 묶는 경우 먼저 묶인 쪽을 계산하여 tmp에 저장 후 
		// 이전까지 연산한 결과인 sum과 tmp를 연산해주고 idx+4를 통해 괄호 이후의 수로 넘어감
		int tmp = cal(str[idx] - '0', str[idx + 2] - '0', str[idx+1]);
		dfs(idx + 4, cal(sum, tmp, c));
	}
	// 괄호를 안묵는 경우 이전까지의 계산결과와 현재 가리키는곳을 연산한 후 다음 수로 넘어감(idx+2)
	dfs(idx + 2, cal(sum, str[idx] - '0', c));
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> str;

	result = INT_MIN;
	dfs(0, 0);

	cout << result << "\n";
	
	return 0;
}
