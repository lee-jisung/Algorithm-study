#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>

using namespace std;

/*
   Two pointer => front / rear
   rear를 이용하여 뒤로 이동하면서 보석을 map에 추가 (개수 ++)
   만약 map의 개수가 보석의 개수만큼 찼다면 front를 이용해서
    현재 front가 가리키는 보석이 map에서 1개 이상이 있을 경우 front를 증가시키고 map에서 감소
    => 구간이 제일 짧은것을 계속 찾아서 갱신
*/

int front, rear;
pair<int, int> result;
set<string> jewelry;
map<string, int> jewelry_count;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    for(int i=0; i<gems.size(); i++){
        jewelry.insert(gems[i]);
    }
    
    while(front <= rear && rear < gems.size()){
        
        jewelry_count[gems[rear]]++;
        
        while(jewelry_count.size() >= jewelry.size()){
            if(result.first && result.second){ // 구간이 이미 정해졌을 경우
                // 구간이 더 짧은 것을 찾았다면 갱신
                if(result.second - result.first > rear - front) {
                    result.first = front + 1;
                    result.second = rear + 1;
                }
            }
            else { 
                result.first = front + 1;
                result.second = rear + 1;
            }
            // front가 가리키는 보석 개수가 1개면 break
            if(jewelry_count[gems[front]] == 1) break;
            jewelry_count[gems[front]]--;
            front++;
        }
        rear++;
    }
    answer.push_back(result.first);
    answer.push_back(result.second);
    return answer;
}
