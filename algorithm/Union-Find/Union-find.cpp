#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100
#define INF 987654321

using namespace std;

int n, m; 
int parent[SIZE];

/*
   Disjoint-set
   
   그래프에서 여러 노드 중 임의의 2개 노드가 서로 같은 그래프에 있는지 확인하는 algorithm
   
   Union -->  연결되어 있는 노드들에 대하여 가장 작은 수의 노드를 부모로 표시

   Find --> 두개의 노드를 비교하여 같은 부모인지 확인 (같은 부모면 같은 그래프)
*/

// 부모 노드를 찾는 함수
int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

// 두 노드를 합치는 함수 (가장 작은 수를 부모노드로 갖음)
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모를 가지는지 확인
int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a == b) return 1;
    return 0;
}

int main(void) {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
	
    for (int i = 1; i <= 10; i++) {
        parent[i] = i;
    }

    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    if (findParent(parent, a, b)) {
        cout << a << " 와(과) " << b << " 는(은) 연결됨 \n";
    }
    else {
        cout << a << " 와(과) " << b << " 는(은) 연결 안됨 \n";
    }

	return 0;
}
