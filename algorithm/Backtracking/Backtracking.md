# Backtracking

## Basic

 - 기본 아이디어: 가능한 한 모든 방법을 탐색, 대표적인 방법: DFS
 - 단, DFS를 통해 완전탐색을 하면 중복방문의 경우가 발생할 수 있음, 이를 해결하기 위해 pruning을 진행
 
 - DFS + Pruning = Backtracking이라고 볼 수 있음
 
 
 
 
## Process


- Backtracking을 위한 4가지 절차
  - 1. DFS를 수행
  - 2. 유망한 노드 검토 - 방문한 노드를 포함해서 유망한 노드면 sub tree로 이동, 그렇지 않으면 backtrack
  - 3. 방문한 노드의 하위 노드로 이동하여 다시 재귀를 통해 DFS 수행
  - 4. Backtracking 수행 - 방문한 노드를 가지치기를 하고 상위 노드로 Backtrack한 후, DFS 수행
 

- Backtrack의 일반화

```
 Backtrack-DFS(A, k){
   if A == (a1, a2, a3, ...) is a solution, report it // return 지점;
   else
     for i in Arr:
       if(!visit[i])
         compute A
         visit[i] = true
         Bactrack-DFS(A, k+1)
         visit[i] = false
  } 
```

 - Pruning(가지치기): Bactracking 함수 내에서 for, while, if문 내에서 break, return을 통해서 더이상 재귀적으로 탐색할 필요없는 경우에 한에서 중지시키는 것

### Backtracking vs DFS

 - Backtracking의 경우 Pruning이 일어나기 때문에 모든 경우에 대해서 탐색하는 DFS와는 차이가 있다
 - DFS는 모든 경우의 수를 확인하는 알고리즘이라고 볼 수 있음

 
 
 
## Example

### N-Queen
 
 - N * N 체스판에 퀸 N개를 서로 공격할 수 없게 놓는 방법의 수 구하기
 
 ![image](https://user-images.githubusercontent.com/32594290/82134946-5b905e80-9838-11ea-98ef-4c6d99dcc86c.png)

- Pruning(가지치기)없이 탐색했을 경우, (2,1), (2,2)도 중복으로 탐색했을 것, 따라서 Pruning이 중요함

참고: https://idea-sketch.tistory.com/29
  
  
  
