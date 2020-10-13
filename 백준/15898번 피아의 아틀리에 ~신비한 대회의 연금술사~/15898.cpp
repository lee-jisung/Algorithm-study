#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
   1. 재료를 입력받으면서 4방향 회전한것을 배열에 담기
   2. 가마 상태를 매개변수로 넘기면서 변화되는 상태를 유지
   3. 00, 01, 10, 11 마다 4방향의 재료를 3가지 넣을 것 (순서도 모두 다르게)
	  putMaterial => 가마에 재료를 넣은 후의 가마 상태를 반환
   4. getQuality를 통해 점수를 얻어옴
*/

struct Qual {
	int qual;
	char ele;
};

int n, isSelect[10], result;
int materialQuality[10][4][4][4];
char materialElement[10][4][4][4];
vector<vector<Qual>> gama(5, vector<Qual>(5));

void rotateMaterial(int idx, int dir) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			materialQuality[idx][dir + 1][j][4 - i - 1] = materialQuality[idx][dir][i][j];
			materialElement[idx][dir + 1][j][4 - i - 1] = materialElement[idx][dir][i][j];
		}
	}
}

vector<vector<Qual>> putMaterial(vector<vector<Qual>> v, int r, int c, int idx, int dir) {

	for (int i = r; i < r + 4; i++) {
		for (int j = c; j < c + 4; j++) {
			v[i][j].qual += materialQuality[idx][dir][i - r][j - c];
			if (v[i][j].qual > 9) v[i][j].qual = 9;
			else if (v[i][j].qual < 0) v[i][j].qual = 0;

			if (materialElement[idx][dir][i - r][j - c] != 'W') {
				v[i][j].ele = materialElement[idx][dir][i - r][j - c];
			}
		}
	}
	return v;
}

int getMaterial(vector<vector<Qual>> v) {
	int r = 0, b = 0, g = 0, y = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			switch (v[i][j].ele) {
			case 'R':
				r += v[i][j].qual;
				break;
			case 'B':
				b += v[i][j].qual;
				break;
			case 'G':
				g += v[i][j].qual;
				break;
			case 'Y':
				y += v[i][j].qual;
				break;
			}
		}
	}
	return 7 * r + 5 * b + 3 * g + 2 * y;
}

void selectMaterial(vector<vector<Qual>> g, int cnt) {
	if (cnt == 3) {
		result = max(result, getMaterial(g));
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isSelect[i]) continue;
		isSelect[i] = true;

		for (int r = 0; r < 2; r++) {
			for (int c = 0; c < 2; c++) {
				for (int d = 0; d < 4; d++) {
					vector<vector<Qual>> tmp = putMaterial(g, r, c, i, d);
					selectMaterial(tmp, cnt + 1);
				}
			}
		}

		isSelect[i] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			gama[i][j].ele = 'W';

	for (int k = 0; k < n; k++) {

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4;j++)
				cin >> materialQuality[k][0][i][j];

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4;j++)
				cin >> materialElement[k][0][i][j];

		for (int d = 0; d < 3; d++)
			rotateMaterial(k, d);
	}

	selectMaterial(gama, 0);

	cout << result << "\n";

	return 0;
}
