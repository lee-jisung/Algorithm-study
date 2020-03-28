#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 100001
#define INF 987654321

using namespace std;

/*
   비행기 p의 번호 i --> 1 ~ gi번째까지 도킹 가능 
   => g번부터 g-1, g-2..해서 도킹 가능한 곳이 있다면 도킹함
   --> 이때 도킹은 union(g-1, g) --> parent[g]값을 g-1로 갱신함
   그리고 비행기 번호 pi에 대해서 getParent(pi)값이 0이 된다면 도킹이 가능한 모든곳에 착륙한것이므로 
   그 이상 착륙을 안시키면 됨
*/

int g, p, f, res, parent[SIZE];
bool open = true;

int getParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent[x]);
}

void unionParent(int prev, int cur) {
    prev = getParent(prev);
    cur = getParent(cur);
    parent[cur] = prev;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

    cin >> g >> p;

    for (int i = 0; i <= g; i++)
        parent[i] = i;

    for (int i = 0; i < p; i++) {
        int temp;
        cin >> temp;

        if (!open) continue;

        int gate = getParent(temp);

        if (gate > 0) {
            unionParent(gate - 1, gate);
            res++;
        }
        else
            open = false;
    }
    cout << res << "\n";
	return 0;
}
