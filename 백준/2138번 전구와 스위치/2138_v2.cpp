#include <iostream>
#include <algorithm>
#include <string>

#define INF 1e9

using namespace std;

int n, result;
string input, compInput, goal;

void pushSwitch(int idx) {
	if (idx > 0)
		compInput[idx - 1] = (compInput[idx - 1] == '0') ? '1' : '0';
	compInput[idx] = (compInput[idx] == '0') ? '1' : '0';
	if(idx < n-1)
		compInput[idx + 1] = (compInput[idx + 1] == '0') ? '1' : '0';
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> input >> goal;

	result = INF;
	compInput = input;
	
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (compInput[i - 1] != goal[i - 1]) {
			pushSwitch(i);
			cnt++;
		}
	}
	if (compInput.compare(goal) == 0)
		result = min(result, cnt);

	compInput = input;
	pushSwitch(0);
	cnt = 1;
	for (int i = 1; i < n; i++) {
		if (compInput[i - 1] != goal[i - 1]) {
			pushSwitch(i);
			cnt++;
		}
	}

	if (compInput.compare(goal) == 0)
		result = min(result, cnt);
	
	if (result == INF) cout << -1 << "\n";
	else cout << result << "\n";

	return 0;
}
