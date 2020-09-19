#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
   몬스터와 만났을 때 => -1을 해주는 이유: HP = 1, 공격력 =1 같은 경우를 예외처리해주기 위해

   curHp -=  1 / 1 *stg.a => stg.a만큼 마이너스가 됨 ==> 하지만 실제로는 공격만하고 끝났기 때문에 curHp -= 0/1 * stg.a여야 함
   
   */

struct STAGE {
	int t, a, h;
};

int n, hatk;
long long result;
vector<STAGE> stage[123457];

bool clearStage(long long hp) {

	long long curHp = hp;
	long long curAtk = hatk;

	for (int i = 0; i < n; i++) {

		STAGE stg = stage[i][0];

		if (stg.t == 1) {
			if(((stg.h -1) / curAtk) > ((curHp-1) / stg.a)) return false;
			curHp -= ((stg.h - 1)/ curAtk) * stg.a;
		}
		else {
			curAtk += stg.a;
			curHp = min(curHp + stg.h, hp);
		}
	}
	return true;
}

void binary_search(long long st, long long ed) {
	if (st > ed) return;

	long long mid = (st + ed) / 2;
	if (clearStage(mid)) {
		result = mid;
		binary_search(st, mid - 1);
	}
	else {
		binary_search(mid+1, ed);
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long maxHp = 1e18;

	cin >> n >> hatk;

	for (int i = 0; i < n; i++) {
		int t, a, h; cin >> t >> a >> h;
		stage[i].push_back({ t, a, h });
	}

	binary_search(1, maxHp);

	cout << result << "\n";

	return 0;
}

// O(n) 풀이


//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main() {
//	ios::sync_with_stdio(false);
//
//	long long n, attack;
//	long long cur = 0, mx = 0;
//	cin >> n >> attack;
//
//	while (n--) {
//		int t, a, h;
//		cin >> t >> a >> h;
//		if (t == 1) {
//			long long damage = a * (ceil((double)h / attack) - 1);
//			if (damage > cur)mx += damage - cur, cur = 0;
//			else cur -= damage;
//		}
//		else {
//			attack += a;
//			cur += h;
//			if (cur > mx)cur = mx;
//		}
//	}
//	cout << mx + 1 << endl;
//}
