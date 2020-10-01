#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string x;
int prevX, nextX;
bool isBig;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> x;
	
	prevX = stoi(x);
	do {
		nextX = stoi(x);
		if (nextX > prevX) {
			isBig = true;
			break;
		}

	} while (next_permutation(x.begin(), x.end()));
	if (isBig) cout << nextX << "\n";
	else cout << 0 << "\n";
	return 0;
}
