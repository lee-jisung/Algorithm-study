#include <string>
#include <vector>
#include <stack>
#include <iostream>

/*
   바구니 => stack으로 사용
   board에서 숫자를 만날 때 마다
   bucket의 맨 위 숫자가 같으면 answer += 2 해주고 pop
   아니라면 board에서 가져온 숫자 bucket에 push
*/

using namespace std;

stack<int> bucket;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    int answer = 0;
    
    for(int i=0; i<moves.size(); i++){
        int col = moves[i] - 1;
        int target = 0;
        for(int i=0; i<board.size(); i++){
            if(board[i][col]){
                target = board[i][col];
                board[i][col] = 0;
                break;
            }
        }
        if(target == 0) continue;
        if(!bucket.empty() && bucket.top() == target){
            answer += 2;
            bucket.pop();
        }
        else{
            bucket.push(target);
        }
    }
    
    return answer;
}
