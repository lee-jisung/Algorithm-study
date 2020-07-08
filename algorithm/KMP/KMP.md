
## KMP Algorithm

### Reference

 - https://bowbowbow.tistory.com/6



### Example

``` c++

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
  Parent string의 pointer = i 
  pattern 의 pointer = j
  
  pattern의 table을 구하여 prefix와 suffix를 비교하여 prefix == suffix인 최대 길이를 저장하는 table 생성

  i, j를 증가시키면서 parent와 pattern을 비교하면서 문자가 다른 부분이 나올 경우
  j = table[j-1]로 적용

  j가 0이 된다면 pattern의 처음부터 다시 비교를 해야하므로 그 이전까지 parent에서 pattern과 동일한 문자가 나온적이 없음
  j가 0 이상의 수라면 pattern의 해당 index 문자 까지 현재 i가 가리키고 있는 이전 문자들과 동일하다는 얘기
  즉, j를 해당 수부터 parent와 비교하여 일치여부를 확인하면 됨

  이렇게 하면 parent에서 문자 하나당 pattern을 전체 비교하는 것이 아니라
  일치하는 부분을 뛰어넘어 뒷부분을 비교할 수 있게 되므로 시간을 줄일 수 있음

*/

int n, m, cnt;
string s, pat;

vector<int> makeTable(string pattern) {
	int patternSize = pattern.length();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parent.length();
	int patternSize = pattern.length();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) { // 문자열이 일치할 경우
				cnt++;
				j = table[j];
			}
			else {
				j++;
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string parent = "abaacbdaacbacdbababdcd";
	string pattern = "ababba";

	KMP(parent, pattern);
	cout << cnt << "\n";

	return 0;
}
```

