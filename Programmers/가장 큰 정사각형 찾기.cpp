#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
   dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
   => 1의 길이가 가장 긴 것을 찾아 제곱하여 answer의 max값으로 갱신
*/

int dp[1001][1001];

int solution(vector<vector<int>> board) {
    int answer = 0;
    int row = board.size(); 
    int col = board[0].size();
    
    for(int i=0; i<row;i++)
        if(board[i][0] == 1) {
            dp[i][0] = 1;
            answer = 1;
        }
    
    for(int j=0; j<col; j++)
        if(board[0][j] == 1) {
            dp[0][j] = 1;
            answer = 1;
        }
    
    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            if(!board[i][j]) continue;
            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            answer = max(dp[i][j] * dp[i][j], answer);
        }
    }

    return answer;
}
