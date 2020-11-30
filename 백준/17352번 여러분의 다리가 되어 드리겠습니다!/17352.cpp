#include <iostream>

using namespace std;

/*
   1 ~ N 번 섬이 있을 때 어떤 형태든, 
   
   1번으로 연결된 섬들 / 임의의 번호로 연결된 섬들 2가지로 나뉘게 될것
    => 이유는 union 할 때 무조건 번호가 적은 쪽으로 합치기 때문

   => 1번과 임의의 섬으로 연결하면 끝 
*/

int n;
int bridge[300001];

int getBridge(int x) {
	if (bridge[x] == x) return x;
	return bridge[x] = getBridge(bridge[x]);
}

void unionBridge(int a, int b) {
	a = getBridge(a);
	b = getBridge(b);
	if (a < b) bridge[b] = a;
	else bridge[a] = b;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) bridge[i] = i;
	
	for (int i = 0; i < n - 2; i++) {
		int a, b; cin >> a >> b;
		unionBridge(a, b);
	}
	for (int i = 2; i <= n; i++) {
		int idx = getBridge(i);
		if (idx != 1) {
			cout << 1 << " " << idx << "\n";
			break;
		}
	}

	return 0;
}
