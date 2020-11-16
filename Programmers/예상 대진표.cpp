#include <iostream>

using namespace std;

/*
   2배씩 번호를 줄이면 됨
   단, 짝수 => 짝수 or 짝수 => 홀수 or 홀수 => 짝수 or 홀수 => 홀수 의 경우들이 존재하기 때문에
   단순히 /2만 하면 안되고, a = (a/2) + (a%2)를 해줘서 다음 라운드에 지정할 번호를 계산함
   
   탈출 조건 => a가 짝수일 때 b가 a보다 1 적다면 같은 라운드 (반대도 동일)
*/

int solution(int n, int a, int b)
{
    int answer = 1;
    while(1){
        if(a % 2 == 0 && b + 1 == a) break;
        if(b % 2 == 0 && a + 1 == b) break;
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
        answer++;
    }
    
    return answer;
}
