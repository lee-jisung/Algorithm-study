#include <iostream>
#include <vector>

/*
   5 6 4 3 6 2 3 일 경우 작은 위치 아래로는 더이상 내려갈 수 없기 때문에
   5 5 4 3 3 2 2 로 나타낼 수 있음

   -> 맨 마지막부터 pizza가 들어갈 수 있는 위치에 넣어주고 모든 pizza가 다 들어갔으면 마지막 위치를 return
      그게 아니라면 0 return
*/

using namespace std;

int d, n;
int position;
vector<int> oven, pizza;

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> d >> n;
	for (int i = 0; i < d; i++) {
		int num; cin >> num; oven.push_back(num);
		if (i != 0 && oven[i] > oven[i - 1]) oven[i] = oven[i - 1];
	}
	for (int i = 0; i < n; i++) {
		int num; cin >> num; pizza.push_back(num);
	}

	int idx = 0;
	for (int i = d - 1; i >= 0; i--) {
		if (pizza[idx] <= oven[i]) {
			position = i + 1;
			idx++;
		}
		if (idx == n) break;
	}

	if (idx == n) cout << position << "\n";
	else cout << 0 << "\n";

	return 0;
}
