#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/* 
   
   ptr 2개를 1부터 시작

   (r * r) - (l * l) == g 라면 r 출력하고 몸무게 찾았다고 표시
   
   만약 (r - l)이 1이고 (r * r) - (l * l)가 g보다 크면 더이상 탐색 x 
     => 제일 인접한 제곱수끼리(차이 == 1)의 차가 g보다 크면 더이상 탐색을 못함 

   (r * r) - (l * l)의 값이 g 보다 크다면 l 값을 줄여서 범위를 좁히고
   (r * r) - (l * l) 값이 g보다 작거나 같으면 right을 늘려서 범위를 늘려줌
 */

int g;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> g;
	int left = 1, right = 1;
	bool isFind = false;

	while (1) {
		if (right * right - left * left == g) {
			isFind = true;
			cout << right << "\n";
		}
		if (right - left == 1 && right * right - left * left > g) break;
		if (right * right - left * left > g) left++;
		else right++;
	}

	if (!isFind) cout << -1 << "\n";

	return 0;
}

//--------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

/*
   처음 생각해낸 방법

   G를 2로 나눈 값 = r이라 했을 때

   정답이되는 몸무게의 제일 큰 값은 r +1 임 (r+1)^2 - r^2가 G가 되는 가장 큰 수 이기 때문 (제곱수끼리의 차는 1, 3, 5, ... 의 식으로 늘어남)

   그래서 (r+1)을 기준으로 제곱수 값들을 모두 벡터에 넣고

   투포인터를 이용해서 차이가 G가 되는 값들을 찾는다.

   ** 틀렷던 이유 => G가 짝수면 무조건 -1이라고 처리했을 때 틀렸고

   숫자를 찾았을 경우에 flag를 두어서 처리하여 맞음

*/

int g, limit;
vector<long long> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> g;

	limit = (g / 2) + 1;

	for (long long i = 1; i <= limit; i++) v.push_back(i * i);

	int left = 0, right = 0;
	bool isFind = false;
	while (left <= right && right < v.size()) {
		if (v[right] - v[left] >= g) {
			if (v[right] - v[left] == g) {
				int num = sqrt(v[right]);
				isFind = true;
				cout << num << "\n";
			}
			left++;
		}
		else {
			right++;
		}
	}

	if (!isFind) cout << -1 << "\n";

	return 0;
}
