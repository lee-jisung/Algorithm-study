#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 평문->암호 규칙 == 1->2 규칙
// 1 -> 2로 가는 규칙을 찾음
// 예를 들어 1에서 0번째 index였던 것을 2에 1번째로 옮겻을 경우
// 평문에서 역시 0번째를 암호문의 1번째로 옮긴 것 
// 따라서 암호문의 1번째를 평문의 0번째로 다시 돌려놓으면 됨

int test, word;
int index;

int main(void) {

	cin >> test;
	while (test--) {
		cin >> word;
		vector<string> keys[3];
		string* plain = new string[1001];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < word; j++) {
				string str;
				cin >> str;
				keys[i].push_back(str);
			}
		}

		for (int i = 0; i < word;i++) {
			for (int j = 0; j < word; j++) {
				if (keys[0][i] == keys[1][j]) { // 1 공개키 -> 2 공개키 맞는 index 규칙 찾기 
					index = j;
					break;
				}
			}
			// 암호문에서 평문쪽으로 옮기는 작업
			plain[i] = keys[2][index]; 
		}

		for (int i = 0; i < word; i++)
			cout << plain[i] << " ";
		cout << "\n";
	}

	return 0;
}
