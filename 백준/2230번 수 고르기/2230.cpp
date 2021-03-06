#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100
#define INF 2000000000

using namespace std;

int n, m, result, x, y; 
vector<int> a;

/*
   배열 -> pointer를 2개 두고 각 구간을 설정해서 조건에 맞으면 앞 포인터를 한칸 뒤로 움직이고
           조건에 부합하지 않을 경우 뒤 포인터를 한칸씩 뒤로 움직이면서 조건 확인
*/

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	
	sort(a.begin(), a.end());
	result = INF;
	while (x < n && y < n) {
		// 차이가 m보다 작으면 충분히 큰 값이 될 때까지 y를 늘려줌
		if (a[y] - a[x] < m) {
			y++;
			continue;
		}
		// 차이가 m 이상인 것 중 가장 작은 것 --> 차이가 m이면 가장 작은 경우임
		if (a[y] - a[x] == m) {
			result = a[y] - a[x];
			break;
		}
		// m 이상인 경우중 가장 작은 것으로 계속 갱신
		result = min(result, a[y] - a[x]);
		x++;
	}

	cout << result << "\n";

	return 0;
}
