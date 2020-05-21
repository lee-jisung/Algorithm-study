# 조합 (중복 허용 x)

 - m = 5, n = 3일 때, 
   - dfs(0, 0)을 main에서 호출하게 되면 arr이라는 배열에 0, 1, 2가 들어가고 cnt == 3이 되어 arr의 요소가 출력됨
   - 그 후 이런식으로 012, 013, 014, 023, ... 식으로 조합이 이루어져서 배열에 들어가게됨
   - 단, dfs를 호출할 때, idx를 추가로 넣어주는 이유는 중복을 제거하기 위해서임
   - 012와 102는 같은것이라고 간주하기 때문에 idx를 넣지 않고, for문의 시작을 i=0으로 한다면 1로 시작하는 경우에도 0을 방문하게 되므로
     012, 102가 중복되서 나타남
   

```
void dfs(int idx, int cnt){
  if(cnt == n){
    for(int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  
  for(int i=idx; i<m; i++){
     if(!isVisit[i]){
        isVisit[i] = true;
        arr[cnt] = i;
        dfs(i, cnt+1);
        isVisit[i] = false;
     }
 }
}
```


# 조합 (중복 허용 O)

 - m = 5, n = 3일 때, 
   - dfs(0, 0)을 main에서 호출하게 되면 arr이라는 배열에 0, 1, 2가 들어가고 cnt == 3이 되어 arr의 요소가 출력됨
   - 그 후 이런식으로 012, 013, 014, 023, ... 식으로 조합이 이루어져서 배열에 들어가게됨
   - 단, for문의 시작을 i=0으로 한기 때문에 1로 시작하는 경우에도 0을 방문하게 되므로 012, 102가 중복되서 나타남
   

```
void dfs(int cnt){
  if(cnt == n){
    for(int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  
  for(int i=0; i<m; i++){
     if(!isVisit[i]){
        isVisit[i] = true;
        arr[cnt] = i;
        dfs(i, cnt+1);
        isVisit[i] = false;
     }
 }
}
```


# 각 숫자마다 순서의 의미가 있는 경우

 - 예를 들어, 0번이 오른쪽, 1번이 왼쪽 등의 방향을 가리키고, 경우의 수를 확인하기 위해서 순열을 짜야 할 때
 - 방문처리를 해주지 않으면 000, 001, 002...식으로 배열에 숫자가 할당되어 여러번 같은 것을 선택할 수 있음

```
void dfs(int cnt){
  if(cnt == n){
    for(int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  
  for(int i=0; i<m; i++){
        arr[cnt] = i;
        dfs(i, cnt+1);
   }
}
```

 - 아래의 경우, 방문 처리를 해주었기 때문에 000, 001의 결과가 아닌 012, 013, 014, ... 의 식으로 방문하게 됨
 - 그리고 012와 102가 같은 것으로 간주가 되지 않을때 사용

```
void dfs(int cnt){
  if(cnt == n){
    for(int i=0; i<n; i++)
       cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  
  for(int i=0; i<m; i++){
        if(!isVisit[i]){
          isVisit[i] = true;
          arr[cnt] = i;
          dfs(i, cnt+1);
          isVisit[i] = false;
        }
   }
}
```
