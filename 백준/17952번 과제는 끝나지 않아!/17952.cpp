#include <iostream>
#include <stack>

using namespace std;

/*
   1. 과제 가장 최근 나온 순대로 (과제를 받으면 바로 시작)
   2. 과제하는 도중 새로운 과제가 나오면 하던거 중단하고 새로운 과제 진행
   3. 새로운 과제가 끝났다면 이전 과제를 하던부분부터 이어서

   과제가 새로 나왔을 경우
     => 기존의 시간, 점수를 stack에 넣고 새로운 과제 시간을 -1 한 후 0인지 조사
	       => 0 이면 점수 + 하고 이전 과제 꺼내오기
		   => 0 이 아니면 pass
   과제가 나오지 않았을 경우
     => 기존 시간 -1 하고, 0인지 조사
	    => 0이면 점수 + 하고 이전 과제 꺼내오기
		=> 0이 아니면 pass
*/

int n;
int resultScore, idx, curScore, curTime;
stack<pair<int, int>> st;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int tc, score, time; cin >> tc;
		
		if (tc == 1) {
			cin >> score >> time;
			if (curTime != 0) {
				st.push({ curScore, curTime });
			}
			curTime = --time;
			curScore = score;
			if (curTime == 0) {
				resultScore += curScore;
				if (!st.empty()) {
					curScore = st.top().first;
					curTime = st.top().second;
					st.pop();
				}
			}
			continue;
		}

		if (--curTime == 0) {
			resultScore += curScore;
			if(!st.empty()) {
				curScore = st.top().first;
				curTime = st.top().second;
				st.pop();
			}
		}
	}

	cout << resultScore << "\n";

	return 0;
}
