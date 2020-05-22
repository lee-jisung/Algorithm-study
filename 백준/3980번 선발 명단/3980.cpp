#include <iostream>
#include <algorithm>

using namespace std;

int tc, result;
int position[11][11], sel[11];
bool isVisit[11];

/*
   dfs - 선수 i번째 선수의 능력치가 0 이상일 때 해당 포지션의 값을 sel[i]에 저장하고 해당 포지션은 이미 
         채워진것을 isVisit[i]로 표시
       - 모든 포지션에 1명씩들어가 있어야 하므로 sum[i]가 0이 한개라도 있다면 포지션이 겹치는 경우가 생기는 것이므로 
	     결과를 구하지 않고 return
*/

void dfs(int len) {

	if (len == 11) {
		int sum = 0;
		for (int i = 0; i < 11; i++) {
			if (sel[i] == 0) return;
			sum += sel[i];
		}
		result = max(result, sum);
		return;
	}

	for (int i = 0; i < 11; i++) {
		if (position[len][i] != 0 && !isVisit[i]) {
			sel[len] = position[len][i];
			isVisit[i] = true;
			dfs(len + 1);
			isVisit[i] = false;
		}
	}

}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {

		result = 0;
		for (int i = 0; i < 11; i++)
			for (int j = 0;j < 11;j++)
				cin >> position[i][j];

		dfs(0);

		cout << result << "\n";

	}
	return 0;
}
