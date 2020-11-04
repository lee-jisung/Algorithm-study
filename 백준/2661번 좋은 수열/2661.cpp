#include <iostream>
#include <string>

using namespace std;

/*
   1, 2, 3 중 1개를 뒤에 새로 추가한 후,
   뒤에서부터 1, 2, 3 ... 의 길이만큼 잘라가면서 두 문자열 비교
     => i = 1 ~ no / 2 만큼 
	    substr(no - i, i) / substr(no - i * 2 , i) 로 비교

   n-1 == n 인 이유는 seq += c를 함수 내부에서 해주기 때문에 
   no = 8이될 때 seq의 길이가 c를 더하기 전인 7임
*/

int n;
string seq;

void makeSeq(char c, int no) {
	if (no - 1 == n) {
		cout << seq << "\n";
		exit(0);
	}

	seq += c;
	for (int i = 1; i <= no / 2; i++) {
		string s1 = seq.substr(no - i, i);
		string s2 = seq.substr(no - i * 2, i);
		if (s1.compare(s2) == 0) { // 연속된 문자열이 같은 것이 있다면 안좋은 수열
			seq.pop_back();
			return;
		}
	}

	for (int i = 1; i <= 3; i++)
		makeSeq(i + '0', no + 1);
	// 1, 2, 3 모두 뒤에 붙였을 때도 성립안되면 그전 수를 빼고 다른 수를 넣기 위해 pop_back해줌
	seq.pop_back(); // no - 1의 자리가 성립하지 않는 경우 
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	makeSeq('1', 1);

	return 0;
}
