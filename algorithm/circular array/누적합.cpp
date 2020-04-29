#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
  https://www.acmicpc.net/problem/2632
  
  a 배열을 원형 큐로 생각하여 각 요소 별로 누적 합을 더해 target값을 이루는 경우의 수를 찾는 법
  
  front, rear를 두어 원형 큐 처럼 rear를 이동시키면서 배열의 요소들의 합을 누적하고 
  rear가 a배열의 크기를 벗어나면 rear값을 0으로 만들어 원형배열처럼 포인터를 이동시킴
  
  front는 각 배열 요소 합의 시작점을 의미 --> front가 a배열 크기를 벗어나면 종료
  
  배열의 합이 target보다 작거나 같은 경우에 va 백터에 모두 넣어주고
  만약 target보다 커지는 순간 front를 1 증가시켜 포인터를 이동시켜주고 새로운 경우의 수를 찾음
  
*/

int target = 7, front, rear, temp;
int a[5] = {2, 2, 1, 7, 2}; 
vector<int> va;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	va.push_back(0); vb.push_back(0);

	front = rear = temp = 0;
	while (front < 5) {

		temp += a[rear++];
		if (temp <= target) va.push_back(temp);
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
  
  return 0;
}
