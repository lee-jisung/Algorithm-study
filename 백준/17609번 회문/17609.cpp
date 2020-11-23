#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
  
   two pointer처럼 양쪽에서 문자를 비교해가면서 
   
   문자가 모두 같으면
   회문 => 0 출력
   
   문자가 다를 경우
   (i + 1 ~ j) / (i ~ j -1) 의 문자열이 palindrome이 되는지 확인해서
    된다면 유사 회문 => 1 출력
	안된다면 회문이 아님 => 2 출력

*/

int T;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {

		string input;
		cin >> input;
		int result = 0;
		
		for (int i = 0, j = input.length() - 1; i < j; i++, j--) {

			if (input[i] == input[j]) continue;

			bool isPalin = false;

			// (i + 1 ~ j) / (i ~ j-1) 의 2 구간을 확인
			for (int ck = 0; ck < 2 && isPalin == false; ck++) {

				int st = i, ed = j;
				
				// i + 1 or j-1 구간 지정
				ck == 0 ? st++ : ed--;

				isPalin = true;

				for (int a = st, b = ed; a < b; a++, b--) {
					if (input[a] != input[b]) {
						isPalin = false;
						break;
					}
				}
			}

			isPalin ? result = 1 : result = 2;
			break;
		}
		cout << result << "\n";
	}

	return 0;
}
