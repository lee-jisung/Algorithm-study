#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>

using namespace std;

/*
   maxHeap.top 을 mid로 생각
   maxHeap 개수 = minHeap개수 일때 (홀수개)=> 새로 들어온 수가 mid보다 크면 새로운 수가 mid가 됨
     - 기존 mid를 minHeap으로 넘기고 새로운 수를 maxHeap에 push
	 - 새로운 수가 mid보다 작으면 그냥 max에 push

   maxHeap 개수 > minHeap 개수 일 때 (짝수개) => 새로운 수가 mid보다 작으면 새로운 수가 mid가 됨
     - 기존 mid를 minHeap으로 넘기고 새로운 수를 maxHeap에 push
	 - 새로운 수가 mid보다 크면 그냥 minHeap에 push
*/

int n;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num; cin >> num;
		
		if (maxHeap.empty() && minHeap.empty()) {
			maxHeap.push(num);
		}
		else {
			if (maxHeap.size() == minHeap.size()) {
				if (minHeap.top() < num) {
					int tmp = minHeap.top();
					minHeap.pop();
					minHeap.push(num);
					maxHeap.push(tmp);
				}
				else {
					maxHeap.push(num);
				}
			}
			else if (maxHeap.size() > minHeap.size()) {
				if (maxHeap.top() > num) {
					int tmp = maxHeap.top();
					maxHeap.pop();
					maxHeap.push(num);
					minHeap.push(tmp);
				}
				else {
					minHeap.push(num);
				}
			}
		}
		cout << maxHeap.top() << "\n";
	}
	return 0;
}
