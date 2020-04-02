#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 300001
#define INF 987654321

/*
    1. n번째 술병을 ai or bi번째 서랍에 넣을 수 있으면 그대로 넣고 
      1-1. A가 비어있으면 A를 자식, B를 부모로 설정
      1-2. B가 비어있으면 B를 자식, A를 부모로 
      즉, 술병을 넣은 서랍의 값을 다른 넣을 수 있는 서랍의 값으로 바꿔놓는 것임
    2. A에 부모노드가 방문 안됐으면 (즉, 병을 옮길 수 있으면) A에 부모를 자식으로 하고, B를 부모로 바꿈
    3. B에 부모노드가 방문 안됐으면 (즉, 병을 옮길 수 있으면) B에 부모를 자식으로 하고, A를 부모로 바꿈
   
*/

using namespace std;

int n, l;
int alchol[SIZE];
bool room[SIZE];

int getParent(int x) {
    if (alchol[x] == x) return x;
    return alchol[x] = getParent(alchol[x]);
}

// a의 부모를 b로 합침
void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    alchol[a] = b;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> l;

    for (int i = 0; i <= l; i++)
        alchol[i] = i;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        if (!room[a]) {
            room[a] = true;
            unionParent(a, b);
            cout << "LADICA\n";
        }
        else if (!room[b]) {
            room[b] = true;
            unionParent(b, a);
            cout << "LADICA\n";
        }
        else if (!room[getParent(alchol[a])]) {
            room[getParent(alchol[a])] = true;
            unionParent(a, b);
            cout << "LADICA\n";
        }
        else if (!room[getParent(alchol[b])]) {
            room[getParent(alchol[b])] = true;
            unionParent(b, a);
            cout << "LADICA\n";
        }
        else
            cout << "SMECE\n";
    }

	return 0;
}
