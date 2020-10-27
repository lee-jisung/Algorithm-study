#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n;
bool isAvail;
queue<string> sentence[101];
string input, output;

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n; getline(cin, input);
	// 각 문장 입력받아 i번째 큐에 단어별로 push
	for (int i = 0; i < n; i++) {
		getline(cin, input);
		string tmp = "";
		for (int j = 0; j < input.length(); j++) {
			if (input[j] != ' ') tmp += input[j];
			else {
				sentence[i].push(tmp);
				tmp = "";
				continue;
			}
		}
		sentence[i].push(tmp);
	}

	getline(cin, output);
	string tmp = "";
	// 받아 적은 문장의 단어를 하나씩 확인하면서
	// 큐의 front와 맞으면 pop, front와 맞는 단어가 아니라면 조건에 어긋나므로 impossible
	for (int i = 0; i < output.length(); i++) {
		if (output[i] != ' ') tmp += output[i];
		else {
			isAvail = false;
			for (int j = 0; j < n; j++) {
				if (!sentence[j].empty() && sentence[j].front() == tmp) {
					sentence[j].pop();
					tmp = "";
					isAvail = true;
					break;
				}
			}
			if (!isAvail) {
				cout << "Impossible\n";
				return 0;
			}
		}
	}

	// 받아적은 문장의 마지막 단어도 동일하게 처리
	// 단어가 일치하는 큐가 있지만, 빈 큐가 아닌 큐가 존재하는 경우도 impossible
	isAvail = false;
	for (int i = 0; i < n; i++) {
		if (!sentence[i].empty() && sentence[i].front() == tmp) {
			sentence[i].pop();
			isAvail = true;
			for (int j = 0; j < n; j++) {
				if (!sentence[j].empty()) {
					cout << "Impossible\n";
					return 0;
				}
			}
		}
	}

	if (!isAvail) cout << "Impossible\n";
	else cout << "Possible\n";

	return 0;
}
