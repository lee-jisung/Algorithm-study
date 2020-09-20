#include <iostream>
#include <vector>

using namespace std;

/*
   출력: 다음 수 or A (무수히 많은 경우) or B (불가능한 경우)

   예외처리

   1. n == 1 => 무수히 많은 수 가능 => A

   2. n == 2 
     2.1 v[0] == v[1] 일 때 => v[0]의 수만 올 수 잇음
	 2.2 v[0] != v[1] 일 때 => 무수히 많은 수 가능 => A

   3. n >=3
     3.1 v[0] == v[1]일 때 
	    => 나머지 모든 수가 v[0]과 같다면 다음수도 v[0]
		=> 하나라도 틀리면 B 

     3.2 v[0] != v[1]일 때
	    => (v[2] - v[1]) % (v[1] - v[0]) != 0 이면 a가 실수라는 의미 => B
		=> a = (v[2] - v[1]) / (v[1] - v[0])
		   b= v[1] - v[0] * a
		   의 a, b를 구해서 나머지 모든 n개 숫자에 대해서 a, b가 적용되면 다음수 출력
		   적용이 안된다면 B 
*/

int n;
int a, b;
bool ck;
vector<int> v;

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	if (n == 1) {
		cout << "A\n";
	}
	else if (n == 2) {
		if (v[0] == v[1]) 
			cout << v[0] << "\n";
		else 
			cout << "A\n";
	}
	else {
		if (v[0] == v[1]) {
			bool ck = true;
			for (int i = 2; i < n; i++) {
				if (v[0] != v[i]) {
					ck = false;
					break;
				}
			}
			if (ck)
				cout << v[0] << "\n";
			else cout << "B\n";
		}
		else if ((v[2] - v[1]) % (v[1] - v[0]) != 0) {
			cout << "B\n";
		}
		else {
			bool ck = true;
			a = (v[2] - v[1]) / (v[1] - v[0]);
			b = v[1] - v[0] * a;

			for (int i = 0; i < n - 1; i++) {
				if (v[i] * a + b != v[i + 1]) {
					ck = false;
					break;
				}
			}

			if (ck) {
				cout << v[n - 1] * a + b << "\n";
			}
			else cout << "B\n";
		}
	}

	return 0;
}
