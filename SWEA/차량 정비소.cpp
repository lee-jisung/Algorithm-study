/*
   고객 별 도착 시간, (접수 번호, 접수 처리 시간, 정비 번호, 정비 처리 시간, 서비스 종료 여부) struct
   접수, 정비 창구 -> 고객 번호 / 처리시간

   현 시각 time == 고객 도착 시간 인 고객이 있다면 접수 대기 큐에 고객 번호 push

   매 시간(time)마다
   접수 창구, 정비 창구에 있는 고객의 처리시간들 +1

   접수 창구가 낮은 순부터
	고객의 처리 시간 == 접수 처리 시간 이면 접수에서 정비 큐로 고객 넘기고 (이 때, 고객 접수 번호는 해당 접수 창구 번호로)
	접수 창구에서 고객 제거, 만약 접수 대기자가 잇다면 바로 다시 접수 창구로 push

   정비 창구가 낮은 순부터
	고객 처리 시간 == 정비 처리 시간 이면 고객 정비 창구 번호를 해당 번호로 해주고
	정비 창구에서 고객 제거, 서비스 종료 표시
	만약 정비 대기자가 잇으면 다시 정비 창구로 고객 push

   모든 고객이 서비스를 받았다면 종료

   -> 종료 후, A, B와 같은 정비, 접수 창구 번호를 가진 고객번호 합 출력
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Customer {
	int arriveTime;
	int reception_no;
	int reception_time;
	int repair_no;
	int repair_time;
	bool finish;
};

struct Reception {
	int custNo;
	int time;
};

struct Repair {
	int custNo;
	int time;
};

int TC, tc;
int N, M, K, A, B;
Customer customer[1001];
Reception reception[10];
Repair repair[10];

bool isEnd() {
	for (int i = 1; i <= K; i++)
		if (!customer[i].finish) return false;
	return true;
}

int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	while (TC--) {

		queue<int> reception_q, repair_q;
		int result = 0;

		cin >> N >> M >> K >> A >> B;

		for (int i = 1; i <= N; i++) {
			cin >> reception[i].time;
			reception[i].custNo = 0;
		}
		for (int i = 1; i <= M; i++) {
			cin >> repair[i].time;
			repair[i].custNo = 0;
		}
		for (int i = 1; i <= K; i++) {
			cin >> customer[i].arriveTime;
			customer[i].reception_no = 0;
			customer[i].reception_time = 0;
			customer[i].repair_no = 0;
			customer[i].repair_time = 0;
			customer[i].finish = false;
		}

		int time = 0;
		while (1) {
			if (isEnd()) break;
			// 도착시간이 해당되는 손님을 접수 대기줄로 push
			for (int i = 1;i <= K; i++) {
				if (time == customer[i].arriveTime) {
					reception_q.push(i);
				}
			}

			// 창구에 있는 손님마다 소요시간 +1 
			for (int i = 1; i <= N; i++) {
				customer[reception[i].custNo].reception_time++;
			}
			for (int i = 1; i <= M; i++) {
				customer[repair[i].custNo].repair_time++;
			}

			//접수 창구 처리
			for (int i = 1; i <= N; i++) {
				if (customer[reception[i].custNo].reception_time == reception[i].time) {
					customer[reception[i].custNo].reception_no = i;
					repair_q.push(reception[i].custNo);
					reception[i].custNo = 0;
				}

				if (!reception_q.empty()) {
					if (reception[i].custNo == 0) {
						reception[i].custNo = reception_q.front();
						reception_q.pop();
					}
				}
			}

			for (int i = 1; i <= M; i++) {
				if (customer[repair[i].custNo].repair_time == repair[i].time) {
					customer[repair[i].custNo].repair_no = i;
					customer[repair[i].custNo].finish = true;
					repair[i].custNo = 0;
				}

				if (!repair_q.empty()) {
					if (repair[i].custNo == 0) {
						repair[i].custNo = repair_q.front();
						repair_q.pop();
					}
				}
			}
			time++;
		}
		for (int i = 1; i <= K; i++)
			if (customer[i].reception_no == A && customer[i].repair_no == B)
				result += i;
		cout << "#" << ++tc << " ";
		if (result == 0) cout << -1 << "\n";
		else cout << result << "\n";
	}

	return 0;
}
