#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
   강의 시작 시간 기준 정렬 (오름차순)

   prioirty queue => 강의가 끝나는 시간을 push ==> 현재 사용중인 강의실 개수라고 보면 됨

   강의 시작 시간 < pq의 top (강의 끝시간)이 더 긴 강의라면 해당 강의의 끝시간을 pq에 push
   강의 시작 시간 >= 강의 끝시간 이라면 pq에서 하나 빼고, 강의 끝 시간 push
*/

int n;
vector<pair<int, int>> classTime;
priority_queue<int, vector<int>, greater<int>> lectureRoom;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	classTime.resize(n);
	for (int i = 0; i < n; i++) cin >> classTime[i].first >> classTime[i].second;

	sort(classTime.begin(), classTime.end());
	lectureRoom.push(classTime[0].second);

	for (int i = 1; i < n; i++) {
		if (lectureRoom.top() > classTime[i].first) { // 강의 끝 시간 > 강의 시작시간
			lectureRoom.push(classTime[i].second); // 강의실 추가
		}
		else { // 강의 끝 시간 <= 강의 시작시간
			lectureRoom.pop(); // 강의실 하나 빼고
			lectureRoom.push(classTime[i].second); //다음 강의로 추가
		}
	}

	cout << lectureRoom.size() << "\n";

	return 0;
}
