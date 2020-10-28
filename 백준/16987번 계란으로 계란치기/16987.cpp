#include <iostream>
#include <algorithm>

using namespace std;

int n, result;
int eggWeight[9], eggDurability[9];

void crashEgg(int cur, int ec) {
	if (cur == n) {
		result = max(result, ec);
		return;
	}

	// 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 넘어가는 경우
	if (eggDurability[cur] <= 0 || ec == n-1) crashEgg(cur + 1, ec);

	for (int i = 0; i < n; i++) {
		// 손에 든 계란으로 다른 깨지지 않은 계란을 치기
		// 내구도를 깎고, 깨진 계란 수를 추가해줌
		if (cur != i && eggDurability[i] > 0 && eggDurability[cur] > 0) {
			eggDurability[cur] -= eggWeight[i];
			eggDurability[i] -= eggWeight[cur];
			int cnt = 0;
			if (eggDurability[cur] <= 0) cnt++;
			if (eggDurability[i] <= 0) cnt++;
			crashEgg(cur + 1, ec + cnt);
			eggDurability[cur] += eggWeight[i];
			eggDurability[i] += eggWeight[cur];
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> eggDurability[i] >> eggWeight[i];
	}

	crashEgg(0, 0);

	cout << result << "\n";

	return 0;
}
