#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

const int target = 123456789;
int origin;
queue<int> q;
map<int, int> isVisit;

int dr[4] = { -1, 1, 0, 0 }, dc[4] = { 0, 0, -1, 1 };

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 9; i++) {
		int a; cin >> a;
		if (!a) a = 9; // 0 => 9로 바꿈 (수 조합 위해)
		origin *= 10; origin += a;
	}
	
	// 원래의 숫자를 넣고, isVisit => 해당 숫자를 몇번 만에 방문햇는지 count
	q.push(origin);
	isVisit[origin] = 0;

	while (!q.empty()) {

		int cur = q.front();
		string str = to_string(cur);
		q.pop();

		// 9가 몇번째 index에 위치한지 찾음
		int idx = str.find('9');
		// 3 x 3 board에서 index를 기준으로 /3을 하면 r, %3을하면 c 좌표를 구할 수 있음
		int r = idx / 3;
		int c = idx % 3;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;
			string cmp = str;
			// r * 3 + c => 원래의 인덱스 값이 나옴
			// nr * 3 + nc => 바꾸고자 하는 인덱스의 값
			swap(cmp[r * 3 + c], cmp[nr * 3 + nc]);

			// 위치를 바꾼 수를 방문했던 적이 있으면 pass
			int num = stoi(cmp);
			if (isVisit.count(num)) continue;
			isVisit[num] = isVisit[cur] + 1;
			q.push(num);
		}
	}

	// 123456780의 조합을 방문한적이 없으면 -1, 방문햇다면 몇번만에 했는지 출력
	if (isVisit.count(target)) {
		cout << isVisit[target] << "\n";
	}
	else {
		cout << "-1\n";
	}
	
	return 0;
}
