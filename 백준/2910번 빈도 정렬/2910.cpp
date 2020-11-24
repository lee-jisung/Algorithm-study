#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
   빈도가 같으면 index가 앞선 순으로 출력
*/

struct node {
	int val;
	int freq;
	int idx;
};

int n, c;
map<int, int> freq, idx;
vector<node> v;

bool cmp(node a, node b) {
	if (a.freq == b.freq) 
		return a.idx < b.idx;
	return a.freq > b.freq;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		freq[num]++;
		if (idx[num] == 0) idx[num] = (i + 1);
	}

	for (auto iter = freq.begin(); iter != freq.end(); iter++) {
		v.push_back({ iter->first, iter->second, idx[iter->first] });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		int frequency = v[i].freq;
		for (int j = 0; j < frequency; j++)
			cout << v[i].val << " ";
	}

	return 0;
}
