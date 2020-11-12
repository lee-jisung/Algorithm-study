#include <iostream>

/*
   대각선으로 선을 그었을 때, 사용하지 못하는 사각형의 규칙이 생성
   => w, h의 최대 공약수 만큼 반복해서 나타남
   => 반복되는 사각형에서 잘리는 사각형의 개수 => w + h - 1임
   => 따라서 반복되는 사각형들에서 사용하지 못하는 사각형 개수는
     gcd * (w / gcd + h / gcd - 1) ==> w + h - gcd로 나타낼 수 있음
     
     // 참고: https://leedakyeong.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EB%A9%80%EC%A9%A1%ED%95%9C-%EC%82%AC%EA%B0%81%ED%98%95-in-python
  
*/

using namespace std;

long long gcd(long long a, long long b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

long long solution(int w, int h) {
    long long answer = 0, g, W, H;
    
    W = w; H = h;
    
    g = gcd(W, H);
    
    long long tmp = (W + H - g);
    
    answer = (W * H) - tmp;
    
    return answer;
}
