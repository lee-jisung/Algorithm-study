#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
    높이가 가장 높은 기둥, 첫 기둥, 끝 기둥 위치를 각각 찾음

	처음 가장 높은 기둥 값을 result에 더해주고 시작

	첫 기둥 ~ max 기둥 까지 stack을 이용해서 현재 기둥보다 높은 기둥이 나오면 push해주고 top을 계속 누적 합

	마지막 기둥 ~ max 기둥까지 위와 동일하게
*/

int n, result; 
int maxHeight, maxPos, startPos, endPos;
int height[1001];
stack<int> st;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, h; cin >> l >> h;
		height[l] = h;

		if (maxHeight < h) {
			maxHeight = h;
			maxPos = l;
		}
		if (!startPos || startPos > l) startPos = l;
		if (!endPos || endPos < l) endPos = l;
	}

	// max값 먼저 더하기
	result += maxHeight;

	// 출발 ~ max 기둥 까지 합
	for (int i = startPos; i < maxPos; i++) {
		if (height[i]) {
			if (st.empty() || st.top() < height[i]) {
				st.push(height[i]);
			}
		}
		result += st.top();
	}

	// stack clear
	while (!st.empty()) st.pop();

	// 마지막 ~ max 기둥 합
	for (int i = endPos; i > maxPos; i--) {
		if (height[i]) {
			if (st.empty() || st.top() < height[i]) {
				st.push(height[i]);
			}
		}
		result += st.top();
	}

	cout << result << "\n";

	return 0;
}
