#include <iostream>

using namespace std;

int N, R, C, result;

// 시간이 오래 걸림
//void func(int r, int c, int len) {
//	
//	if (len == 2) {
//		for (int i = r; i < r + len; i++) {
//			for (int j = c; j < c + len; j++) {
//				if (i == R && j == C) {
//					cout << result << "\n";
//					exit(0);
//				}
//				result++;
//			}
//		}
//		return;
//	}
//
//	int div = len / 2;
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 2; j++) {
//			func(r + i * div, c + j * div, div);
//		}
//	}
//}

// 4칸으로 나누어 앞선 칸의 개수를 더한 값으로 계산하는 것
int zfunc(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1 << (n - 1);
	if (r < half && c < half) return zfunc(n - 1, r, c); 
	if (r < half && c >= half) return half * half + zfunc(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half * half + zfunc(n - 1, r - half, c);
	return 3 * half * half + zfunc(n - 1, r - half, c - half);
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> R >> C;
	cout << zfunc(N, R, C);
	//func(0, 0, (1 << N));

	return 0;
}
