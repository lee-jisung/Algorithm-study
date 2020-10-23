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
     
        
### 배열의 부분 수열의 합을 구하기

 - ex) int arr[] = {5, 1, 2, 4}; (n = 4)
 - recursive에서 index를 한개씩 증가시키면서 더하거나 더하지 않는 2가지로 나눠서 구할 수 있음
 - makeSum(0, 0)부터 시작해야함 -> 5, 1, 2, 4 로 한개씩 더하는 경우도 구해야하기 때문에 0에서 시작하면됨

```
bool numbers[10000];

void makeSum(int idx, int sum) {
	if (idx == n) {
		if (maxVal < sum) maxVal = sum;
		numbers[sum] = true;
		st.insert(sum);
		return;
	}
	makeSum(idx + 1, sum + arr[idx]);
	makeSum(idx + 1, sum);
}


```
