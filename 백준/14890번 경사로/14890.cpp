#include <iostream>

using namespace std;

int n, l, load;
int map[101][101];
bool isVisit[101][101];

bool isRange(int x) {
	return x >= 0 && x < n;
}

int main(void) {

	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	// 행 확인
	for (int i = 0;i < n; i++) {
		bool isP = true;
		for (int j = 0; j < n-1; j++) {

			if (map[i][j] != map[i][j + 1]) { // 높낮이가 다를때
				if (map[i][j] - map[i][j + 1] == 1) { // 앞의 칸 높이가 더 높을 때

					// L 길이만큼 같은 높이 칸이 연속되어 있는지
					// 범위에 벗어나지 않는지
					// 이미 경사로를 지은곳인지 확인
					for (int k = 0; k < l;k++) { 
						if (map[i][j + 1] != map[i][j + 1 + k] || !isRange(j + 1 + k) || isVisit[i][j + 1 + k])
							isP = false;
					}
					// 만약 경사로를 짓는게 가능한 곳이라면
					// L 길이 만큼 경사로 지음
					if (isP) {
						for (int k = 0; k < l; k++)
							isVisit[i][j + 1 + k] = true;
					}

				}
				else if (map[i][j] - map[i][j + 1] == -1) { // 뒤의 칸 높이가 더 높을 때
					for (int k = 0; k < l;k++) {
						if (map[i][j] != map[i][j - k] || !isRange(j - k) || isVisit[i][j - k])
							isP = false;
					}
					if (isP) {
						for (int k = 0; k < l; k++)
							isVisit[i][j-k] = true;
					}
				}
				else isP = false; // 높낮이가 2 이상 차이질 때
			}
		}
		if (isP) {
			load++;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			isVisit[i][j] = false;

	// 열 확인
	for (int j = 0;j < n; j++) {
		bool isP = true;
		for (int i = 0; i < n-1; i++) {
			if (map[i][j] != map[i+1][j]) {

				if (map[i][j] - map[i+1][j] == 1) {

					for (int k = 0; k < l;k++) {
						if (map[i+1][j] != map[i+1+k][j] || !isRange(i + 1 + k) || isVisit[i + 1 + k][j])
							isP = false;
					}
					if (isP) {
						for (int k = 0; k < l; k++)
							isVisit[i + 1 + k][j] = true;
					}

				}
				else if (map[i][j] - map[i + 1][j] == -1) {
					for (int k = 0; k < l;k++) {
						if (map[i][j] != map[i - k][j] || !isRange(i - k) || isVisit[i - k][j])
							isP = false;
					}
					if (isP) {
						for (int k = 0; k < l; k++)
							isVisit[i - k][j] = true;
					}
				}
				else isP = false;
			}
		}
		if (isP)
			load++;
	}

	cout << load << "\n";

	return 0;
}
