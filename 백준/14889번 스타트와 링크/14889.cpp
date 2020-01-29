#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, st, li;
int min_diff = 1000;
int level[20][20];

vector<int> c;

// n/2로 팀을 나눠야하므로 각 팀을 나눌 경우의 수를
// next_permutation으로 구한 후에 각 팀에 맞게 백터에 넣고
// 해당 팀에 맞는 점수를 더해서 차이를 전부 구하여 가장 최소값 찾음

int main(void) {

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n;j++)
			cin >> level[i][j];

	for (int i = 0; i < n / 2; i++)
		c.push_back(0);
	for (int i = 0; i < n / 2; i++)
		c.push_back(1);


	do {
		st = li = 0;
		vector<int>  stv, liv;
		for (int i = 0; i < n; i++) {
			if (c[i])
				stv.push_back(i);
			else
				liv.push_back(i);
		}

		for (int i = 0; i < stv.size();i++) {
			for (int j = 0; j < stv.size(); j++) {
				st += level[stv[i]][stv[j]];
			}
		}
		for (int i = 0; i < liv.size();i++) {
			for (int j = 0; j < liv.size(); j++) {
				li += level[liv[i]][liv[j]];
			}
		}
		if (min_diff > abs(st - li)) min_diff = abs(st - li);
		
	} while (next_permutation(c.begin(), c.end()));

	cout << min_diff << "\n";

	return 0;
}
