#include <iostream>

using namespace std;

/*
  각 행에서 그 행의 전구를 켜려면 그 행에 꺼져 있는 열의 스위치를 모두 눌러야 함
  초기 상태가 다른 두 임의의 a, b 행은 절대 동시에 켜져 있는 행이 될 수 없음
  따라서 k번 눌러 켜져있게 만들 수 있는 행들에 대해서, 초기 상태가 가장 많이 동일한 것의 개수를 반환

  즉, 각 행마다 0의 개수를 세어서 0의 개수가 k개 이하이고 (k %2)와 (0 개수 % 2)가 동일하면
  나머지 행 들 중 그 행과 동일한 것의 개수를 세어서 최대값을 반환하면 됨

  1) 해당 행에 있는 0의 개수와 k가 2로 나눈 나머지가 동일한지?
  2) 그 행에 있는 0의 개수가 k개 이하인지?
*/

int n, m, k, result;
string lamp[51];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> lamp[i];
	cin >> k;

	for (int i = 0; i < n; i++) {

		int cnt = 0, rows = 0;
		for (int j = 0; j < m; j++)
			if (lamp[i][j] == '0') cnt++;

		if (cnt <= k && k % 2 == cnt % 2) {
			for (int j = 0;j < n; j++) {
				if (lamp[i] == lamp[j]) rows++;
			}
			if (result < rows) result = rows;
		}
	}
	cout << result << "\n";

	return 0;
}
