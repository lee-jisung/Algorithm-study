#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 8
#define INF 987654321

using namespace std;

struct CCTV {
	int r;
	int c;
	int no;
	int dir;
};

int n, m, cctv_num, result;
int map[SIZE][SIZE], cctv_map[SIZE][SIZE];

vector<CCTV> v[SIZE];

void init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cctv_map[i][j] = map[i][j];
}

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < n && c < m;
}

void up(CCTV ct) {
	int r = ct.r, c = ct.c;
	for (int i = r - 1; i >= 0; i--) {
		if (cctv_map[i][c] == 6) break;
		if (cctv_map[i][c] == 0) cctv_map[i][c] = -1;
	}
}

void down(CCTV ct) {
	int r = ct.r, c = ct.c;
	for (int i = r + 1; i < n; i++) {
		if (cctv_map[i][c] == 6) break;
		if (cctv_map[i][c] == 0) cctv_map[i][c] = -1;
	}
}

void right(CCTV ct) {
	int r = ct.r, c = ct.c;
	for (int i = c + 1; i < m; i++) {
		if (cctv_map[r][i] == 6) break;
		if (cctv_map[r][i] == 0) cctv_map[r][i] = -1;
	}
}

void left(CCTV ct) {
	int r = ct.r, c = ct.c;
	for (int i = c - 1; i >= 0; i--) {
		if (cctv_map[r][i] == 6) break;
		if (cctv_map[r][i] == 0) cctv_map[r][i] = -1;
	}
}

// 처음 사각지대를 찾을 cctv_map을 초기화 하고
// cctv의 번호 마다 방향을 확인해서 감시 구역은 cctv_map에 -1로 표시
void blind_spot() {
	init();
	for (int i = 0; i < cctv_num; i++) {
		CCTV ct = v[i].back();

		switch (ct.no) {

		case 1:
			if (ct.dir == 0) right(ct);
			else if (ct.dir == 1) up(ct);
			else if (ct.dir == 2) left(ct);
			else down(ct);
			break;

		case 2:
			if (ct.dir == 0 || ct.dir == 2) {
				right(ct);
				left(ct);
			}
			else {
				up(ct);
				down(ct);
			}
			break;

		case 3:
			if (ct.dir == 0) {
				right(ct); up(ct);
			}
			else if (ct.dir == 1) {
				up(ct); left(ct);
			}
			else if (ct.dir == 2) {
				left(ct); down(ct);
			}
			else {
				down(ct); right(ct);
			}
			break;

		case 4:
			if (ct.dir == 0) {
				right(ct); up(ct); left(ct);
			}
			else if (ct.dir == 1) {
				up(ct); left(ct); down(ct);
			}
			else if (ct.dir == 2) {
				left(ct); down(ct); right(ct);
			}
			else {
				down(ct); right(ct); up(ct);
			}
			break;

		case 5:
			right(ct);
			up(ct);
			left(ct);
			down(ct);
			break;
		}
	}
}

// 사각지대 공간 count
int count_blind_spot() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cctv_map[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

// ** 재귀 핵심 부분
// vector에 cctv가 한대씩 저장되어 있고
// 재귀 호출을 하면서 cctv 번호마다 방향을 바꿔주고 
// cctv 개수만큼 방향을 바꿨으면 사각지대 찾음
// cnt --> 0 들어오면 
// 0번째가 방향 :0 되고 밑에 다시 호출되고
// 1번재가 방향 : 0이 되고 다시 밑에 호출되고 하는식으로 진행
void cctv_direction(int cnt) {

	if (cnt == cctv_num) {
		blind_spot();
		result = min(result, count_blind_spot());
		return;
	}

	v[cnt].back().dir = 0;
	cctv_direction(cnt + 1);

	v[cnt].back().dir = 1;
	cctv_direction(cnt + 1);

	v[cnt].back().dir = 2;
	cctv_direction(cnt + 1);

	v[cnt].back().dir = 3;
	cctv_direction(cnt + 1);

}

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6) {
				v[cctv_num].push_back({ i, j, map[i][j], -1 });
				cctv_num++;
			}
		}
	}

	for (int i = 0; i < cctv_num; i++) {

	}

	result = INF;
	cctv_direction(0);

	cout << result << "\n";

	return 0;
}
