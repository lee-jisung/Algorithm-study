#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

vector<string> combi;

// array의 index를 조합으로 구하기 
// ex) 0, 1, 2, 3, 01, 02, 03, .... 
void getCombination(int columnSize) {
	for (int i = 0; i < columnSize; i++) {
		vector<int> v;
		for (int j = 0; j <= i; j++) v.push_back(1);
		for (int j = 0; j < columnSize - (i + 1); j++) v.push_back(0);
		do {
			string tmp = "";
			for (int j = 0; j < v.size(); j++)
				if (v[j]) tmp += to_string(j);
			combi.push_back(tmp);
		} while (prev_permutation(v.begin(), v.end()));
	}
}

int solution(vector<vector<string>> relation) {
	int answer = 0, columnSize = relation[0].size();

	getCombination(columnSize);


	for (int i = 0; i < combi.size(); i++) {
		string col = combi[i];
		set<string> s;
		bool ck = true;
		
		// 유일성 확인하기
		for (int j = 0; j < relation.size(); j++) {
			string tmp = "";
			for (int k = 0; k < col.length(); k++) {
				int idx = col[k] - '0';
				tmp += relation[j][idx] + " ";
			}
			if (s.count(tmp)) {
				ck = false;
				break;
			}
			s.insert(tmp);
		}

		// 만약 위의 col이 유일성을 만족한다면, 
		// col이 포함된 나머지 조합을 모두 제거해줌 (최소성을 만족하지 못하는 것들을 제거하는것)
		if (ck) {
			for (int j = combi.size() - 1; j >= i; j--) {
				bool isErase = true;
				for (int k = 0; k < col.length(); k++) {
					if (combi[j].find(col[k]) == string::npos) {
						isErase = false;
						break;
					}
				}
				if (isErase) combi.erase(combi.begin() + j);
			}
			// combi.size()-1 부터 i까지 지우니까 본인도 지워져서 
			// i--를 해줘야 하나 앞으로 땡겨진 것부터 확인할 수 있음
			i--; answer++;
		}
	}
	return answer;
}

int main(void) {

	vector<vector<string>> v = {
		{ "100","ryan","music","2"},
		{"200","apeach","math","2"},
		{"300","tube","computer","3"},
		{"400","con","computer","4"},
		{"500","muzi","music","3"},
		{"600","apeach","music","2"},
	};
	solution(v);

	return 0;
}
