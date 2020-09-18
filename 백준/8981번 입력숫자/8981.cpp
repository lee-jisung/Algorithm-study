#include <iostream>
#include <vector>

using namespace std;

/*
   입력값 x로부터 출력값 y를 얻음 => y를 이용해 x를 구하기

   Y = [1, 2, 4, 8, 6, 3, 7, 5, 10, 9]
   
   to: X's index
   value: Y[i] 

   X[to] = value; 
   next to = (to + value) % n;

   만일 X에서 값이 0이 아니라면 한칸씩 증가시키면서 0인 index를 찾아 to로 설정
*/

int n;
int value, to, cnt;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<int> v(n), origin(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	cout << n << "\n";
	value = v[cnt];
	while (cnt < n) {
		while (origin[to] != 0) {
			to = (to + 1) % n;
		}
		origin[to] = value;
		cnt++;
		to = (value + to) % n;
		if (cnt >= n) break;
		value = v[cnt];
	}

	for (int i = 0; i < n; i++) cout << origin[i] << " ";
	cout << "\n";
	return 0;
}
