# Two Pointer

## how?

- 배열의 원소 위치를 가리키는 pointer 2개를 선언하며, 시작과 끝을 가리키는 역할임
- 부분합, 부분집합 등의 문제에 사용
> (p, q) / (s, e) ... 등 


- 초기 값
  - s = e = 0
  
- 조건
  > s <= e를 항상 만족해야 함
  - 만약 현재 부분합이 M 이상이거나 이미 e = N이면 s++
  - 그렇지 않다면 e++
  - 현재 부분합이 M과 같다면 result++
  - s > e 거나 s == N이라면 종료
  
 - 현재 pointer가 가리키는 값을 누적시켜서 더하거나 빼면서 진행
 
 ---
 
 ## Code
 ``` c++
#include <cstdio>
using namespace std;
 
int main(){
    int N, M, arr[10000];
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", arr+i);
    int result = 0, sum = 0, lo = 0, hi = 0;
    while(1){
        if(sum >= M) sum -= arr[lo++];
        else if(hi == N) break;
        else sum += arr[hi++];
        if(sum == M) result++;
    }
    printf("%d\n", result);
}
```

## Sliding Window

- two pointer와 동일하게 구간을 탐색하며 지나가지만, 탐색하는 구간의 크기가 항상 일정한 것
