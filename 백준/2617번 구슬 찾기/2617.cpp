#include <iostream>
#include <vector>
#include <cstring>

#define SIZE 100

using namespace std;

int n, m, cnt1, cnt2, result;
int big[SIZE], small[SIZE];
bool isVisit[SIZE];
vector<int> bigger[SIZE], smaller[SIZE];

/*
   큰 것, 작은 것을 기준으로 graph 만듦 ( ex, 4 > 3일 때, bigger에서는 4 -> 3/ smaller에서는 3 -> 4

   그리고 각각의 graph를 dfs로 탐색하면서 연결된 요소가 몇개인지 찾아 big, small 배열에 update

   big, small의 값이 (n+1)/2와 같거나 큰것이 있다면 제외할 구술 숫자 ++
*/

void big_dfs(int idx) {
	
	isVisit[idx] = true;
	for (int i = 0; i < bigger[idx].size(); i++) {
		int next = bigger[idx][i];
		if (!isVisit[next]) {
			cnt1++;
			big_dfs(next);
		}
	}
}

void small_dfs(int idx) {

	isVisit[idx] = true;
	for (int i = 0; i < smaller[idx].size(); i++) {
		int next = smaller[idx][i];
		if (!isVisit[next]) {
			cnt2++;
			small_dfs(next);
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		int a, b;
		cin >> a >> b;
		bigger[a].push_back(b);
		smaller[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		memset(isVisit, false, sizeof(isVisit));
		cnt1 = cnt2 = 0;
		big_dfs(i); big[i] = cnt1;
		memset(isVisit, false, sizeof(isVisit));
		small_dfs(i); small[i] = cnt2;
	}

	for (int i = 1; i <= n; i++) {
		if (big[i] >= (n + 1) / 2) result++;
		else if (small[i] >= (n + 1) / 2) result++;
	}
	cout << result << "\n";
	return 0;
}
