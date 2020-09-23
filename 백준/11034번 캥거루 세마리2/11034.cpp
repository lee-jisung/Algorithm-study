#include <cstdio>
#include <algorithm>

using namespace std;

int a, b, c;

int main(void) {
	
	while (scanf("%d %d %d", &a, &b, &c) == 3) {
		printf("%d\n", (b - a >= c - b) ? b - a - 1 : c - b - 1);
	}

	return 0;
}
