#include <string>
#include <vector>
#include <queue>

using namespace std;

/* 
   minHeap, maxHeap 2개를 이용
   숫자와 index 2개를 push, isVisit을 이용해서 최솟값 or 최댓값에서 pop을 하는 경우 해당 인덱스의 숫자를 이미 처리했다고 표시
   => 각 최대,최소 값을 삭제하는 연산에서 이미 처리된 숫자들을 먼저 제거 후, 다음 숫자 처리
   
   + 마지막에 한번 더 처리해줌 (이미 처리된 숫자이지만 다른 큐에 남아있을 수가 있음)
*/

priority_queue<pair<int, int>> maxHeap;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
bool isVisit[1000001];

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    
     for(int i=0; i<operations.size(); i++){
         int num = stoi(operations[i].substr(2, operations[i].length()-2));
    
         if(operations[i][0] == 'I'){
             isVisit[i] = true;
             minHeap.push({num, i});
             maxHeap.push({num, i});
         }else{
             if(num == 1){
                 while(!maxHeap.empty() && !isVisit[maxHeap.top().second]){
                     maxHeap.pop();
                 }
                 if(maxHeap.empty()) continue;
                 isVisit[maxHeap.top().second] = false;
                 maxHeap.pop();
             }else{
                 while(!minHeap.empty() && !isVisit[minHeap.top().second]){
                     minHeap.pop();
                 }
                 if(minHeap.empty()) continue;
                 isVisit[minHeap.top().second] = false;
                 minHeap.pop();
             }             
         }
     }
    
    while(!maxHeap.empty() && !isVisit[maxHeap.top().second])
        maxHeap.pop();
    
    while(!minHeap.empty() && !isVisit[minHeap.top().second])
        minHeap.pop();

    
    if(minHeap.empty() && maxHeap.empty()){
        answer[0] = answer[1] = 0;
    }
    else{
        answer[0] = maxHeap.top().first;
        answer[1] = minHeap.top().first;
    }
    
    return answer;
}
