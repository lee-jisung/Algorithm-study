#include <iostream>
#include <queue>

using namespace std;

/*
   크기가 같지 않은 두 그룹의 개수를 나눠도 a, b, c의 합은 항상 같기 때문에 a, b 2개의 돌만으로 판단 가능
   a,b,c의 합인 sum을 통해 a, b 만으로 c를 구할 수 있음
   => a, b 2개의 돌만 가지고 a-b, a-c, b-c 3개의 경우의 수를 판단할 수 있음

*/

int A, B, C, sum;
bool isVisit[1501][1501], isAvail;

void findDol() {

	queue<pair<int, int>> q;
	q.push({ A, B });
	isVisit[A][B] = true;
	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		int c = sum - a - b;

		if (a == b && b == c) {
			isAvail = true;
			return;
		}

		int group1[] = { a, a, b }, group2[] = { b, c, c };
		for (int i = 0; i < 3; i++) {
			int na = group1[i], nb = group2[i];
			if (na > nb) {
				na -= nb; 
				nb += nb;
			}
			else if (na < nb) {
				nb -= na;
				na += na;
			}
			if (!isVisit[na][nb]) {
				isVisit[na][nb] = true;
				q.push({ na, nb });
			}
		}
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;
	sum = A + B + C;

	if (sum % 3 != 0) {
		cout << 0 << "\n";
		return 0;
	}

	findDol();
	cout << isAvail << "\n";

	return 0;
}
