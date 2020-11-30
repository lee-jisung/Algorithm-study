#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
    동맹 => union 할 때 parent / 병력 array도 같이 합쳐주기
	전쟁 => 전쟁을 할 때 parent에 누적된 병력수를 가져와서 계산, 
	        남은 병력 = (승리 - 패배) => 갱신 해주고 union해주기
			만약 병력이 같으면 모두 멸망 => parent 값을 -1로 표시

	남은 병력들을 벡터에 넣고 오름차순으로 정렬하여 출력
*/

int n, m, countryCnt;
int parent[100001], military[100001];
vector<int> mt;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

// a국가로 b를 편입시킨다.
// a에 b 병력 합쳐주고 b 병력을 0으로 만듦
// 여기서 해주는 이유는 getParent로 부모 국가로 갱신해서 합쳐야 하기 때문
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b || a == -1 || b == -1) return;
	parent[b] = a;
	military[a] += military[b];
	military[b] = 0;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> military[i];
		parent[i] = i;
	}
	countryCnt = n;

	for (int i = 0; i < m; i++) {
		int o, p, q;
		cin >> o >> p >> q;

		if (o == 1) { // 동맹 맺을 때 국가가 2개 국가가 1개로 줄어드니까 국가 수 -1
			unionParent(p, q);
			countryCnt--;
		}
		else {
			p = getParent(p);
			q = getParent(q);
			// p가 승리 시 p 병력에서 q 병력 빼주고 
			// 국가 수 1개 줄이고, q국가도 p로 합치기
			if (military[p] > military[q]) { 
				military[p] -= military[q];
				military[q] = 0;
				unionParent(p, q);
				countryCnt--;
			}
			// 위와 반대로
			else if (military[q] > military[p]) {
				military[q] -= military[p];
				military[p] = 0;
				unionParent(q, p);
				countryCnt--;
			}
			else { // 멸망 시 국가 수 -2, 멸망 국가는 -1, 병력 0으로 표시
				countryCnt -= 2;
				parent[p] = -1;
				parent[q] = -1;
				military[p] = 0;
				military[q] = 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (military[i] > 0) mt.push_back(military[i]);
	}

	sort(mt.begin(), mt.end());

	cout << countryCnt << "\n";
	for (int i = 0; i < mt.size(); i++) {
		cout << mt[i] << " ";
	}
	cout << "\n";

	return 0;
}
