#include <string>
#include <vector>
#include <set>
#include <algorithm>

/*
   순열 => 연산자 모든 경우의 수 탐색
    숫자, 연산자 분리한 후
    순열 순서에 맞는 연산자부터 차례대로 계산 => 마지막 vector 0번째 원소에 최종값이 남게됨
    => answer와 비교하여 max값으로 갱신
*/

using namespace std;

vector<char> operand, operand_priority;
vector<long long> nums;
set<char> opd;

long long solution(string expression) {
    long long answer = 0;
    
    string tmp = "";
    for(int i=0; i<expression.size(); i++){
        if(expression[i] >= '0' && expression[i] <= '9'){
            tmp += expression[i];
            continue;
        }
        nums.push_back(stoll(tmp));
        operand.push_back(expression[i]);
        opd.insert(expression[i]);
        tmp = "";
    }
    nums.push_back(stoll(tmp));
    
    for(char c : opd)
        operand_priority.push_back(c);
    
    do{
        vector<char> tmpOperand = operand;
        vector<long long> tmpNum = nums;
        for(int i=0; i<operand_priority.size(); i++){
            for(int j=0; j <tmpOperand.size(); j++){
                if(operand_priority[i] == tmpOperand[j]){
                    switch(tmpOperand[j]){
                        case '*':
                            tmpNum[j] *= tmpNum[j+1];
                            break;
                        case '+':
                            tmpNum[j] += tmpNum[j+1];
                            break;
                        case '-':
                            tmpNum[j] -= tmpNum[j+1];
                            break;
                    }
                    tmpNum.erase(tmpNum.begin() + j + 1);
                    tmpOperand.erase(tmpOperand.begin() + j);
                    j--;
                }
            }
        }
        
        answer = max(answer, abs(tmpNum[0]));
    }while(next_permutation(operand_priority.begin(), operand_priority.end()));
    
    
    return answer;
}
