#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

int res;
string p;

/*
   res - p의 개수 
   a를 만났을 때 다음 인덱스 값이 p면 res값 1개 줄이고 인덱스 + 1
   최종 res가 1로 끝나면 ppap 아니면 np
*/

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> p;

	for (int i = 0; i < p.length(); i++) {

		if (p[i] == 'P') {
			res++; 
		}
		else if (p[i] == 'A' && res >= 2 && p[i+1] == 'P') {
			res--;
			i++;
		}
		else { // A문자 시점에서 앞에 p가 2개 이상이 아니거나 뒤에가 p가아니면 np
			cout << "NP\n";
			return 0;
		}
	}
	if (res == 1) {
		cout << "PPAP\n";
	}
	else
		cout << "NP\n";

	return 0;
}
