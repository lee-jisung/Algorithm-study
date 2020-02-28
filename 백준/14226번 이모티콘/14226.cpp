#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>

#define SIZE 2002 
// 1001 이면 런타임 에러, 2002로 확장 해줘야 함
// 이모티콘, 클립보드 모두 s가 1000일때를 맞추기 위해 그전에 복사되는 경우 그 이상으로 넘어가기 때문
// 예를들어 이모티콘이 600개일때 클립보드 복사하면 그이상으로 넘어감
#define INF 987654321

using namespace std;

struct node {
	int emo;
	int clip;
	int cal;
};


int emoji, s, result;
// isVisit[이모티콘개수][클립보드 복사된 개수]를 각각 방문처리 해줌
bool isVisit[SIZE][SIZE];

int main(void) {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> s;

	queue<node> q;
	q.push({ 1, 0, 0 });
	isVisit[1][0] = true;

	while (!q.empty()) {

		int emo = q.front().emo;
		int clip = q.front().clip;
		int cal = q.front().cal;

		q.pop();

		if (emo == s) {
			result = cal;
			break;
		}

		for (int i = 0; i < 3; i++) {
			switch (i) {
			case 0: // 복사
				if (!isVisit[emo][emo]) { //복사한 적이 없으면 복사
					q.push({ emo, emo, cal + 1 });
					isVisit[emo][emo] = true;
				}
				break;
			case 1: // 붙여넣기 
				if (emo <= 1000 && clip > 0 && !isVisit[emo+clip][clip]) {
					q.push({ emo + clip, clip, cal + 1 });
					isVisit[emo + clip][clip] = true;
				}
				break;
			case 2: // 이모티콘 1개 삭제 
				if (emo >= 2 && !isVisit[emo-1][clip]) {
					q.push({ emo - 1, clip, cal + 1 });
					isVisit[emo - 1][clip] = true;
				}
			}
		}
		
	}

	cout << result << "\n";

	return 0;
}
