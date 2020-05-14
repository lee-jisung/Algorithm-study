### 2차원 배열에서 여러개의 빈칸 중 1, 2, 3 개의 칸을 채워야 하는 경우 등등

- 기존 -> permutation을 이용해서 0, 1의 조합으로 구했었음 --> 비효율적이라 생각 (물론 직관적으로 짜기 편함)

- recursive 활용 

```
 void test(int pos, int cnt){
   if(cnt >= 3) return;
   if(condition()){
     result = result;// 여기에 조건 확인 등등을 추가 해서 결과 값 구함
     return; 
   }
   
   for(int i=pos; i<n; i++){
     for(int j=0; j<m; j++){
        if(visit[i][j] || //조건 추가) continue;
        visit[i][j] = true;
        test(i, cnt+1);
        visit[i][j] = false;
     }
   }
   
}
``` 
     
        
