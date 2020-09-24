#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   r, c / c, r을 vector에 넣고 
   i, j번째 스티커의 가로길이 합 <= 모눈종이 가로 && max(i세로, j세로) <= 모눈 세로 => 계산
   세로도 동일하게 계산

*/

struct sticker {
	int r, c;
	int idx;
};

int h, w, n;
int result;
vector<sticker> v;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w >> n;
	
	for (int i = 0; i < n; i++) {
		int r, c; cin >> r >> c;
		v.push_back({ r, c, i });
		v.push_back({ c, r, i });
	}

	for (int i = 0; i < v.size() - 1; i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].idx == v[j].idx) continue;
			if (v[i].r + v[j].r <= h && max(v[i].c, v[j].c) <= w) {
				result = max(result, (v[i].r * v[i].c + v[j].r * v[j].c));
			}

			if (v[i].r + v[j].r <= w && max(v[i].c, v[j].c) <= h) {
				result = max(result, (v[i].r * v[i].c + v[j].r * v[j].c));
			}
		}
	}

	cout << result << "\n";

	return 0;
}
