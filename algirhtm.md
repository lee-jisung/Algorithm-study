# algorithm header

### sort 함수

``` c++
 sort(v.begin(), v.end(), cmp);
 
 int cmp(int a, int b){
  return a > b // 감소하는 순 (내림차순)
  return a < b // 증가하는 순 (오름차순)
 }
```
