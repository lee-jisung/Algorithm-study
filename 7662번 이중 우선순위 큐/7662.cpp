#include <iostream>
#include <set>

using namespace std;

int t, k;

int main(void) {

	using namespace std;

	cin >> t;

	while (t--) {

		multiset<int> ms;

		cin >> k;

		for (int i = 0; i < k; i++) {
			string tmp;
			int num;
			cin >> tmp >> num;
			if (tmp == "I") {
				ms.insert(num);
			}
			else if(tmp == "D" && !ms.empty()){
				if (num == 1) ms.erase(--ms.end());
				else ms.erase(ms.begin());
			}
		}
		if (ms.empty()) cout << "EMPTY\n";
		else {
			auto maxVal = --ms.end();
			auto minVal = ms.begin();
			cout << *maxVal << " " << *minVal << "\n";
		}
	}

	return 0;
}
