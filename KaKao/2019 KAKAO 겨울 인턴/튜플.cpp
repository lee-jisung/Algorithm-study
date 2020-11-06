#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

/* 
   tuples 벡터에 => 각 집합의 숫자와 숫자 개수를 담아줌  
     => 숫자가 1개인 집합부터 차례대로 answer에 넣어주면 답이 나옴
     => 이 때의 중복 확인은 set으로 처리
*/

string number;
set<int> duplicateCheck;
vector<int> numbers;
vector<pair<int, vector<int>>> tuples;

vector<int> solution(string s) {
    vector<int> answer;

    for (int i = 1; i < s.length() - 1; i++) {
        if (s[i] == '{') continue;
        if (s[i] == ',') {
            if (s[i - 1] == '}') continue; // 집합을 구분하기 위한 , 였으면 넘어가기
            numbers.push_back(stoi(number)); // 숫자 push
            number = "";
        }
        else if (s[i] == '}') { // 집합의 마지막일 경우 숫자 개수와 숫자를 담은 벡터를 tuples에 추가
            numbers.push_back(stoi(number));
            number = "";
            tuples.push_back({ numbers.size(), numbers });
            numbers.clear();
        }
        else
            number += s[i];
    }

    // 숫자 개수대로 정렬
    sort(tuples.begin(), tuples.end()); 

    // 중복없이 answer에 차례대로 원소 담기
    for (int i = 0; i < tuples.size(); i++) {
        numbers = tuples[i].second;
        for (int num : numbers) {
            if (duplicateCheck.count(num) != 0) continue;
            answer.push_back(num);
            duplicateCheck.insert(num);
        }
    }

    return answer;
}
