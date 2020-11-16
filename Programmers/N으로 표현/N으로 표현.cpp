#include <string>
#include <vector>

using namespace std;

/*
  tmp에 N을 붙여서 +, -, *, / 모든 경우 찾고
  다시 NN에 대해서 다 찾고
  다시 NNN에 대해 찾는 DFS
*/

int result;

void dfs(int n, int number, int cnt, int val){
    if(cnt >= 9) return;
    if(val == number){
        if(result > cnt) result = cnt;
        return;
    }
    
    int tmp = 0;
    for(int i=0; i<9; i++){
        tmp = tmp * 10 + n;
        dfs(n, number, cnt + 1 + i, val + tmp);
        dfs(n, number, cnt + 1 + i, val - tmp);
        dfs(n, number, cnt + 1 + i, val * tmp);
        dfs(n, number, cnt + 1 + i, val / tmp);
    } 
}

int solution(int N, int number) {
    result = 1e9;
    dfs(N, number, 0, 0);
    if(result == 1e9) return -1;
    else return result;
}
