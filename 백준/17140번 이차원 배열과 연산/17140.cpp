#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>

#define SIZE 100
#define INF 987654321

using namespace std;

int r, c, k, time;
int row_no, col_no;
int cnt[101];
vector<int> arr[SIZE];

// 정렬: 각 수의 등장횟수 기준으로 오름차순 정렬 ( 등장횟수가 같다면 수의 크기로 오름차순 정렬 ) 
// 수와 등장횟수를 같이 배열에 삽입
// ex) [3, 1, 1] --> 3:1번 1:2번 --> [3 1 1 2]
// [3 1 1 2] --> 3 1번 1 2번 2 1번 --> [2 1 3 1 1 2] 
// R - 행에 대해서 / C - 열에 대해서
// R, C를 모두 하고 난 후 가장 큰 행, 열에 대해서 size를 확장, 빈곳은 0으로 채움
// 정렬시 0은 무시
// 크기가 100을 넘어가면 처음 100개 이외의 것은 제외

// 최소 시간이니 R, C를 각각 연산했을때 마다 1초를 더해주고
// 행 개수 >= 열 -> R
// 행 < 열 ==> C연산
// A[r][c]가 맞을 때 return해줘서 시간 출력

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void calculation_R(int row) {

	int length = 0, len;
	if (row > 100)
		row = 100;

	for (int i = 0; i < row; i++) {
		vector<pair<int, int > > v;
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] != 0)
				cnt[arr[i][j]]++;
		}

		for (int j = 1; j < 101; j++) 
			if (cnt[j]) {
				v.push_back(make_pair(j, cnt[j]));
			}

		sort(v.begin(), v.end(), cmp);

		arr[i].clear();
		for (int j = 0;j < v.size(); j++) {
			if (arr[i].size() > 100) break;
			arr[i].push_back(v[j].first);
			if (arr[i].size() > 100) break;
			arr[i].push_back(v[j].second);
		}

		len = arr[i].size();
		length = max(length, len);
	}

	for (int i = 0; i < row; i++) {
		len = arr[i].size();
		if (len < length) {
			for (int j = 0; j < length - len; j++)
				arr[i].push_back(0);
		}
	}
}

void calculation_C(int row, int col) {

	vector<int> ar[SIZE];
	int length = 0, len;
	if (col > 100)
		col = 100;

	for (int i = 0; i < col; i++) {
		vector<pair<int, int > > v;
		memset(cnt, 0, sizeof(cnt));

		for (int j = 0; j < row; j++) {
			if(arr[j][i] != 0)
				cnt[arr[j][i]]++;
		}

		for (int j = 1; j < 101; j++)
			if (cnt[j]) {
				v.push_back(make_pair(j, cnt[j]));
			}

		sort(v.begin(), v.end(), cmp);

		for (int j = 0;j < v.size(); j++) {
			if (ar[i].size() > 100) break;
			ar[i].push_back(v[j].first);
			if (ar[i].size() > 100) break;
			ar[i].push_back(v[j].second);
		}
		len = ar[i].size();

		length = max(length, len);
		if (length > 100) length = 100;
	}
	// ar -> 행이 col이고 열 최고길이가 legnth가 되겟네

	for (int i = 0; i < row; i++)
		arr[i].clear();

	for (int i = 0; i < col; i++) {
		len = ar[i].size();
		if (len < length) {
			for (int j = 0; j < length - len; j++)
				ar[i].push_back(0);
		}
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < length; j++) {
			arr[j].push_back(ar[i][j]);
		}
	}

}

int main(void) {
	
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= 3; j++) {
			int temp;
			cin >> temp;
			arr[i].push_back(temp);
		}
	}

	while (1) {

		row_no = 0;
		for (int i = 0; i < SIZE; i++) {
			if (arr[i].empty()) break;
			row_no++;
		}

		col_no = arr[0].size();

		if(row_no >= r && col_no >= c)
			if (arr[r-1][c-1] == k)
				break;

		if (time > 100) {
			time = -1;
			break;
		}

		if (row_no >= col_no)
			calculation_R(row_no);
		else
			calculation_C(row_no, col_no);

		row_no = 0;
		for (int i = 0; i < 100; i++) {
			if (arr[i].empty()) break;
			row_no++;
		}
		col_no = arr[0].size();
		time++;
	}
	
	cout << time << "\n";

	return 0;
}
