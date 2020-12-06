#include <iostream>
#include <string>
#include <set>

using namespace std;

/*
   bruteforce 
   모든 카드 조합해서 set에 담기 (중복 제거)
   개수 출력
*/

int n, k;
string card[10];
bool isVisit[10];
set<string> st;

void selectCard(int no, string str) {
	if (no == k) {
		st.insert(str);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isVisit[i]) continue;
		isVisit[i] = true;
		selectCard(no + 1, str + card[i]);
		isVisit[i] = false;
	}
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> card[i];
	selectCard(0, "");

	cout << st.size() << "\n";

	return 0;
}
