#include <string>
#include <vector>

using namespace std;

/*
   n = 15 => n / 2 = 7.5, (n+1)/2 = 8
   따라서 n이 홀수이든 짝수이든 n+1 / 2를 해주어야 합 범위를 모두 탐색할 수 있음
   
   (n+1) / 2 까지 자연수를 연속으로 더해가면서 n과 같은 수면 answer ++
   만약 합이 n을 넘어가는 경우 n보다 같거나 작아질때까지 1부터 차례로 빼주기
*/

int solution(int n) {
    int answer, sum = 0;
    int limit = (n + 1) / 2, idx = 1;
    
    // n = n인 경우 우선 증가
    answer = 1;
    for(int i=1; i<=limit; i++){
        sum += i;
        while(sum > n) sum -= idx++;
        if(sum == n) answer++;
    }
    
    return answer;
}
