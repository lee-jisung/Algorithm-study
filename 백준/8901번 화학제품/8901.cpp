#include <iostream>
#include <algorithm>

using namespace std;

/*
   A => i개 선택하면 
   B => 최대 (B - i)개 선택할 수 있고 ( => 이걸 j개라고 하면)
   C => 최대 (C - j)개 선택 가능함

   A -> i개 선택 => AB = i개
   B -> j개 선택 => BC = j개
   C -> CA = C - j와 A - i 중 적은 값으로 결정
*/

int T;
int a, b, c, result;
int cost[3];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {

		cin >> a >> b >> c;
		for (int i = 0; i < 3; i++) cin >> cost[i];

		result = 0;
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b - i; j++) {
				if (c - j < 0) break;
				//            AB              BC               CA
				int tmp = (cost[0] * i) + (cost[1] * j) + (cost[2] * min(c - j, a - i));
				result = max(result, tmp);
			}
		}
	
		cout << result << "\n";
	}

	return 0;
}
