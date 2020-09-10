#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
   log 시작 시간 = 끝난시간 - 처리시간 + 1
   비교할 log의 끝난 시간 => 끝난시간 + 1000(1초)

                   
	  (i+1)의 끝일때  시작시간은 무조건 limit보다 적음
   i  |                  i+1초 (limit)
   |----------------------|----| << 이게 j번째라 했을 때
                        |------| 
						 이게 시작시간이라면 limit보다 작기때문에 count ++

*/

int getLogTime(string str) {

	string h = str.substr(11, 2);
	string m = str.substr(14, 2);
	string s = str.substr(17, 6);
	s.erase(s.begin() + 2, s.begin() + 3);

	int hour = stoi(h) * 60 * 60 * 1000;
	int minute = stoi(m) * 60 * 1000;
	int sec = stoi(s);
	return hour + minute + sec;
}

int getProcessTime(string str) {
	string t = str.substr(24, str.length() - 25); // 처리시간을 뺀 나머지 문자 개수 = 25개
	double pt = stod(t);
	int pTimes = pt * 1000;
	return pTimes;
}

int solution(vector<string> lines) {
	int answer = 0;
	vector<int> logTime, processTime;

	for (int i = 0; i < lines.size(); i++) {
		logTime.push_back(getLogTime(lines[i]));
		processTime.push_back(getProcessTime(lines[i]));
	}

	for (int i = 0; i < lines.size(); i++) {
		int cnt = 1; // i번째 log부터 count
		int limit = logTime[i] + 1000; // logTime + 1초 => i번째 log가 끝난 시간 ~ + 1초 
		for (int j = i + 1; j < lines.size(); j++) {
			//  startTime => j번째 log가 처리시작된 시간 
			// 시작 시간이 limit보다 적다면 i번째 log 끝 ~ 1초 사이에 있는 것
			int startTime = logTime[j] - processTime[j] + 1;
			if (startTime < limit) {
				cnt++;
			}
		}
		if (answer < cnt)
			answer = cnt;
	}

	return answer;
}

int main(void) {


	vector<string> v = {
		"2016-09-15 20:59:57.421 0.351s",
		"2016-09-15 20:59:58.233 1.181s",
		"2016-09-15 20:59:58.299 0.8s",
		"2016-09-15 20:59:58.688 1.041s",
		"2016-09-15 20:59:59.591 1.412s",
		"2016-09-15 21:00:00.464 1.466s",
		"2016-09-15 21:00:00.741 1.581s",
		"2016-09-15 21:00:00.748 2.31s",
		"2016-09-15 21:00:00.966 0.381s",
		"2016-09-15 21:00:02.066 2.62s"
	};

	cout << solution(v);

	return 0;
}
