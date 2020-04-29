#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 1001
#define INF 987654321

using namespace std;

int psize, n, m, result; 
int front, rear, temp;
int a[SIZE], b[SIZE];

vector<int> va, vb;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> psize;
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	va.push_back(0); vb.push_back(0);

	front = rear = temp = 0;
	while (front < m) {

		temp += a[rear++];
		if (temp <= psize) va.push_back(temp);
		else {
			front++;
			rear = front;
			temp = 0;
		}
		// 원형 배열로 포인터를 맨 처음으로 위치시킴
		if (rear == m) rear = 0; 
		// 배열의 전체 합 중복 방지
		if ((!rear && !front) || rear + 1 == front) {
			front++;
			rear = front;
			temp = 0;
		}
	}

	front = rear = temp = 0;
	while (front < n) {

		temp += b[rear++];
		if (temp <= psize) vb.push_back(temp);
		else {
			front++;
			rear = front;
			temp = 0;
		}

		if (rear == n) rear = 0;
		if ((!rear && !front) || rear + 1 == front) {
			front++;
			rear = front;
			temp = 0;
		}
	}

	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	for (int i = 0; i < va.size(); i++) {

		front = lower_bound(vb.begin(), vb.end(), psize - va[i]) - vb.begin();
		rear = upper_bound(vb.begin(), vb.end(), psize - va[i]) - vb.begin();

		result += rear - front;
	}

	cout << result << "\n";
	return 0;
}
