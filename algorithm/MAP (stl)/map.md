# MAP container

## Structure

 - 노드 기반으로 이루어진 **균형 이진 트리** 구조
 
 ![image](https://user-images.githubusercontent.com/32594290/78003655-fd84e600-7373-11ea-94b8-0c8686ae6da7.png)

 
 - Map: **key**와 **value**로 이루어져 있으며 pair 객체 형태로 저장됨
 
 - Unique key: key값은 고유한 값으로 **중복 불가능** (중복 key는 multimap에서 가능)
 
 - Ordered: 삽입이 되면서 자동으로 정렬 됨 (default - 오름차순)


## How to use

  - 기본 선언 방법
   ```  c++
     map<string, int> name;
     map<string, int> mm("hi", 10);
  ```
  
  - 연산자 '==', '<=', '>=', '<', '>', '!=' 사용 가능
  
  - 값 추가, 수정
  ``` c++
    map<string, int> name;
    name[key] = val; 
  ```
  
## Method

  - name.begin();
  - name.end();
  - name.rbegin();
  - name.rend();
  - name.clear();
  - name.insert({i, i});
  - name.insert(iter, {i, i});
  - name.erase(start, end);
  - name.find(key);
  - name.upper_bound(key);
  - name.lower_bound(key);
  - name.equal_range(key);
  - name.value_comp();
  - name.size(0;
  ...
  
 
## map 순회 방법

``` c++

map<int, int> m;
m.insert({10, 20});
m.insert({20, 30});
...

map<int, int>::iterator iter;

for(iter = m.begin(); iter != m.end(); iter++){
   cout << iter->first << " " << iter->second << "\n";
             // or 
   cout << (*iter).first << " " << (*iter).second << "\n";
}
 ```
  

## map을 이용한 방문처리
```
// map<pair<비교 수, 횟수>, bool> 로 초기화 한 후
// 방문 처리를 할 수 있음 
// 방문처리를 위한 배열이 너무 클 경우에 
map<pair<long long, int>, bool> isVisit;

void dfs(long long sum, int no) {

	string tmp = to_string(sum);
	if (tmp.length() > D || isVisit[{sum, no}]) return;

	isVisit[{sum, no}] = true;

	if (no == P) {
		result = max(result, sum);
		return;
	}

	for (int i = 2; i <= 9; i++) {
		dfs(sum * i, no + 1);
	}
}
```
