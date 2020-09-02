#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
   공의 크기, 색, 누적합 관리 /
   색상 별 누적 합 관리 

   크기순으로 정렬

   현재의 공이 가질 수 있는 크기 => 현재까지의 누적합 - 같은색상의 누적합

   **이전 공과 크기가 같은공이라면 => 이전보다 작은 크기까지의 누적합 - 같은 색상 (이전보다 작은 크기까지) 누적 합 이 현재 크기가 가질 수 있는 크기
 
*/

struct ball {
	int idx;
	int color;
	int size;
	int sum;
};

struct color {
	int size;
	int sum;
	int before;
};

bool cmp(ball a, ball b) {
	return a.size < b.size;
}

bool cmp2(ball a, ball b) {
	return a.idx < b.idx;
}

int n;
int sum, before;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<ball> balls(n);
	vector<color> colors(n);

	for (int i = 0; i < n; i++) {
		balls[i].idx = i;
		cin >> balls[i].color >> balls[i].size;
	}

	sort(balls.begin(), balls.end(), cmp);

	for (int i = 0; i < n; i++) {
		int color = balls[i].color - 1;
		if (i > 0 && balls[i].size > balls[i - 1].size) {
			before = sum;
		}
		sum += balls[i].size;

		// 크기가 달라졋다면 
		// 현재 색의 최대 크기를 현재 볼의크기로
		// 현재까지 색의 크기 누적 => 현재까지 누적합
		if (balls[i].size > colors[color].size) {
			colors[color].size = balls[i].size;
			colors[color].before = colors[color].sum;
		}
		//b[i]의 색에 크기 누적
		colors[color].sum += balls[i].size;

		// ball의 현재 크기가 이전 크기보다 크다면
		// 현재까지 누적 합 - 해당 볼 색의 누적 합 이 현재 볼이 가질 수 있는 크기
		if (i > 0 && balls[i].size > balls[i - 1].size) {
			balls[i].sum = sum - colors[color].sum;
		}
		// 현재 크기가 이전과 동일하다면
		// 현재 크기보다 적은 크기까지의 누적 합 - 현재 볼 색의 적은크기까지 누적합
		else if (i > 0 && balls[i].size == balls[i - 1].size) {
			balls[i].sum = before - colors[color].before;
		}
	}

	sort(balls.begin(), balls.end(), cmp2);
	
	for (int i = 0; i < n; i++) {
		cout << balls[i].sum << "\n";
	}

	return 0;
}
