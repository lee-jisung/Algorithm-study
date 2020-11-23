#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/*
   n^3 풀이
   - input 길이만큼 반복문 돌리고
   - 아직 추가하지 않은 문자들에 대해서 반복문 돌리면서
   - 이미 추가되어있던 문자와 아직 추가하지 않은 문자를 추가하여 만든 문자열을 벡터에 추가,
	 (추가하지 않은 문자에 대한 index도 추가 => 방문처리 위해서)
   - 벡터를 정렬한 다음 가장 앞선 문자열을 추가하고, 새롭게 추가된 문자 index를 방문처리 해줌
*/

string input;
bool isVisit[101];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		vector<pair<string, int>> v;
		// j번 째 문자 확인
		for (int j = 0; j < input.length(); j++) {
			if (isVisit[j]) continue; // 이전에 처리한 문자면 pass

			string tmp = "";
			for (int k = 0; k < input.length(); k++) {
				// j번째 문자 or 이미 처리했던 문자를 추가
				if (j == k || isVisit[k]) {
					tmp += input[k];
				}
			}
			// j번째 index와 문자열 추가
			v.push_back({ tmp, j });
		}
		// 문자열 순으로 정렬
		sort(v.begin(), v.end());
		cout << v[0].first << "\n";
		isVisit[v[0].second] = true; // 새롭게 추가된 문자 방문 처리
	}
	return 0;
}
