#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/*
   stack에 벡터의 뒤에서부터 숫자를 넣어줌
   stack의 top이 자신보다 같거나 작은수면 큰수가 나올 때 까지 pop
	-> stack이 비어버리면 -1
	-> stack의 top이 자신보다 큰 수면 stack의 top을 result에 추가한 후 현재 값을 stack에 push
*/

int n;
stack<int> st;
vector<int> arr, result;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = arr.size() - 1; i >= 0; i--) {
		while (!st.empty() && st.top() <= arr[i]) {
			st.pop();
		}
		if (st.empty()) 
			result.push_back(-1);
		else
			result.push_back(st.top());
		st.push(arr[i]);
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i] << " ";
	}

	return 0;
}
