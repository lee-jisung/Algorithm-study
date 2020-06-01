#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 51
#define INF 1e9

using namespace std;

struct node {
	int r, c, s;
};

int n, m, k, result;
int board[SIZE][SIZE], temp[SIZE][SIZE];

vector<int> v;
vector<node> turning;

void copy() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			temp[i][j] = board[i][j];
}

// 배열 1칸씩 당겨오기
// s의 범위만큼 돌면 됨
void clockwise(int r, int c, int s) {

	for (int i = s; i >= 1; i--) {
		int str = r - i, stc = c - i;
		int endr = r + i, endc = c + i;
		int tmp = temp[str][stc];

		for (int j = str; j < endr; j++) 
			temp[j][stc] = temp[j + 1][stc];
		for (int j = stc; j < endc; j++)
			temp[endr][j] = temp[endr][j + 1];
		for (int j = endr; j > str; j--)
			temp[j][endc] = temp[j - 1][endc];
		for (int j = endc; j > stc+1; j--)
			temp[str][j] = temp[str][j - 1];
		temp[str][stc + 1] = tmp;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];

	for (int i = 0; i < k; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		turning.push_back({ r, c, s });
	}

	for (int i = 1; i <= k; i++)
		v.push_back(i);
	result = INF;
	
	// 회전 순서를 임의로 정해서 모든 경우마다 결과값계산
	do {
		copy();
		for (int i = 0; i < v.size(); i++) {
			auto cal = turning[v[i]-1];
			clockwise(cal.r, cal.c, cal.s);
		}
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				sum += temp[i][j];
			}
			result = min(result, sum);
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << result << "\n";

	return 0;
}
