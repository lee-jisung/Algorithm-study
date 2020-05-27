#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, result;
int inning[51][10], batter[10];
bool sel[10];


/*
   각 이닝마다 out count와 point[4]으로 점수와 진루 및 점수를 계산
   nextGame변수로 out count가 3이되면 true로 만들어 while을 탈출해 다음 이닝으로 넘김
 
   각 번호의 주자 타선을 batter[j]로 가져와 순서에 맞는 결과를 넣고
   아웃, 1루타, 2루타, 3루타, 홈런을 각각 처리
   point[1] = 1루, point[2] = 2루, point[3] = 3루
*/
int playGame() {

	int st = 1, score = 0;
	int point[4];

	for (int i = 1; i <= n; i++) {

		bool nextGame = false;
		int out = 0;
		memset(point, 0, sizeof(point));

		while (1) {

			for (int j = st; j <= 9; j++) {

				int res = inning[i][batter[j]];
				if (res == 0) out++;
				else if (res == 1) {
					
					for (int k = 3; k >= 1; k--) {
						if (point[k]) {
							if (k == 3) {
								point[k] = 0;
								score++;
							}
							else {
								point[k + 1] = 1;
								point[k] = 0;
							}
						}
					}
					point[1] = 1;

				}
				else if (res == 2) {

					for (int k = 3; k >= 1; k--) {
						if (point[k]) {
							if (k == 3 || k == 2) {
								score++;
								point[k] = 0;
							}
							else {
								point[k + 2] = 1;
								point[k] = 0;
							}
						}
					}
					point[2] = 1;
				}
				else if (res == 3) {
					for (int k = 3; k >= 1; k--) {
						if (point[k]) {
							score++;
							point[k] = 0;
						}
					}
					point[3] = 1;
				}
				else if (res == 4) {
					for (int k = 1; k <= 3; k++) {
						if (point[k]) {
							score++;
							point[k] = 0;
						}
					}
					score++;
				}

				if (out == 3) {
					nextGame = true;
					st = j + 1;
					break;
				}

			}
			if (nextGame) break;
			st = 1;
		}
	}
	return score;

}

void dfs(int no) {
	if (no == 10) {
	
		result = max(result, playGame());

		return;
	}

	for (int i = 1;i <= 9; i++) {
		if (!sel[i]) {
			sel[i] = true;
			batter[i] = no;
			dfs(no + 1);
			sel[i] = false;
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> inning[i][j];
		}
	}
	
	//4번 타자는 1번으로 고정
	batter[4] = 1;
	sel[4] = true;

	dfs(2);

	cout << result << "\n";

	return 0;
}
