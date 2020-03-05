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
