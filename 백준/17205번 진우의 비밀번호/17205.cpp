#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
   dp[i] = dp[i-1] * 26 + 26 

   a, aa, ab ... 이런식으로 나아가기 때문에
   2개를 고를 확률은 26 * 26이지만 aa, ab, ac ... 말고도 a, b, c, d, ...의 1개씩 고르는 경우까지 포함하기 때문에 + 26을 해준 것

   ---------------------
   n = 3, 목표가 ba라면
   
   첫번째 글자인 'b'까지 가는데 소요되는 시간은

   최대 길이가 3이기 때문에 a, aa, aaa, aab ... 이런식으로 탐색하게됨 
   여기서 'b'까지 가는데 걸리는 시간은 'a'에서 뒤에 알파벳 2개를 조합하는 경우의 수니까 26 * 26 + 26임
   따라서 (input[i] - 'a') * dp[n-i-1]이 의미하는 바는
    
	i번째 알파벳 이전 올수 있는 경우의 수를 계산하는 것이며 
	dp[n-i-1] 은 i번째 자릿수 이후 남은 글자수에 대한 경우의 수임

	즉, 길이가 6, 목표가 b라면

	첫 글자를 a를 정해놓고 그 뒤에 올 수 있는 조합은 dp[5] 임 (길이 6에서 첫번째 글자를 정한 후 나머지 5개의 경우의 수를 찾는것이기 때문)

    그리고 

   (input[i] - 'a' + 1) => 해당 i번째 알파벳을 몇번째 만에 누르는지 계산
   
 */

int n;
string input;
long long dp[11], result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> input;
	
	dp[1] = 26;

	
	for (int i = 2; i <= 10; i++) {
		dp[i] = dp[i - 1] * 26 + 26;
	}
	for (int i = 0; i < input.length(); i++) {
		result += (input[i] - 'a') * dp[n - i - 1] + (input[i] - 'a' + 1);
	}

	cout << result << "\n";

	return 0;
}
