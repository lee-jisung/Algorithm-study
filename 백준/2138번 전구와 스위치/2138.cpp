#include <iostream>
#include <algorithm>
#include <string>

#define INF 1e9

using namespace std;

/*
   idx-1번째 스위치는 idx번째 스위치를 누를 때 최종 상태가 결정됨

   첫 번째 스위치를 눌렀을 때 vs 안눌렀을 때 비교
   2.모든 경우를 재귀호출 => 메모리 초과 => 현재 보는 인덱스 직전의 전구상태만 확인
     - 인덱스를 한번 지나가면 다시 돌아보지않기때문에 (인덱스 - 1)에 위치한 전구 상태를 보고 스위치 누를지 말지 결정
	 - (인덱스 - 1)에 위치한 전구 상태 == 목표 전구 (인덱스-1) 상태 라면 스위치 누르지 말고 다음 인덱스로 재귀호출
	 - 만약 다르다면 스위치를 누르고 재귀 호출  
   3. 인덱스가 n-1에 도착
     => 스위치를 누르지 않은 상태에서 목표와 같은지 확인
	 => 스위치를 한번 더 누르고 같은지 확인 
*/

int n, result;
string input, goal, compString;

// i-1, i, i+1번째 스위치 누르기
void pushSwitch(int idx) {
	if (idx > 0)
		compString[idx - 1] = (compString[idx - 1] == '0') ? '1' : '0';
	compString[idx] = (compString[idx] == '0') ? '1' : '0';
	if(idx < n-1)
		compString[idx + 1] = (compString[idx + 1] == '0') ? '1' : '0';
}

void simulateSwitch(int idx, int cnt) {
	if (idx == n - 1) {
		// 마지막 index에서 스위치 안누른 상태로 비교
		bool isSame = true;
		for (int i = 0; i < goal.length();i++) {
			if (compString[i] != goal[i]) {
				isSame = false;
				break;
			}
		}
		if (isSame) result = min(result, cnt);

		// 스위치 한번 더 누르고 비교
		isSame = true;
		pushSwitch(idx);
		for (int i = 0; i < goal.length(); i++) {
			if (compString[i] != goal[i]) {
				isSame = false;
				break;
			}
		}
		if (isSame) result = min(result, cnt + 1);
		return;
	}

	// 스위치 안누르고 탐색 vs 스위치 누르고 탐색 결정
	if (compString[idx - 1] == goal[idx - 1])
		simulateSwitch(idx + 1, cnt);

	pushSwitch(idx);// 스위치 누르기
	if (compString[idx - 1] == goal[idx - 1])
		simulateSwitch(idx + 1, cnt + 1);
	pushSwitch(idx); // 원상 복구
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> input >> goal;

	result = INF;

	// 첫번째 스위치 안누르고 탐색
	compString = input;
	simulateSwitch(1, 0);

	// 첫번째 스위치 누르고 탐색
	compString = input;
	pushSwitch(0);
	simulateSwitch(1, 1);
	
	if (result == INF)
		cout << -1 << "\n";
	else
		cout << result << "\n";

	return 0;
}
