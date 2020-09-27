#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, m; 
map<int, int> post, pic;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.first == b.first)
		return a.second.second < b.second.second;
	return a.first < b.first;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int num; cin >> num;

		// 사진틀 다 찬 상태에서 새로운 학생 추천받을 때
		if (pic.size() == n && !pic.count(num)) {
			vector<pair<int, pair<int, int>>> v;
			for (auto iter = pic.begin(); iter != pic.end(); iter++)
				v.push_back({ iter->second, {iter->first, post[iter->first]} }); // {추천수, {학생번호, 게시된시점}}
			sort(v.begin(), v.end(), cmp); // 추천수 적은순 (같다면 게시된 시점이 적은순)
			int idx = v[0].second.first;

			//기존 학생 지우고 새롭게 추가
			pic.erase(idx);
			post.erase(idx);
			pic[num]++;
			post[num] = i;
		}
		else {
			// 기존 학생 추천받을 때
			pic[num]++;
			// 게시된 시점 
			if (!post.count(num))
				post[num] = i;
		}
	}

	for (auto iter = pic.begin(); iter != pic.end(); iter++)
		cout << iter->first << " ";
	cout << "\n";
	return 0;
}
