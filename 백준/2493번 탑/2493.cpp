#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

/*
   i번째 높이 탐색 -> stack에 들어가 있는 것의 높이보다 현재 높이가 더 높다면 stack의 내용을 계속 pop
   현재 높이보다 높은 것이 stack에 있으면 해당 stack의 top에서 index값 출력 후 현재 높이 및 index값 stack에 push
   만약 stack이 비어있다면 현재 빌딩보다 높은게 없는것 --> 0 출력

*/

int n;
stack<pair<int, int>> st;
vector<int> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for (int i = 0; i < n; i++) {

		while (!st.empty() && st.top().second < v[i]) 
			st.pop();
		if (st.empty()) 
			cout << 0 << " ";
		else 
			cout << st.top().first << " ";
		st.push({ i + 1, v[i] });
	}

	return 0;
}
