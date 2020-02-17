#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>

#define SIZE 101
#define INF 987654321

using namespace std;

struct shark {
	int r;
	int c;
	int s;
	int d;
	int z;
	bool move;
};

int pos, r, c, m, result;
vector<shark> map[SIZE][SIZE];

// 1. 낚시왕 오른쪽으로 한칸씩(열) 이동 --> 해당 열에서 가장 가까운 위치의 상어 잡음
// 2. 상어 이동 --> 모든 상어를 각자 방향과 이동 칸수 만큼 이동시킨 후 해당 칸에 상어가 2마리 이상이면 크기가 큰 상어가 
// 나머지를 모두 먹음
// * 경계선이 다음이면 방향을 바꾸고 그 다음 한칸을 가야 +1이 된거
// ** 같은 크기 상어 없고, 하나에 2개 이상 상어가 주어지는 경우 없음

// 가장 오른쪽 열까지 낚시왕이 이동한 후 종료

// 각각 방향마다 속력만큼 이동하고 끝까지 가거나 방향을 바꿔야하면 바꾸고
// 열이나 행의 끝칸까지 가지 않을 정도면 방향은 유지한채 좌표만 수정
shark up(shark s) {

	if ((s.r - 1) < s.s) {
		s.s -= (s.r - 1);
		s.r = 1;
		s.d = 2;
	}
	else {
		s.r -= s.s;
		s.s = 0;
		if (s.r == 1) s.d = 2;
		else s.d = 1;
	}
	return s;
}

shark down(shark s) {

	if (r - s.r < s.s) {
		s.s -= (r - s.r);
		s.r = r;
		s.d = 1;
	}
	else {
		s.r += s.s;
		s.s = 0;
		if (s.r == r) s.d = 1;
		else s.d = 2;
	}
	return s;

}

shark right(shark s) {

	if (c - s.c < s.s) {
		s.s -= (c - s.c);
		s.c = c;
		s.d = 4;
	}
	else {
		s.c += s.s;
		s.s = 0;
		if (s.c == c) s.d = 4;
		else s.d = 3;
	}
	return s;

}

shark left(shark s) {

	if ((s.c - 1 ) < s.s) {
		s.s -= (s.c - 1);
		s.c = 1;
		s.d = 3;
	}
	else {
		s.c -= s.s;
		s.s = 0;
		if (s.c == 1) s.d = 3;
		else s.d = 4;
	}
	return s;
}

// 이동 
void shark_move(shark s) {

	shark temp;
	temp = s;

	// temp를 이동
	while (temp.s) {

		switch (temp.d) {
		case 1:
			temp = up(temp);
			break;
		case 2:
			temp = down(temp);
			break;
		case 3:
			temp = right(temp);
			break;
		case 4:
			temp = left(temp);
			break;
		}
	}

	s.r = temp.r;
	s.c = temp.c;
	s.d = temp.d;
	s.move = true;
	map[s.r][s.c].push_back(s);

}

void init() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (!map[i][j].empty()) {
				map[i][j].back().move = false;
			}
		}
	}
}

int main(void) {
	
	cin >> r >> c >> m;
	for (int i = 0; i < m; i++) {
		shark s;
		cin >> s.r >> s.c >> s.s >> s.d >> s.z;
		map[s.r][s.c].push_back(s);
	}

	while (pos < c) {
		pos++; // 낚시왕 열 위치
		init();

		// 상어 잡기
		for (int i = 1; i <= r; i++) {
			if (!map[i][pos].empty()) {
				result += map[i][pos].front().z;
				map[i][pos].pop_back();
				break;
			}
		}
		// 상어 이동

		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {

				if (!map[i][j].empty()) {

					vector<shark> v;
					int size = map[i][j].size();
					for (int k = 0; k < size; k++) {
						shark s = map[i][j].back();
						map[i][j].pop_back();
						if (!s.move) 
							shark_move(s);
						else 
							v.push_back(s);
					}
					for (int k = 0;k < v.size(); k++)
						map[i][j].push_back(v[k]);
				}
			}
		}

		// 상어 먹기
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				shark temp;
				temp.z = 0;
				if (map[i][j].size() >= 2) {
					for (int k = 0; k < map[i][j].size(); k++) {
						if (temp.z < map[i][j][k].z)
							temp = map[i][j][k];
					}
					map[i][j].clear();
					map[i][j].push_back(temp);
				}
			}
		}

	}
	
	cout << result << "\n";

	return 0;
}
