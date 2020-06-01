#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
   진실을 아는 사람 번호 관리 -> people
   진실을 아는 사람이 참석하는 파티 번호 관리 -> party

   진실을 아는사람을 우선 queue에 모두 push
    - 각 파티당 참석하는 사람 중 진실을 아는 사람이 있으면 party[no] 을 true로 바꿔줌
	- 각각의 사람이 가는 파티 번호 (peopleToParty)
	  & 각 파티에 참석하는 사람 번호 (people_list)를 vector에 따로 관리

   queue에 들어있는 진실을 아는 사람을 하나씩 꺼내보면서
    해당 사람이 참석하는 파티를 모두 true로 바꿔주고 
	해당 파티에 참석하는 사람들 중 진실을 모르는 사람을 큐에 넣음
   위의 작업을 반복 후 

   총 파티 수 - 진실을 아는 파티 수를 출력
*/

int n, m, t, cnt;
bool people[51], party[51];

vector<int> peopleToParty[51], people_list[51];
queue<int> q;

int main(void) {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	if (t >= 1) {
		while (t--) {
			int tmp; cin >> tmp;
			people[tmp] = true;
			q.push(tmp);
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> t;
		while (t--) {
			int tmp; cin >> tmp;
			peopleToParty[tmp].push_back(i);
			people_list[i].push_back(tmp);
			if (people[tmp]) party[i] = true;
		}
	}

	while (!q.empty()) {

		int p = q.front();
		q.pop();

		for (int i = 0; i < peopleToParty[p].size(); i++) {
			int pt = peopleToParty[p][i];
			if (!party[pt]) party[pt] = true;
			for (int j = 0; j < people_list[pt].size(); j++) {
				int no = people_list[pt][j];
				if (!people[no]) {
					people[no] = true;
					q.push({ no });
				}
			}
		}
	}

	for (int i = 1; i <= m; i++)
		if (party[i]) cnt++;
	cout << m - cnt << "\n";

	return 0;

}
