#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
   정사각형 가능한 모든 크기를 탐색 => n, m 중 크기가 작은 것을 정사각형 크기의 limit으로 설정
   크기 1x1 ~ limit x limit까지 
   탐색가능한 영역에 대해서 모든 점을 탐색
*/

int n, m, result;
int square[51][51];

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++)
			square[i][j] = s[j] - '0';
	}

	int len = min(n, m);

	for (int r = 0; r < len; r++) {
		for (int i = 0; i < n - r; i++) {
			for (int j = 0; j < m - r; j++) {
				if (square[i][j] == square[i + r][j] && square[i][j] == square[i][j + r] && square[i][j] == square[i + r][j + r]) {
					result = max(result, (r+1) * (r+1));
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}
