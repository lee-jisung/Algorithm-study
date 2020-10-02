#include <iostream>
#include <string>

using namespace std;

int n, cnt;
string ring;

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> ring >> n;
	while (n--) {
		string str;
		cin >> str;
		str += str;
		if (str.find(ring) != string::npos) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}
