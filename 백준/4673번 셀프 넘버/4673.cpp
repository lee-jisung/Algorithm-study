#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 10001
#define INF 987654321

using namespace std;

int n, m; 
int arr[SIZE];

void self(int num) {
	if (num > 10000) return;
	string str = to_string(num);
	int temp = 0;
	for (int i = 0; i < str.length(); i++)
		temp += str[i] - '0';
	if (num + temp > 10000) return;
	arr[num + temp] = 0;
	self(num + temp);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 10000; i++) {
		arr[i] = i;
	}
	
	for (int i = 1; i <= 10000;i++) {
		if (arr[i] == 0) continue;
		self(i);
	}

	for(int i = 1; i <= 10000; i++)
		if (arr[i]) cout << arr[i] << "\n";

	return 0;
}
