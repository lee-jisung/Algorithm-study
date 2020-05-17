#include <iostream>

using namespace std;

int n;
long long cache[31][31];

long long dfs(int w, int h) {

	if (cache[w][h]) return cache[w][h];
	
	// 한조각이 0개면 반조각만 남은거니까 계속 1만 return
	if (w == 0) 
		return 1;
	
	cache[w][h] = dfs(w - 1, h + 1);

	// 반조각이 남아있는 경우 나머지 문자 조합을 dfs 탐색 해서 더해줌
	if (h > 0) 
		cache[w][h] += dfs(w, h - 1);

	return cache[w][h];
}


int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) {

		cin >> n;
		if (!n) break;

		cout << dfs(n, 0) << "\n";
	}

	return 0;
}
