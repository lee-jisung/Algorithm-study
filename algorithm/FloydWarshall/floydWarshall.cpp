#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <map>

#define SIZE 100
#define INF 987654321

using namespace std;

/*
  모든 정점 -> 모든 정점으로의 최단 경로 --> 2차원 배열로 관리
  
  거쳐가는 노드를 중심으로 매번 계산 -> 노드z를 거치지 않는 경우들을 모두 아래의 식을 통해 비교하여 갱신

  (x에서 y로 가는 최소 비용) vs (x에서 노드 z로 가는 비용 + z에서 y로 가는 비용)

*/

int number = 4;
int d[SIZE][SIZE];//모든 정점으로 가는 최소 비용 저장

int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {

	for (int i = 0;i < number;i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// k = 거쳐가는 노드
	for (int k = 0; k < number; k++) {
		// i = 출발 노드
		for (int i = 0; i < number; i++) {
			 // j = 도착 노드
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

}


int main(void) {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	floydWarshall();

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number;j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
