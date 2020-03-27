#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100
#define INF 987654321

using namespace std;

/*
   n쪽까지 수 --> a ~ b까지 수 에서 나온 자리수로 변경
   a의 일의자리를 0, b의 일의자리를 9로 맞출때까지 a++, b--하면서 
   가감할때마다 해당 자리수가 나온 수만큼 ++해줌
   
   즉, a가 1일때 아직 0이 안됐으므로 증가해야함
   이때, 증가 하기 전 cal 함수를 불러 1이라는 자릿수를 현재 일의자리만큼 개수를 증가시켜줘야함
   따라서 prefix만큼 증가함

   여기서 prefix는 각 자리수를 의미하고 1의 자리일때는 1, 10의 자리일 때는 10이 됨

   a, b를 가감하면서 일의자리를 모두 더해주어 0, 9 자리수를 맞추면 b/10 - a/10 +1 의 수만큼 0 ~ 9가 반복해서 나온거임

   a = 10, b = 39일 때 10~19, 20~29, 30~39씩 0~9가 3번씩 나왔음
   따라서 b/10 - a/10 + 1 --> 3 - 1 + 1 = 3이고 3에 자리수를 곱하여 더해주면됨
  
   만약 a가 원래 100이었고, b가 390이었을때
   일의자리를 이미 처리한 후 a/10, b/10의 수가 다시 재귀함수로 불러들었다면
   a = 10, b = 39가 될 것이고 a ~ b까지 0, 9 숫자는 (3 - 1 + 1) * 10임
 
   10 ~ 39까지 0~9숫자는 사실 100 ~ 390까지의 0~9숫자임
   따라서 3번씩 나왔지만 10의자리수 이기때문에 10씩 곱해준 것
   10 -> 11의 과정이 사실은, 100 101, 102 ... 110이 된것임 
   
 */

long long n;
int cnt[10];

void cal(long long t, long long prefix) {

	while (t > 0) {
		cnt[t % 10] += prefix;
		t /= 10;
	}
}

void solve(long long a, long long b, long long prefix) {

	while (a % 10 != 0 && a <= b) {
		cal(a, prefix);
		a++;
	}
	if (a > b) return;

	while (b % 10 != 9 && b >= a) {
		cal(b, prefix);
		b--;
	}

	long long count = (b / 10 - a / 10 + 1);
	for (int i = 0; i < 10; i++)
		cnt[i] += count * prefix;
	solve(a / 10, b / 10, prefix * 10);

}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	solve(1, n, 1);
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << " ";

	return 0;
}
