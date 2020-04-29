# LCS? 

- 최장 공통 부문 문자열

## Substring vs Subsequence

 - ex) 가나다라마바사
       나아자다마바사
       
 - Longest Substring
 > 가나다라**마바사**    
 > 나아자다**마바사**
 
 - Longest Subsequence
 > 가**나다**라**마바사**    
 > **나**아자**다마바사**
 
 --> LCS = **나다마바사**


## LCS Implement

- ACAYKP, CAPCAK의 두 단어를 통해 LCS를 구하는 구현 과정 확인

![image](https://user-images.githubusercontent.com/32594290/80601095-507fb500-8a68-11ea-90a3-ed68408f3eb6.png)

LCS를 구현할 때, LCS 테이블의 첫 행, 첫 열은 항상 0으로 통일

![image](https://user-images.githubusercontent.com/32594290/80601199-76a55500-8a68-11ea-96f3-c0e1edb8bcb3.png)

ACAYKP의 단어에서 C를 이용해서 테이블을 채운다면 위와 같다.
위의 테이블이 의미하는 바는 A열까지의 LCS는 0, AC열까지의 LCS는 1, ... , ACAYKP까지의 LCS는 1

즉, **ACAYKP까지 LCS가 1이라는 것은 ACAYKP와 C의 공통 부문 문자열이 1개 있다는 뜻임.**

![image](https://user-images.githubusercontent.com/32594290/80601600-fe8b5f00-8a68-11ea-9187-39bc42095025.png)

다음으로 ACAYKP와 CA를 비교해보면 LCS는 2가 나올 것임


***숫자를 넣는 기준은??***

![image](https://user-images.githubusercontent.com/32594290/80602126-b15bbd00-8a69-11ea-9aa6-2f6f4f73eb91.png)

**푸른색 부분**을 보면, C와 AC에서 이미 1이 되어, C와 ACA에서는 마지막 단어가 C와 A로 서로 다르지만, 1인 이유는 왼쪽에서의 값이 1이었으므로
1이 LCS임.

**분홍색 부분**을 보면, CAP와 ACA에서 마지막 단어가 P와 A로 서로 다르지만, LCS가 2인 이유는 이전 CAP의 CA와 ACA의 CA가 서로 2여서
누적된 값이 내려왔음.

즉, **현재 가리키는 문자가 서로 다를 때는, 테이블에 들어가 있는 수의 왼쪽과 위쪽 중 큰 값을 받아 옴**

**마지막 회색부분**을 보면, 3이 된 이유는 CAP와 ACAYKP의 마지막 단어가 P로 같기 때문임. 
--> 3은 위의 2에서 더해진 1? 왼쪽 2에서 더해진 1?이 아닌 왼쪽 위(대각선) 2에서 더해진 1이다.
이유는 CA와 ACAYK다음 P와 P가 동일한 문자를 갖는다고 보는 것이 정확한 의미이기 때문에 대각선 방향에서 1을 더해야 함

즉 **현재 가르키는 문자가 서로 같을 때는, 테이블에 들어가 있는 수의 대각선 값 + 1을 넣어준다**

![image](https://user-images.githubusercontent.com/32594290/80602716-67270b80-8a6a-11ea-967c-2793ee21b049.png)

최종 LCS 과정을 거친 후의 테이블이며, 마지막 요소인 4가 LCS 값임.


## Code

``` c++
#include <iostream>
#include <string>

#define SIZE 1001

using namespace std;

int lcs[SIZE][SIZE];

string a, b;
string str1, str2;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	str1 = '0' + a; // 첫 행,열을 0으로 하기 위해서 앞에 0을 붙여줌
	str2 = '0' + b;

	for (int i = 1; i < str1.length(); i++) {
		for (int j = 1; j < str2.length(); j++) {
			if (str1[i] == str2[j]) { //문자가 같다면 대각선 값 + 1
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else { // 다르다면 왼쪽/위쪽 중 큰값
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}

	cout << lcs[str1.length()-1][str2.length()-1];
	return 0;
}

```


## LCS Implement, 실제 단어 찾기

![image](https://user-images.githubusercontent.com/32594290/80604635-f1706f00-8a6c-11ea-9e0d-ef8ff9aee565.png)

가장 끝 자리부터 시작해서 자신과 같은 숫자가 있는 곳으로 따라감.
만약, 왼쪽 위쪽에 자신과 같은 수가 없다면 왼쪽 위(대각선)방향의 값이 현재 (자신의 값 - 1)인지 확인하고 그 수를 따라감
수가 0이 되면 종료

** 대각선으로 이동하게 되는 경우에 현재 문자열을 담고, 대각선으로 이동 ** 
왼쪽, 위쪽으로 이동할때는 문자열을 담지 않음.


## Code, LCS

``` c++

#include <iostream>
#include <string>
#include <stack>

#define SIZE 1001

using namespace std;

int lcs[SIZE][SIZE];

string a, b;
string str1, str2;
stack<char> st;
int r, c;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	str1 = '0' + a;
	str2 = '0' + b;

	for (int i = 1; i < str1.length(); i++) {
		for (int j = 1; j < str2.length(); j++) {
			if (str1[i] == str2[j]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
			}
		}
	}

	r = str1.length() - 1; c = str2.length() - 1;
	while (lcs[r][c] != 0) {

		if (lcs[r][c] == lcs[r][c - 1])
			c--;

		else if (lcs[r][c] == lcs[r - 1][c])
			r--;
		else if (lcs[r][c] - 1 == lcs[r - 1][c - 1]) {
			st.push(str1[r]);
			r--, c--;
		}	
	}

	cout << lcs[str1.length() - 1][str2.length() - 1] << "\n";
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}

```
