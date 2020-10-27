#include <iostream>
#include <string>
#include <stack>

using namespace std;

int pairPosition[51];
string s;

int decompress(int start, int end) {
	int letters = 0;
	for (int i = start; i < end; i++) {
		if (s[i] == '(') {
			int num = s[i - 1] - '0';
			letters += num * decompress(i + 1, pairPosition[i]) - 1; // 곱할 수까지 ++로 세줫었기 때문에 -1 해줌
			i = pairPosition[i]; // 탐색할 index를 ) 다음부터 시작
			continue;
		}
		letters++; // 숫자 1개씩 세기
	}
	return letters;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	stack<int> st;

	// (, )의 위치를 전처리 => ( 의 짝인 ) 의 위치를 표시
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')') {
			pairPosition[st.top()] = i;
			st.pop();
		}
	}

	cout << decompress(0, s.length()) << "\n";
	return 0;
}
