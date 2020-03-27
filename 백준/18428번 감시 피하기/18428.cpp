#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 6
#define INF 987654321

using namespace std;

int n, cnt;
char map[SIZE][SIZE];
int check[SIZE][SIZE];

vector<int> v;
vector<pair<int, int> > pos;

void init() {
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'T') check[i][j] = 1;
			else if (map[i][j] == 'S') check[i][j] = 2;
			else check[i][j] = 0;
		}
	}
}

// T가 있는 자리에서 장애물을 만나기 전 학생 만나면 return false
// 모두 통과하면 return true
bool detect() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j] == 1) {
				int nr = i, nc = j;
				while (nr >= 0) {
					nr--;
					if (check[nr][nc] == -1) break;
					if (check[nr][nc] == 2) return false;
				}
				nr = i;
				while (nr < n) {
					nr++;
					if (check[nr][nc] == -1) break;
					if (check[nr][nc] == 2) return false;
				}
				nr = i;
				while (nc >= 0) {
					nc--;
					if (check[nr][nc] == -1) break;
					if (check[nr][nc] == 2) return false;
				}
				nc = j;
				while (nc < n) {
					nc++;
					if (check[nr][nc] == -1) break;
					if (check[nr][nc] == 2) return false;
				}
			}
		}
	}
	return true;
}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			pos.push_back({ i,j });
		}

	for (int i = 0; i < n * n - 3; i++)
		v.push_back(0);
	for (int i = 0; i < 3;i++)
		v.push_back(1);

	do {
		init();
		// 장애물 만들 좌표 3개 선택
		for (int i = 0; i < v.size(); i++) {
			if (v[i] && !check[pos[i].first][pos[i].second]) {
				check[pos[i].first][pos[i].second] = -1;
				cnt++;
			}
		}
		// 장애물이 3개가 완성되고 감시를 피한다면
		if (cnt == 3 && detect()) {
			cout << "YES\n";
			return 0;
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << "NO\n";

	return 0;
}
