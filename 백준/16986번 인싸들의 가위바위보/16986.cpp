#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
   1, 2, 3 순서로 진행 => 1 vs 2 해서 이긴사람이 그 다음사람과 붙음
   ex) 1 vs 2 (1승) => 1 vs 3 (3승) => 3 vs 2 이런식으로 ==> 다음 사람을 구하는법 = 3 - p1 - p2
*/

int n, k;
int adj[10][10];
bool isWin;
vector<int> v[3];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> adj[i][j];

	for (int i = 1; i <= n; i++) v[0].push_back(i);
	for (int i = 0; i < 20; i++) {
		int tmp; cin >> tmp;
		v[1].push_back(tmp);
	}
	for (int i = 0; i < 20; i++) {
		int tmp; cin >> tmp;
		v[2].push_back(tmp);
	}
	// 모든 경우 다르게 내야하는데, n번보다 k가 많을 경우 불가
	if (n < k) {
		cout << 0 << "\n";
		return 0;
	}

	do {
		int player1 = 0, player2 = 1;
		vector<int> win(3, 0);
		vector<int> nextIdx(3, 0); // 다음 것을 낼 순서

		while (1) {

			if (player1 > player2) swap(player1, player2);

			// 20경기보다 많이 하게 되는 경우 break
			if (nextIdx[player1] >= v[player1].size()) break;
			if (nextIdx[player2] >= v[player2].size()) break;

			int P1 = v[player1][nextIdx[player1]];
			int P2 = v[player2][nextIdx[player2]];

			nextIdx[player1]++;
			nextIdx[player2]++;

			if (adj[P1][P2] == 2) {// p1이 p2이김
				win[player1]++;
				player2 = 3 - player1 - player2;
			}
			else {// p2가 p1 이기거나 비겻으므로 p2 승
				win[player2]++;
				player1 = 3 - player1 - player2;
			}

			if (win[0] >= k) { // 지우가 k번 이겻을 때
				isWin = true;
				break;
			}
			else if (win[1] >= k || win[2] >= k) break; // 지우 이외 다른 두 사람이 k번 이기면 바로 다음 경우로
		}
		if (isWin) break;
	} while (next_permutation(v[0].begin(), v[0].end())); // 지우가 낼 수 있는 경우 모두 탐색

	cout << isWin << "\n";

	return 0;
}
