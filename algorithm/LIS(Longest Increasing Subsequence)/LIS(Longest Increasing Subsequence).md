# LIS [최장 증가 수열]

> 가장 긴 증가하는 부분 수열

### Example

다음과 같은 수열이 존재할 때
> 10 20 40 25 20 50 30 70 85

LIS를 찾는다면 
> **10 20 40 50 70 85** 

가 LIS가 됨.

#### 즉, 앞에서부터 숫자를 선택하며 증가하는 순서대로 숫자를 고르면서 부분 수열의 길이가 최대가 되도록 만듦 

dp[x]가 채워져 있다면 x보다 큰 수 y의 값 arr[y]도 arr[x]보다 크다면 dp[y] = dp[x] + 1이 됨

``` 
for (int i = 0; i < n; i++) {
    if (dp[i] == 0)dp[i] = 1;
    for (int j = 0; j < i; j++) {
        if (arr[i] > arr[j]) {
            if (dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
}
```

하지만 2중 포문의 경우 N이 10만이 넘어가면 O(N^2)의 방법은 비효율적

### 이분 탐색 이용

이분 탐색을 이용하여 LIS를 유지하기 위한 **최적의 위치에 수를 삽입**

매 수열을 탐색할 때 마다 벡터의 맨 뒤 원소와 탐색 대상인 수열의 수를 비교하여 수열의 원소가 더 클 시 벡터에 push_back을 해주고 
LIS의 길이를 1 증가시켜줌

만일 수열의 원소가 벡터의 맨 뒤 원소보다 크기가 작을 경우 lower_bound를 이용하여 최적의 자리를 찾은 뒤 그 자리의 값을 해당 수열의
원소로 교체.

> | 10 | 40 | 70 |
> | ---| -- | -- |    

의 값이 벡터에 들어있다고 가정할 때 50이 들어갈 위치를 찾기 위해 lower_bound로 50을 찾으면 
iterator는 70의 위치를 가리키게 되어 70을 50으로 갱신

> | 10 | 40 | 50 |
> | ---| -- | -- | 

이 다음 수열에 원소가 55라는 값일 경우 맨뒤 원소보다 값이 크기 때문에 추가 될것임
만일 50이 아닌 70의 값이 그대로 유지되었다면 55라는 값이 들어올 수 없었을 것.


- lower_bound() 사용 

  - lower_bound(v.begin, v.end, x): array에서 x보다 크거나 같은 값 중 최솟값의 위치를 return

```
vt.push_back(-INF);
for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (vt.back() < x) {
        vt.push_back(x);
           ans++;
    }
    else {
        auto it = lower_bound(vt.begin(), vt.end(), x);
        *it = x;
    }
}
```

#### 주의할 점
lower_bound()를 이용하여 LIS를 구할 경우 vector에 들어간 수열이 실제 LIS를 이루는 요소와는 무관함

따라서 길이가 아닌 LIS의 원소를 구할 경우 다른 방법을 사용

### LIS 원소 구하기

[1, 3, 4, 2] 라는 배열을 생각했을 때,
위의 알고리즘을 적용하면 답은 1, 2, 4가 나오지만 실제 배열상 부분 증가 수열은 1, 3, 4여야 함
따라서 증가하는 최장 부분 수열을 구하기 위한 다른 알고리즘을 적용해야 함.

```
// BOJ 14002

#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int n, cnt;
int arr[100001], cache[100001];
pair<int, int> res[100001];
stack<int> s;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	int idx = 0;
	cache[idx] = arr[0];
	res[0] = { 0, arr[0] };

	for (int i = 1; i < n; i++) {
		if (cache[idx] < arr[i]) {
			cache[++idx] = arr[i];
			res[i] = { idx, arr[i] };
		}
		else {
			int idx2 = lower_bound(cache, cache + idx, arr[i]) - cache;
			cache[idx2] = arr[i];
			res[i] = { idx2, arr[i] };
		}
	}

	cnt = idx + 1;
	cout << cnt << "\n";

	int num = cnt - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (res[i].first == num) {
			s.push(res[i].second);
			num--;
		}
	}
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";


	return 0;
}

```

실제 lis 배열을 구하는 알고리즘 예시 

1 6 2 5 7 3 5 6인 경우
res배열에는 다음과 같이 들어간다.

 > first  ::  0 1 1 2 3 2 3 4
 
 > second ::  1 6 2 5 7 3 5 6

이 값을 first를 기준으로 뒤에서 부터 조사해오면
first가 4일때 (6) - > first가 3일때 (5) -> first가 2일때 (3)
-> first가 1일때 (2) -> first가 0일때(1)이다.

이것을 스택에 담아 역출력하면 1,2,3,5,6이라는 실제 배열을 구할 수 있다.

출처: https://www.crocus.co.kr/681 [Crocus]

