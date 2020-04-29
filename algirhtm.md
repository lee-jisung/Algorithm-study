# algorithm header

### sort 함수

``` c++
 sort(v.begin(), v.end(), cmp);
 
 int cmp(int a, int b){
  return a > b // 감소하는 순 (내림차순)
  return a < b // 증가하는 순 (오름차순)
 }
```

- greater<int>() 사용하여 오름차순 정리
 ```
   sort(v.begin(), v.end(), greater<int>());
 ```

### lower_bound(), upper_bound() 함수
 
  - 이진탐색 기반의 탐색 방법
  - 배열 or 리스트가 정렬 되어 있어야 함.
  - lower_bound(v.begin(), v.end(), key);
    - 찾으려 하는 ***key값 이상인 수가 처음으로 등장하는 위치 반환***
  - upper_bound(v.begin(), v.end(), key);
    - 찾으려 하는 ***key값을 초과하는 수가 처음 등장하는 위치 반환***
   
``` c++
  lower_bound(v.begin(), v.end(), key); // iterator 반환
  upper_bound(v.begin(), v.end(), key);
  
  int idx = lower_bound(v.begin(), v.end(), key) - v.begin(); // index 값으로 사용
  int idx = upper_bound(v.begin(), v.end(), key) - v.begin();
  
```

# string header

### to_string
```
 int n = 10;
 string str = to_string(n);
 ```

### stoi
```
 string str = "1000";
 int n = stoi(str);
 ```
